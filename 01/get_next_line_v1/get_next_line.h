/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoarau <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:57:36 by rohoarau          #+#    #+#             */
/*   Updated: 2021/11/29 11:14:33 by rohoarau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>	//read
# include <stddef.h> //size_t
# include <stdlib.h>	//malloc, free

char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
typedef long unsigned int	t_size;
char	*ft_strchr(const char *s, int c);
t_size	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, t_size len);

#endif
