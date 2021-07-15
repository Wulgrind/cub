/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:12:14 by qbrillai          #+#    #+#             */
/*   Updated: 2021/07/15 17:33:59 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_loop5(t_game *game)
{
	game->texNum = game->map[game->cam.mapX][game->cam.mapY] - 1;
	img_init(game);
	if (game->cam.side == 0)
	{
		game->wallX = game->cam.posY
		   			+ game->cam.perpWallDist * game->cam.rayDirY;
	}
	else
	{
		game->wallX = game->cam.posX
					+game->cam.perpWallDist * game->cam.rayDirX;
	}
	game->wallX -= floor((game->wallX));
	game->texX = (int)(game->wallX * (double)(game->img.img_width));
	if (game->cam.side == 0 && game->cam.rayDirX > 0)
		game->texX = game->img.img_width - game->texX - 1;
	if (game->cam.side == 1 && game->cam.rayDirY < 0)
		game->texX = game->img.img_width - game->texX - 1;
	ft_loop6(game);
	return (1);
}

int	ft_loop4(t_game *game)
{
	if (game->cam.side == 0)
	{
		game->cam.perpWallDist = (game->cam.mapX - game->cam.posX
					+ (1 - game->cam.stepX)  / 2) / game->cam.rayDirX;
	}
	else
	{
		game->cam.perpWallDist = (game->cam.mapY - game->cam.posY
					+ (1 - game->cam.stepY) / 2) / game->cam.rayDirY;
	}
	game->lineHeight = (int)(game->param.screenHeight / game->cam.perpWallDist);
	game->drawStart = -game->lineHeight / 2 + game->param.screenHeight / 2;
	if (game->drawStart < 0)
		game->drawStart = 0;
	game->drawEnd = game->lineHeight / 2 + game->param.screenHeight / 2;
	if (game->drawEnd >= game->param.screenHeight)
		game->drawEnd = game->param.screenHeight - 1;
	ft_loop5(game);
	return (1);
}

int	ft_loop3(t_game *game)
{
	while (game->cam.hit == 0)
	{
		if (game->cam.sideDistX < game->cam.sideDistY)
		{
			game->cam.sideDistX += game->cam.deltaDistX;
			game->cam.mapX += game->cam.stepX;
			game->cam.side = 0;
		}
		else
		{
			game->cam.sideDistY += game->cam.deltaDistY;
			game->cam.mapY += game->cam.stepY;
			game->cam.side = 1;
		}
		if (game->map[game->cam.mapX][game->cam.mapY] > 0)
			game->cam.hit = 1;
	}
	ft_loop4(game);
	return (1);
}

void	ft_loop2(t_game *game)
{
	if (game->cam.rayDirX < 0)
	{
		game->cam.stepX = -1;
		game->cam.sideDistX = (game->cam.posX - game->cam.mapX)
				* game->cam.deltaDistX;
	}
	else
	{
		game->cam.stepX = 1;
		game->cam.sideDistX = (game->cam.mapX + 1.0 - game->cam.posX)
				* game->cam.deltaDistX;
	}
	if (game->cam.rayDirY < 0)
	{
		game->cam.stepY = -1;
		game->cam.sideDistY = (game->cam.posY - game->cam.mapY)
				* game->cam.deltaDistY;
	}
	else
	{
		game->cam.stepY = 1;
		game->cam.sideDistY = (game->cam.mapY + 1.0 - game->cam.posY)
				* game->cam.deltaDistY;
	}
	ft_loop3(game);
}

int	ft_mainLoop(t_game *game)
{
	ft_ceiling1(game);
	game->x = 0;
	while (game->x++ < game->param.screenWidth)
	{
		game->cam.cameraX = 2 * game->x / (double)game->param.screenWidth - 1;
		game->cam.rayDirX = game->cam.dirX
				+ game->cam.planeX * game->cam.cameraX;
		game->cam.rayDirY = game->cam.dirY
				+ game->cam.planeY * game->cam.cameraX;
		game->cam.mapX = (int)game->cam.posX;
		game->cam.mapY = (int)game->cam.posY;
		game->cam.deltaDistX = sqrt(1 + (game->cam.rayDirY * game->cam.rayDirY)
						/ (game->cam.rayDirX * game->cam.rayDirX));
		game->cam.deltaDistY = sqrt(1 + (game->cam.rayDirX
						* game->cam.rayDirX)
					/ (game->cam.rayDirY * game->cam.rayDirY));
		game->cam.hit = 0;
		ft_loop2(game);
	}
	ft_mainloop2(game);
	return (1);
}
