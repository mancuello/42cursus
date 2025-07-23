/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 22:02:18 by mcuello           #+#    #+#             */
/*   Updated: 2025/07/13 20:59:38 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	valid_args(t_args args)
{
	if (args.number_of_philosofers == 0 || args.time_to_die == 0
		|| args.time_to_eat == 0 || args.time_to_sleep == 0)
		return (0);
	return (1);
}

static t_args	args_initializer(int argv, char **argc)
{
	t_args	args;

	args.number_of_philosofers = ft_atoi(argc[1]);
	args.time_to_die = ft_atoi(argc[2]);
	args.time_to_eat = ft_atoi(argc[3]);
	args.time_to_sleep = ft_atoi(argc[4]);
	args.number_of_time_each_philo_must_eat = 0;
	if (argv == 6)
		args.number_of_time_each_philo_must_eat = ft_atoi(argc[5]);
	return (args);
}

int	main(int argv, char **argc)
{
	t_args	args;

	if (argv == 5 || argv == 6)
	{
		args = args_initializer(argv, argc);
		if (!valid_args(args))
			return (-1);
		return (run_philo(args));
	}
	else
		return (printf("== Error == WRONG NUMBER OF ARGUMENTS.\n"));
}
