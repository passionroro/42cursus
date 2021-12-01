/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoarau <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:57:17 by rohoarau          #+#    #+#             */
/*   Updated: 2021/11/19 14:45:08 by rohoarau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_size	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	t_size	i;
	t_size	j;

	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ptr == NULL)
		return (0);
	j = 0;
	while (s1[j])
	{
		ptr[i] = s1[j];
		j++;
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i] = s2[j];
		j++;
		i++;
	}
	ptr[i] = '\0';
	free((char *)s1);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = -1;
	str = (char *)s;
	while (str[++i])
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
	}
	if (c == 0)
		return (&str[i]);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, t_size len)
{
	char	*ptr;
	t_size	i;
	t_size	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (len + start > ft_strlen(s))
		ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			ptr[j] = s[i];
			j++;
		}
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	t_size	i;
	t_size	len;

	i = -1;
	len = ft_strlen(s1);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (0);
	while (++i < len)
		ptr[i] = s1[i];
	ptr[i] = '\0';
	return (ptr);
}
