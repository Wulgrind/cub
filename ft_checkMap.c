/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkMap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:13:40 by qbrillai          #+#    #+#             */
/*   Updated: 2021/07/15 16:52:39 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_checkMap4(t_game *game, char *line)
{
	if (line[0] == 'F' || line[0] == 'C')
	{
		if (line[1] != ' ')
			game->wrong2++;
	}
	else
	{
		if (line[2] != ' ')
			game->wrong2++;
	}
	game->countp++;
	return (1);
}

int	ft_checkMap3(t_game *game)
{
	int	row;
	int	col;

	row = 1;
	col = 0;
	while (row < game->param.row - 1)
	{
		if (game->map[row][0] != 1 && game->map[row][0]
						!= 9 && game->map[row][0] != 0)
			return (0);
		while (game->map[row][col] != 10)
		{
			col++;
		}
		col--;
		if (game->map[row][col] != 1 && game->map[row][col]
						!= 9 && game->map[row][0] != 0)
			return (0);
		col = 0;
		row++;
	}
	return (1);
}

int	ft_checkMap2(t_game *game)
{
	int	row;
	int	col;

	row = 1;
	col = 0;
	while (game->map[0][col] != 10)
	{
		if (game->map[0][col] != 1 && game->map[0][col] != 9)
			return (0);
		col++;
	}
	col = 0;
	while (row < game->param.row)
		row++;
	row--;
	while (game->map[row][col] != 10)
	{
		if (game->map[row][col] != 1 && game->map[row][col] != 9)
			return (0);
		col++;
	}
	return (1);
}

int	ft_checkMapbis(t_game *game, int row, int col)
{
	if (game->map[row][col + 1] == 9)
		return (0);
	if (col != 0)
	{
		if (game->map[row][col - 1] == 9)
			return (0);
	}
	if (row != 0)
	{
		if (game->map[row - 1][col] == 9)
			return (0);
	}
	if (row != game->param.row - 1)
	{
		if (game->map[row + 1][col] == 9)
			return (0);
	}
	return (1);
}

int	ft_checkMap(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->param.row)
	{
		col = 0;
		while (game->map[row][col] != 10)
		{	
			if (game->map[row][col] == 0)
			{
				if (!(ft_checkMapbis(game, row, col)))
					return (0);
			}
			col++;
		}
		row++;
	}
	if (game->wrong2 > 0)
		return (0);
	return (1);
}
