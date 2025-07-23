/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 22:02:36 by mcuello           #+#    #+#             */
/*   Updated: 2025/07/21 21:13:16 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					is_eating;
	int					meals_eating;
	int					last_meal;
	int					number_of_philosofers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					each_philo_must_eat;
	int					start_time;
	int					*is_dead;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*write_lock;
	pthread_mutex_t		*meal_lock;
	pthread_mutex_t		*dead_lock;
}	t_philo;

typedef struct s_program
{
	int					dead_flag;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		dead_lock;
	pthread_mutex_t		write_lock;
	t_philo				*philos;
}	t_program;

typedef struct s_args
{
	int					time_to_die;
	int					time_to_sleep;
	int					time_to_eat;
	int					number_of_philosofers;
	int					number_of_time_each_philo_must_eat;
}	t_args;

int		ft_atoi(const char *str);
int		run_philo(t_args args);
int		get_current_time(void);
void	init_threads(t_program *program);
void	*monitor_routine(void *philos_struct);
void	*routine(void *philos);
void	print_message(char *str, t_philo *philo, int id);
int		is_alive(t_philo *philo);
void	init_program(t_program *program, t_philo *philos);
void	init_philos(t_philo *philos, t_args args, t_program *program,
			pthread_mutex_t *forks);
void	init_forks(pthread_mutex_t *fork, int len);

#endif