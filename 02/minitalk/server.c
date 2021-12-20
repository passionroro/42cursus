/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoarau <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:26:21 by rohoarau          #+#    #+#             */
/*   Updated: 2021/12/20 20:18:43 by rohoarau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void signal_handler(int sig)
{
	static int	d;
	static int	bit;
	static char	c;

	if (sig == SIGUSR1)
		d += ft_recursive_power(2, bit);
	else if (sig == SIGUSR2)
		;
	bit++;
	if (bit == 8)
	{
		write (1, &d, 1);
		bit = 0;
		d = 0;
		c = 0;
	}
}

int	main()
{
	int pid;

	pid = getpid();
	printf("PID: %d\n", pid);
	while(1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		//pause();
	}
	return (0);
}
