/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:32:10 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/09 16:04:17 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_directory(char *map)
{
	int	ret;

	ret = open(map, O_DIRECTORY);
	if (ret < 0)
	{
		return (0);
	}
	else
	{
		close(map);
		return (1);
	}
}
