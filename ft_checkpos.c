/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkpos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:15:54 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/07 11:36:20 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_checkdir2(int num, t_game *game)
{
	if (num == 5)
	{
		game->cam.dirx = 0;
		game->cam.diry = -1;
		game->cam.planex = -0.66;
		game->cam.planey = 0;
		game->cam.posy -= -1 * 0.50;
		game->cam.posx -= -1 * 0.50;
	}
	if (num == 6)
	{
		game->cam.dirx = 0;
		game->cam.diry = 1;
		game->cam.planex = 0.66;
		game->cam.planey = 0;
		game->cam.posx -= -1 * 0.50;
		game->cam.posy -= -1 * 0.50;
	}
}

void	ft_checkdir(int num, t_game *game)
{
	if (num == 3)
	{
		game->cam.dirx = -1;
		game->cam.diry = 0;
		game->cam.planex = 0;
		game->cam.planey = 0.66;
		game->cam.posx -= -1 * 0.50;
		game->cam.posy -= -1 * 0.50;
	}
	if (num == 4)
	{
		game->cam.dirx = 1;
		game->cam.diry = 0;
		game->cam.planex = 0;
		game->cam.planey = -0.66;
		game->cam.posx -= -1 * 0.50;
		game->cam.posy -= -1 * 0.50;
	}
	ft_checkdir2(num, game);
}

int	ft_checkst(t_game *game)
{
	int	row;
	int	col;
	int	check;

	row = 0;
	check = 0;
	while (row < game->param.row)
	{
		col = 0;
		while (game->map[row][col] != 10)
		{
			if (game->map[row][col] == 3 || game->map[row][col] == 4 ||
				game->map[row][col] == 5 || game->map[row][col] == 6)
			{
				check++;
				game->map[row][col] = 0;
			}
			col++;
		}
		row++;
	}
	if (check != 1)
		return (0);
	return (1);
}

int	ft_checkpos(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->param.row)
	{
		col = 0;
		while (game->map[row][col] != 10)
		{
			if (game->map[row][col] == 3 || game->map[row][col] == 4 ||
				game->map[row][col] == 5 || game->map[row][col] == 6)
			{
				game->cam.posx = row;
				game->cam.posy = col;
				ft_checkdir(game->map[row][col], game);
			}	
			col++;
		}
		row++;
	}
	if (!ft_checkst(game) || game->param.wrong > 0)
		return (0);
	return (1);
}
