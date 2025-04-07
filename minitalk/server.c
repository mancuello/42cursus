/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:42:38 by mcuello           #+#    #+#             */
/*   Updated: 2025/04/07 18:21:40 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L
#include <unistd.h>
#include "ft_printf.h"
#include <signal.h>


static void handler_sig(int sig, siginfo_t *info, void *ucontext)
{
	static char	caracter = 0;
	static int bit = 0;
	
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
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction sa;

	sa.sa_sigaction = handler_sig;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	write(1, "Iniciando Server...\n", 20);
	sleep(2);
	ft_printf("\nSERVER   --ONLINE--\n");
	sleep(1);
	ft_printf("Información de PID => %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Esperando señales...\n");
	while (1)
		pause();
	return (0);
}
