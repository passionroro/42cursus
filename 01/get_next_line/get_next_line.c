#include "get_next_line.h"

char	*copy_lines(char *sline)
{
	char	*line;
	int	i;

	i = 0;
//	if (!sline[i])
//		return (NULL);
	while (sline[i] || sline[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	printf("%d\n", i);
	if (!line)
		return (NULL);
	i = 0;
	while (sline[i] || sline[i] != '\n')
	{
		line[i] = sline[i];
		i++;
	}
	if (sline[i] == '\n')
	{
		line[i] = sline[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_buffer(int fd, char *sline)
{
	char	buff[BUFFER_SIZE + 1];
	int	ret;

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
	printf("sline:	|%s|\n", sline);
	if (!sline)
		return (NULL);
	line = copy_lines(sline);
	//printf("line coucou:	|%s|\n", line);
	//sline = keep_remaining(sline);
	//printf("sline:	|%s|\n", sline);
	return (line);
}

int	main()
{
	int	fd;
	int	nb;
	char	*line;

	fd = open("coucou", O_RDONLY);
	line = get_next_line(fd);
	nb = 1;
	while (nb < 5)
	{
		//printf("line[%d]:	|%s|\n", nb, line);
		free(line);
		nb++;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
