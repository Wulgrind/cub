/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:25:05 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/13 11:27:54 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_checkend(char *map)
{
	int	i;
	
	i = 0;
	while (map[i])
		i++;
	i -= 4;
	if (map[i] == '.')
		i++;
	if (map[i] == 'c')
		i++;
	if (map[i] == 'u')
		i++;
	if (map[i] == 'b')
	{
		return (1);
	}
	write(1, "Error\nBad parameter extension", 30);
	return (0);
}
