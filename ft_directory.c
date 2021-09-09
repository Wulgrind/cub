/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:32:10 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/09 10:38:31 by qbrillai         ###   ########.fr       */
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
		return (1);
}