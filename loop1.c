/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:12:14 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/07 11:18:25 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_loop5(t_game *game)
{
	game->texnum = game->map[game->cam.mapx][game->cam.mapy] - 1;
	img_init(game);
	if (game->cam.side == 0)
	{
		game->wallx = game->cam.posy
			+ game->cam.perpwalldist * game->cam.raydiry;
	}
	else
	{
		game->wallx = game->cam.posx
			+ game->cam.perpwalldist * game->cam.raydirx;
	}
	game->wallx -= floor((game->wallx));
	game->texx = (int)(game->wallx * (double)(64));
	if (game->cam.side == 0 && game->cam.raydirx > 0)
		game->texx = 64 - game->texx - 1;
	if (game->cam.side == 1 && game->cam.raydiry < 0)
		game->texx = 64 - game->texx - 1;
	ft_loop6(game);
	return (1);
}

int	ft_loop4(t_game *game)
{
	if (game->cam.side == 0)
	{
		game->cam.perpwalldist = (game->cam.mapx - game->cam.posx
				+ (1 - game->cam.stepx) / 2) / game->cam.raydirx;
	}
	else
	{
		game->cam.perpwalldist = (game->cam.mapy - game->cam.posy
				+ (1 - game->cam.stepy) / 2) / game->cam.raydiry;
	}
	game->lineheight = (int)(game->param.screenheight / game->cam.perpwalldist);
	game->drawstart = -game->lineheight / 2 + game->param.screenheight / 2;
	if (game->drawstart < 0)
		game->drawstart = 0;
	game->drawend = game->lineheight / 2 + game->param.screenheight / 2;
	if (game->drawend >= game->param.screenheight)
		game->drawend = game->param.screenheight - 1;
	ft_loop5(game);
	return (1);
}

int	ft_loop3(t_game *game)
{
	while (game->cam.hit == 0)
	{
		if (game->cam.sidedistx < game->cam.sidedisty)
		{
			game->cam.sidedistx += game->cam.deltadistx;
			game->cam.mapx += game->cam.stepx;
			game->cam.side = 0;
		}
		else
		{
			game->cam.sidedisty += game->cam.deltadisty;
			game->cam.mapy += game->cam.stepy;
			game->cam.side = 1;
		}
		if (game->map[game->cam.mapx][game->cam.mapy] > 0)
			game->cam.hit = 1;
	}
	ft_loop4(game);
	return (1);
}

void	ft_loop2(t_game *game)
{
	if (game->cam.raydirx < 0)
	{
		game->cam.stepx = -1;
		game->cam.sidedistx = (game->cam.posx - game->cam.mapx)
			* game->cam.deltadistx;
	}
	else
	{
		game->cam.stepx = 1;
		game->cam.sidedistx = (game->cam.mapx + 1.0 - game->cam.posx)
			* game->cam.deltadistx;
	}
	if (game->cam.raydiry < 0)
	{
		game->cam.stepy = -1;
		game->cam.sidedisty = (game->cam.posy - game->cam.mapy)
			* game->cam.deltadisty;
	}
	else
	{
		game->cam.stepy = 1;
		game->cam.sidedisty = (game->cam.mapy + 1.0 - game->cam.posy)
			* game->cam.deltadisty;
	}
	ft_loop3(game);
}

int	ft_mainloop(t_game *game)
{
	ft_ceiling1(game);
	game->x = 0;
	while (game->x < game->param.screenwidth)
	{
		game->cam.camerax = 2 * game->x / (double)game->param.screenwidth - 1;
		game->cam.raydirx = game->cam.dirx
			+ game->cam.planex * game->cam.camerax;
		game->cam.raydiry = game->cam.diry
			+ game->cam.planey * game->cam.camerax;
		game->cam.mapx = (int)game->cam.posx;
		game->cam.mapy = (int)game->cam.posy;
		game->cam.deltadistx = sqrt(1 + (game->cam.raydiry * game->cam.raydiry)
				/ (game->cam.raydirx * game->cam.raydirx));
		game->cam.deltadisty = sqrt(1 + (game->cam.raydirx
					* game->cam.raydirx)
				/ (game->cam.raydiry * game->cam.raydiry));
		game->cam.hit = 0;
		ft_loop2(game);
		game->x++;
	}
	ft_mainloop2(game);
	return (1);
}
