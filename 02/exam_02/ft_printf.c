/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoarau <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:38:48 by rohoarau          #+#    #+#             */
/*   Updated: 2021/12/13 17:14:09 by rohoarau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_printchar(char c)
{
	return(write(1, &c, 1));
}

int	ft_printstr(char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count += write(1, &s[count], 1);
	return (count);
}

int	ft_printint(int d)
{
	char s;
	int	count = 0;
	if (d == 0)
		return (write(1, "0", 1));
	if (d < 0)
	{
		count += write(1, "-", 1);
		if (d == -2147483648)
			count += write (1, "2147483648", 10);
		d *= -1;
	}
	if (d > 0)
	{
		if (d > 9)
			count += ft_printint(d / 10);
		count += ft_printchar(d % 10 + 48);
	}
	return (count);
}
/*
int	ft_printhex(unsigned int d)
{
	char	s;
	int count = 0;

	if (d == 0)
		return (write(1, "0", 1));
	if (d > 0)
	{
		if (d > 15)
			count += ft_printint(d / 16);
		if (d % 16 < 10)
		{
			s = d % 16 + 48;
			count += write(1, &s, 1);
		}
		if (d % 16 >= 10 && d % 16 <= 15)
		{
			s = d % 16 + 87;
			count += write(1, &s, 1);
		}
	}
	return (count);
}*/

int	ft_printhex(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		count += write (1, "0", 1);
	if (nb > 0)
	{
		if (nb > 15)
			count += ft_printhex(nb / 16);
		if (nb % 16 < 10)
			count += ft_printchar(nb % 16 + 48);
		if (nb % 16 >= 10 && nb % 16 <= 15)
			count += ft_printchar(nb % 16 + 87);
	}
	return (count);
}


int	ft_print_params(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 's')
		count += ft_printstr(va_arg(ap, char *));
	if (c == 'd')
		count += ft_printint(va_arg(ap, int));
	if (c == 'x')
		count += ft_printhex(va_arg(ap, unsigned int));
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	int		i = 0;
	va_list ap;

	va_start(ap, s);
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] != '%')
		{
			count += write(1, &s[i], 1);
			i++;
		}
		if (s[i] == '%')
		{
			i++;
			count += ft_print_params(s[i], ap);
			i++;
		}
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	printf("%d\n", printf("  %s  %d  %x | ret=", "hello", 56, 6553));
	printf("%d\n", ft_printf("  %s  %d  %x | ret=", "hello", 56, 6553));
}
