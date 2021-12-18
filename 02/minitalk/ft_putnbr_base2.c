/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoarau <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:36:53 by rohoarau          #+#    #+#             */
/*   Updated: 2021/12/16 14:49:50 by rohoarau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr_base2(int n)
{
	char	str;

	if (n == 0)
		write (1, "0110000", 7);
	if (n < 0)
	{
		write (1, "-", 1);
		if (n == -2147483648)
			write (1, "2147483648", 10);
		n *= -1;
	}
	if (n > 0)
	{
		if (n > 1)
			ft_putnbr_base2(n / 2);
		str = n % 2 + 48;
		write (1, &str, sizeof(str));
	}
}
/*
int	main()
{
	ft_putnbr_base2(97);
	return 0;
}*/
