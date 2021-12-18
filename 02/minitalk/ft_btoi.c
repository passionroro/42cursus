/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btoc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoarau <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:05:16 by rohoarau          #+#    #+#             */
/*   Updated: 2021/12/16 16:43:36 by rohoarau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_btoi(char *str)
{
	int	d;
	int	i;
		
	i = ft_strlen(str);
	while (str[i])
	{
		while (str[i] == '0')
			i--;
		d = ft_recursive_power(2, i);
		i--;
	}
	return ((char)d);
}
