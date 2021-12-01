/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoarau <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:15:57 by rohoarau          #+#    #+#             */
/*   Updated: 2021/11/29 11:10:03 by rohoarau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*freeptr(char *ptr)
{
	free(ptr);
	return (NULL);
}

char	*copy_lines(char **sline, int *isempty)
{
	static int	i = 0;
	static int	start = 0;
	char		*line;
	char		*s;

	line = NULL;
	s = *sline;
	if (!s[i])
		return (freeptr(*sline));
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\0')
		line = ft_substr(s, start, (i - start));
	if (s[i] == '\n')
	{
		i++;
		*isempty += 1;
		line = ft_substr(s, start, (i - start));
	}
	start = i;
	return (line);
}

char	*read_buffer(char *sline, char *buff, int fd, int *isempty)
{
	int		ret;

	ret = 1;
	while (!ft_strchr(buff, '\n') && ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		*isempty += 1;
		if (ret == -1)
			return (freeptr(sline));
		buff[ret] = '\0';
		sline = ft_strjoin(sline, buff);
	}
	return (sline);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		buff[BUFFER_SIZE + 1];
	static char	*sline;
	static int	isempty;

	if (fd < 0 || BUFFER_SIZE <= 0 || isempty == 1 || read(fd, buff, 0) < 0)
		return (NULL);
	if (!sline)
		sline = ft_strdup("");
	sline = read_buffer(sline, buff, fd, &isempty);
	line = copy_lines(&sline, &isempty);
	return (line);
}
/*
int	main()
{
	int fd;
	int	nb;
	char	*line;

//	fd = open("gnlTester/files/41_no_nl", O_RDONLY);
  	//fd = open("gnlTester/files/41_with_nl", O_RDONLY);
    //fd = open("gnlTester/files/42_no_nl", O_RDONLY);
    //fd = open("gnlTester/files/42_with_nl", O_RDONLY);
    //fd = open("gnlTester/files/43_no_nl", O_RDONLY);
    fd = open("gnlTester/files/43_with_nl", O_RDONLY);
    //fd = open("gnlTester/files/alternate_line_nl_no_nl", O_RDONLY);
    //fd = open("gnlTester/files/alternate_line_nl_with_nl", O_RDONLY);
    //fd = open("gnlTester/files/big_line_no_nl", O_RDONLY);
   // fd = open("gnlTester/files/big_line_with_nl", O_RDONLY);
    //fd = open("gnlTester/files/empty", O_RDONLY);
    //fd = open("gnlTester/files/multiple_line_no_nl", O_RDONLY);
    //fd = open("gnlTester/files/multiple_line_with_nl", O_RDONLY);
    //fd = open("gnlTester/files/multiple_nlx5", O_RDONLY);
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
