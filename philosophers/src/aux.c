/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:48:56 by mcuello           #+#    #+#             */
/*   Updated: 2025/07/21 20:34:26 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	print_message(char *str, t_philo *philo, int id)
{
	int	timestamp;

	pthread_mutex_lock(philo->write_lock);
	timestamp = get_current_time() - philo->start_time;
	if (is_alive(philo))
		printf("%i %i %s\n", timestamp, id, str);
	pthread_mutex_unlock(philo->write_lock);
}
