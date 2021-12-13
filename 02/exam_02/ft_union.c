/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoarau <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:59:34 by rohoarau          #+#    #+#             */
/*   Updated: 2021/12/13 16:10:04 by rohoarau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	tab[256];

	if (argc == 3)
	{
		i = 0;
		j = 0;
		while (i < 256)
			tab[i++] = 0;
		i = 1;
		while (i < 3)
		{
			while (argv[i][j])
			{
				if (tab[(unsigned char)argv[i][j]] == 0)
				{
					write(1, &argv[i][j], 1);
					tab[(unsigned char)argv[i][j]] = 1;
				}
				j++;
			}
			j = 0;
			i++;
		}
	}
	return (0);
}
