/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 21:07:38 by mcuello           #+#    #+#             */
/*   Updated: 2025/07/21 21:13:11 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_program(t_program *program, t_philo *philos)
{
	program->philos = philos;
	program->dead_flag = 0;
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
}

static void	set_basics(t_philo *philos, t_args args, int i)
{
	philos[i].number_of_philosofers = args.number_of_philosofers;
	philos[i].time_to_die = args.time_to_die;
	philos[i].time_to_sleep = args.time_to_sleep;
	philos[i].each_philo_must_eat = args.number_of_time_each_philo_must_eat;
	philos[i].time_to_eat = args.time_to_eat;
}

void	init_philos(t_philo *philos, t_args args, t_program *program,
		pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < args.number_of_philosofers)
	{
		set_basics(philos, args, i);
		philos[i].id = i + 1;
		philos[i].is_eating = 0;
		philos[i].meals_eating = 0;
		philos[i].start_time = get_current_time();
		philos[i].last_meal = get_current_time();
		philos[i].is_dead = &program->dead_flag;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].write_lock = &program->write_lock;
		philos[i].left_fork = &forks[i];
		if (i + 1 == args.number_of_philosofers)
			philos[i].right_fork = &forks[0];
		else
			philos[i].right_fork = &forks[i + 1];
		i++;
	}
}

void	init_forks(pthread_mutex_t *fork, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
}
