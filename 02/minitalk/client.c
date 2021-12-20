/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoarau <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:14:28 by rohoarau          #+#    #+#             */
/*   Updated: 2021/12/20 20:15:39 by rohoarau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_itob(char *str, int pid)
{
	int	i;
	int	d;
	int	bit;

	i = 0;
	d = 0;
	while (str[i])
	{
		bit = 8;
		while (bit-- > 0)
		{
			if (1 << bit)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*ptr;
	int		i;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_itob(argv[2], pid);
	}
	return (0);
}
