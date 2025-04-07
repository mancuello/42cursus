/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:50:33 by mcuello           #+#    #+#             */
/*   Updated: 2025/04/07 14:34:27 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf.h"
#include <unistd.h>
#include "client.h"

static void	send_bits(int pid, unsigned char bit)
{
	if (bit & 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(450);
}

static void	send_newline_char(int pid)
{
	send_bits(pid, 0);
	send_bits(pid, 0);
	send_bits(pid, 0);
	send_bits(pid, 0);
	send_bits(pid, 1);
	send_bits(pid, 0);
	send_bits(pid, 1);
	send_bits(pid, 0);
}

static void	send_message(int pid, char *message)
{
	int	i;
	int	bit;

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
	send_newline_char(pid);
}

int	main(int argc, char **argv)
{
	int server_pid;
	char *message;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		message = argv[2];

		send_message(server_pid, message);
		return (0);	
	}
	else
	{
		ft_printf("Uso: <%s> <PID> <\"Cadena a Pasar\">", argv[0]);
		return (1);
	}
}
