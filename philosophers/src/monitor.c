/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 21:51:51 by mcuello           #+#    #+#             */
/*   Updated: 2025/07/21 20:31:40 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_all_ate(t_philo *philos)
{
	int	i;
	int	eaten;

	if (philos->each_philo_must_eat == 0)
		return (0);
	eaten = 0;
	i = 0;
	while (i < philos[0].number_of_philosofers)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eating >= philos[0].each_philo_must_eat)
			eaten++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (eaten == philos[0].number_of_philosofers)
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos[0].is_dead = 1;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (1);
	}
	return (0);
}

static int	is_dead(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].number_of_philosofers)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (get_current_time() - philos[i].last_meal >= philos[i].time_to_die
			&& philos[i].is_eating == 0)
		{
			pthread_mutex_unlock(philos[i].meal_lock);
			print_message("died", &philos[i], philos[i].id);
			pthread_mutex_lock(philos[i].dead_lock);
			*philos[i].is_dead = 1;
			pthread_mutex_unlock(philos[i].dead_lock);
			return (1);
		}
		else
		{
			pthread_mutex_unlock(philos[i].meal_lock);
		}
		i++;
	}
	return (0);
}
//el last-meal tiene que estar iguallado al start time en el primer caso
//ya que sino le restamos nada 

void	*monitor_routine(void *philos_struct)
{
	t_philo	*philos;

	philos = (t_philo *)philos_struct;
	while (1)
	{
		if (is_dead(philos) || is_all_ate(philos))
			break ;
	}
	printf("MONITOR IS FINISH\n");
	return (NULL);
}
