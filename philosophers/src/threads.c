/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 21:11:18 by mcuello           #+#    #+#             */
/*   Updated: 2025/07/21 21:05:38 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	joinex(pthread_t monitor, t_program *program, int len)
{
	int	i;

	i = 0;
	pthread_join(monitor, NULL);
	while (i < len)
	{
		pthread_join(program->philos[i].thread, NULL);
		i++;
	}
}

void	init_threads(t_program *program)
{
	int			i;
	int			len;
	pthread_t	monitor;

	if (pthread_create(&monitor, NULL, monitor_routine,
			(void *)program->philos) != 0)
	{
		printf("==ERROR AL CREAR MONITOR==\n");
		return ;
	}
	len = program->philos->number_of_philosofers;
	i = 0;
	while (i < len)
	{
		if (pthread_create(&program->philos[i].thread, NULL, routine,
				(void *)&program->philos[i]) != 0)
		{
			printf("==ERROR AL CREAR HILOS==\n");
			return ;
		}
		i++;
	}
	joinex(monitor, program, len);
}
