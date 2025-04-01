/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:50:33 by mcuello           #+#    #+#             */
/*   Updated: 2025/03/31 22:22:20 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "client.h"

static void	send_bits(int pid, unsigned char bit)
{
	if (bit & 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(200);
}

static void	send_message(int pid, char *message)
{
	int	i;
	static int	bit = 7;

	i = 0;
	while (message[i] != '\0')
	{
		bit = 7;
		while(bit >= 0)
		{
			send_bits(pid, (message[i] >> bit) & 1);
			bit--;
		}
		i++;
	}
	send_bits(pid, 0);
	send_bits(pid, 0);
	send_bits(pid, 0);
	send_bits(pid, 0);
	send_bits(pid, 1);
	send_bits(pid, 0);
	send_bits(pid, 1);
	send_bits(pid, 0);
}

int	main(int argc, char **argv)
{
	int server_pid;
	char *message;

	if (argc == 1)
	{
		printf("Uso: <%s> <PID> <\"Cadena a Pasar\">", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];

	send_message(server_pid, message);
	return (0);	
}
