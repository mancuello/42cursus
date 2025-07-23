/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 22:21:30 by mcuello           #+#    #+#             */
/*   Updated: 2025/07/21 21:09:17 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_all_mutex(t_program *program, pthread_mutex_t *fork)
{
	int	i;

	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->write_lock);
	i = 0;
	while (i < program->philos->number_of_philosofers)
	{
		pthread_mutex_destroy(&fork[i]);
		i++;
	}
}

int	run_philo(t_args args)
{
	t_program		program;
	t_philo			*philos;
	pthread_mutex_t	*fork;

	philos = malloc(sizeof(t_philo) * args.number_of_philosofers);
	if (!philos)
		return (printf("==FALLO EN LA ASIGNACION DE MEMORIA==\n"), 0);
	fork = malloc(sizeof(pthread_mutex_t) * args.number_of_philosofers);
	if (!fork)
	{
		printf("==FALLO EN LA ASIGNACION DE MEMORIA==\n");
		return (free(philos), 0);
	}
	init_program(&program, philos);
	init_forks(fork, args.number_of_philosofers);
	init_philos(philos, args, &program, fork);
	init_threads(&program);
	destroy_all_mutex(&program, fork);
	free(philos);
	free(fork);
	printf("== finishing all good ==\n");
	return (0);
}
