/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:06:51 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/13 13:09:44 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	ft_lastline2(t_game *game)
{
	int	row;

	row = 0;
	while (row < game->param.row)
	{
		if (game->map[row][0] == 0)
			return (0);
		row++;
	}
	return (1);
}

int	ft_lastline(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < game->param.row)
		row++;
	row--;
	while (game->map[row][col] != 10)
	{
		if (game->map[row][col] == 0)
			return (0);
		col++;
	}
	if (!ft_lastline2(game))
		return (0);
	return (1);
}
