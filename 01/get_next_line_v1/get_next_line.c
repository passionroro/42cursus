/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoarau <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:15:57 by rohoarau          #+#    #+#             */
/*   Updated: 2021/11/30 15:06:42 by rohoarau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*freeptr(char *ptr)
{
	free(ptr);
	return (NULL);
}

char	*copy_line(char *s, int *i)
{
	char		*line;
	int			j;
	static int	start = 0;

	line = NULL;
	j = *i;
	if (s[j] == '\0')
		line = ft_substr(s, start, (j - start));
	if (s[j] == '\n')
	{
		j++;
		*i += 1;
		line = ft_substr(s, start, (j - start));
	}
	if (start == j)
		return (freeptr(line));
	start = j;
	return (line);
}

char	*get_next_line(int fd)
{
	static int	i = -1;
	char		*line;
	static char	buff[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff, 0) < 0)
		return (NULL);
	if (i == -1)
	{
		read(fd, buff, 2147483647);
		i++;
	}
	while (buff[i] != '\n' && buff[i])
		i++;
	line = copy_line(buff, &i);
	return (line);
}
/*
int	main()
{
	int fd;
	int	nb;
	char	*line;

	fd = open("gnlTester/files/42_with_nl", O_RDONLY);
//	fd = open("files/empty", O_RDONLY);
//	fd = open("files/nl", O_RDONLY);
//	fd = open("files/5nl", O_RDONLY);
//	fd = open("files/bigfile", O_RDONLY);
//	fd = open("files/salut_nl", O_RDONLY);
//	fd = open("files/salut_no_nl", O_RDONLY);
	line = get_next_line(fd);
	nb = 1;
	while (line)
	{
		printf("line [%d]:	%s\n", nb, line);
		nb++;
		free(line);
		line = get_next_line(fd);
	}
	return 0;
}*/
