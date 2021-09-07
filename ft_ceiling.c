/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceiling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:12:22 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/07 11:27:46 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_ceiling2(t_game *game)
{
	game->x2 = 0;
	while (game->x2 < game->param.screenwidth)
	{
		game->cellx = (int)game->floorx;
		game->celly = (int)game->floory;
		game->tx = (int)(game->floortexture.img_width
				* (game->floorx - game->cellx))
			& (game->floortexture.img_width - 1);
		game->ty = (int)(game->floortexture.img_height
				* (game->floory - game->celly))
			& (game->floortexture.img_height - 1);
		game->floorx += game->floorstepx;
		game->floory += game->floorstepy;
		game->color = 65536 * game->param.c[0] + 256
			* game->param.c[1] + game->param.c[2];
		game->display.data[game->y2 * game->param.screenwidth + game->x2]
			 = game->color;
		game->color = 65536 * game->param.f[0] + 256
			* game->param.f[1] + game->param.f[2];
		game->display.data[((game->param.screenheight - game->y2 - 1)
				* game->param.screenwidth) + game->x2] = game->color;
		game->x2++;
	}
	return (1);
}

int	ft_ceiling1(t_game *game)
{
	game->y2 = 0;
	while (game->y2 < game->param.screenheight)
	{	
		game->raydirx0 = game->cam.dirx - game->cam.planex;
		game->raydiry0 = game->cam.diry - game->cam.planey;
		game->raydirx1 = game->cam.dirx + game->cam.planex;
		game->raydiry1 = game->cam.diry + game->cam.planey;
		game->p = game->y2 - game->param.screenheight / 2;
		game->posz = 0.5 * game->param.screenheight;
		game->rowdistance = game->posz / game->p;
		game->floorstepx = game->rowdistance
			* (game->raydirx1 - game->raydirx0) / game->param.screenwidth;
		game->floorstepy = game->rowdistance
			* (game->raydiry1 - game->raydiry0) / game->param.screenwidth;
		game->floorx = game->cam.posx
			+ game->rowdistance * game->raydirx0;
		game->floory = game->cam.posy
			+ game->rowdistance * game->raydiry0;
		ft_ceiling2(game);
		game->y2++;
	}
	return (1);
}
