/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoarau <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:10:20 by rohoarau          #+#    #+#             */
/*   Updated: 2021/12/13 16:37:32 by rohoarau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*keep_remaining(char *sline)
{
	int	 i = 0;
	int	j = 0;
	char	*ptr;

	while (sline[i] && sline[i] != '\n')
		i++;
	if (!sline[i])
	{
		free(sline);
		return (NULL);
	}
	ptr = malloc(sizeof(char) * (ft_strlen(sline) - i + 1));
	if (!ptr)
		return (NULL);
	i++;
	while (sline[i] && sline[i] != '\n')
	{
		ptr[j] = sline[i];
		i++;
		j++;
	}
	ptr[i] = '\0';
	free(sline);
	return (ptr);
}

char	*copy_lines(char *sline)
{
	char	*line;
	int	i;

	i = 0;
	if (!sline[i])
		return (NULL);
	while (sline[i] && sline[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (sline[i] && sline[i] != '\n')
	{
		line[i] = sline[i];
		i++;
	}
	if (sline[i] != '\n')
	{
		line[i] = sline[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_buffer(int fd, char *sline)
{
	int		ret;
	char	buff[BUFFER_SIZE + 1];

	ret = 1;
	while (ft_strchr(sline, '\n') != 1 && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		buff[ret] = '\0';
		sline = ft_strjoin(sline, buff);
	}
	return (sline);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*sline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	sline = read_buffer(fd, sline);
	if (!sline)
		return (NULL);
	line = copy_lines(sline);
	sline = keep_remaining(sline);
	return (line);
}

int	main()
{
	int	fd;
	int	nb;
	char	*line;

	nb = 1;
	fd = open("coucou", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("line[%d]:	|%s|\n", nb, line);
		nb++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
