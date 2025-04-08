/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:50:33 by mcuello           #+#    #+#             */
/*   Updated: 2025/04/08 16:46:07 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L
#include <signal.h>
#include "ft_printf.h"
#include <unistd.h>
#include "client.h"

volatile sig_atomic_t	g_ack_received = 0;

static void	send_bits(int pid, unsigned char bit)
{
	g_ack_received = 0;
	if (bit & 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	while (!g_ack_received)
		sleep(1);
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

static void	handler_sig(int signal)
{
	(void)signal;
	g_ack_received = 1;
}

static void	send_message(int pid, char *message)
{
	int	i;
	int	bit;

	i = 0;
	while (message[i] != '\0')
	{
		bit = 7;
		while (bit >= 0)
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
	int					server_pid;
	struct sigaction	sa;

	sa.sa_handler = handler_sig;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		send_message(server_pid, argv[2]);
		return (0);
	}
	else
	{
		ft_printf("Uso: <%s> <PID> <\"Cadena a Pasar\">", argv[0]);
		return (1);
	}
}
