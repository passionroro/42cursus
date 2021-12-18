/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoarau <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:48:42 by rohoarau          #+#    #+#             */
/*   Updated: 2021/12/16 16:45:27 by rohoarau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/*
char	*str;

void	signal_handler1(int sig)
{

}

void	signal_handler2(int sig)
{

}*/

int	main(int argc, char **argv)
{
	char	*ptr;
	int		i = 0;
	char	d;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			ptr = ft_itob((int)argv[1][i]);
			if (!ptr)
				return (0);
			//printf("%s\n", ptr);
			d = printf("%c\n", ft_btoi(ptr));
			free(ptr);
			i++;
		}
	}
	return (0);
}
