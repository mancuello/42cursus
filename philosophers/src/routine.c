/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 21:52:41 by mcuello           #+#    #+#             */
/*   Updated: 2025/07/21 20:31:13 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	think(t_philo *philo)
{
	print_message("is thinking", philo, philo->id);
}

static void	get_sleep(t_philo *philo)
{
	print_message("is slepping", philo, philo->id);
	usleep((philo->time_to_sleep) * 1000);
}

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_message("has taken a fork", philo, philo->id);
	if (philo->number_of_philosofers == 1)
	{
		usleep((philo->time_to_die) * 1000);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	print_message("has taken a fork", philo, philo->id);
	philo->is_eating = 1;
	print_message("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eating++;
	pthread_mutex_unlock(philo->meal_lock);
	usleep((philo->time_to_eat) * 1000);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

int	is_alive(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->is_dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 0);
	pthread_mutex_unlock(philo->dead_lock);
	return (1);
}

void	*routine(void *philos_struct)
{
	t_philo		*philos;

	philos = (t_philo *)philos_struct;
	if (philos->id % 2 == 0)
		usleep(1000);
	while (is_alive(philos))
	{
		eat(philos);
		get_sleep(philos);
		think(philos);
	}
	printf("THREAD %i HA FINALIZADO ==\n", philos->id);
	return (NULL);
}
