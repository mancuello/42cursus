/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:42:38 by mcuello           #+#    #+#             */
/*   Updated: 2025/03/31 21:39:03 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

static char	caracter = 0;
static int bit = 0;

static void handler_sig(int sig)
{
	caracter <<= 1;
	if (sig == SIGUSR1)
	{
		caracter |= 1;
	}
	bit++;
	if (bit == 8)
	{
		write(1, &caracter, 1);
		bit = 0;
		caracter = 0;
	}
}

int	main(void)
{

	write(1, "Iniciando Server...\n", 20);
	sleep(2);
	printf("\nSERVER   --ONLINE--\n");
	sleep(1);
	printf("Información de PID => %d\n", getpid());
	signal(SIGUSR1, handler_sig);
	signal(SIGUSR2, handler_sig);
	printf("Esperando señales...\n");
	while (1)
		pause();
	return (0);
}
