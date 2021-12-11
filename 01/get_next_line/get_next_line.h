#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int	ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);

#endif
