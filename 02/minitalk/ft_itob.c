/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoarau <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:41:06 by rohoarau          #+#    #+#             */
/*   Updated: 2021/12/16 16:16:43 by rohoarau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	len(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
		return (11);
	if (nb <= 0)
	{
		len++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 2;
		len++;
	}
	return (len);
}

char	*ft_itoa_base2(int n)
{
	char	*ptr;
	int		i;
	long	nb;

	nb = n;
	i = len(nb);
	ptr = malloc(sizeof(char) * (len(nb) + 1));
	if (!ptr)
		return (0);
	if (nb == 0)
		ptr[0] = '0';
	if (nb < 0)
	{
		ptr[0] = '-';
		nb *= -1;
	}
	ptr[i] = '\0';
	while (nb > 0)
	{
		i--;
		ptr[i] = nb % 2 + 48;
		nb /= 2;
	}
	return (ptr);
}
