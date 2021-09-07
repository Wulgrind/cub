/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:14:04 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/07 14:20:05 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_move3(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->param.screenheight)
	{
		x = 0;
		while (x < game->param.screenwidth)
		{
			game->display.data[y * game->param.screenwidth + x] = 0;
			x++;
		}
		y++;
	}
	ft_move4(game);
	return (1);
}

void	ft_movebis(t_game *game)
{
	game->move.olddirx = game->cam.dirx;
	game->cam.dirx = game->cam.dirx * cos(game->move.rotspeed)
		- game->cam.diry * sin(game->move.rotspeed);
	game->cam.diry = game->move.olddirx * sin(game->move.rotspeed)
		+ game->cam.diry * cos(game->move.rotspeed);
	game->move.oldplanex = game->cam.planex;
	game->cam.planex = game->cam.planex * cos(game->move.rotspeed)
		- game->cam.planey * sin(game->move.rotspeed);
	game->cam.planey = game->move.oldplanex * sin(game->move.rotspeed)
		+ game->cam.planey * cos(game->move.rotspeed);
}

int	ft_move2(t_game *game)
{
	if (game->move.right == 1)
	{
		game->move.olddirx = game->cam.dirx;
		game->cam.dirx = game->cam.dirx * cos(-game->move.rotspeed)
			- game->cam.diry * sin(-game->move.rotspeed);
		game->cam.diry = game->move.olddirx * sin(-game->move.rotspeed)
			+ game->cam.diry * cos(-game->move.rotspeed);
		game->move.oldplanex = game->cam.planex;
		game->cam.planex = game->cam.planex * cos(-game->move.rotspeed)
			- game->cam.planey * sin(-game->move.rotspeed);
		game->cam.planey = game->move.oldplanex * sin(-game->move.rotspeed)
			+ game->cam.planey * cos(-game->move.rotspeed);
	}
	if (game->move.left == 1)
	{
		ft_movebis(game);
	}
	ft_move3(game);
	return (1);
}

int	ft_move1(t_game *game)
{
	if (game->move.forward == 1)
	{
		if (game->map[(int)(game->cam.posx + game->cam.dirx
				* game->move.movespeed)][(int)(game->cam.posy)] == 0)
			game->cam.posx += game->cam.dirx * game->move.movespeed;
		if (game->map[(int)(game->cam.posx)][(int)(game->cam.posy
				+ game->cam.diry * game->move.movespeed)] == 0)
			game->cam.posy += game->cam.diry * game->move.movespeed;
	}
	if (game->move.backward == 1)
	{
		if (game->map[(int)(game->cam.posx - game->cam.dirx
				* game->move.movespeed)][(int)(game->cam.posy)] == 0)
			game->cam.posx -= game->cam.dirx * game->move.movespeed;
		if (game->map[(int)(game->cam.posx)][(int)(game->cam.posy
				- game->cam.diry * game->move.movespeed)] == 0)
			game->cam.posy -= game->cam.diry * game->move.movespeed;
	}
	ft_move2(game);
	return (1);
}
