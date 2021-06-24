/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:42:58 by qbrillai          #+#    #+#             */
/*   Updated: 2021/02/15 18:43:03 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1

# include <stdlib.h>
# include <unistd.h>
# include "../cub3d.h"

int		get_next_line(int fd, char **line);
char	*ft_cpy(char const *s1, char const *s2);
int		ft_check(char *save);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_newline(char *str);
char	*ft_newsave(char *save);

#endif
