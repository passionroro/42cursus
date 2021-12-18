#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

//int		ft_atoi(const char *str);
char	*ft_itob(int n);
void	ft_putnbr_base2(int n);
int		ft_recursive_power(int nb, int power);
int		ft_btoi(char *str);
size_t	ft_strlen(char *s);

#endif
