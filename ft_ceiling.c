/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceiling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:12:22 by qbrillai          #+#    #+#             */
/*   Updated: 2021/07/15 14:19:14 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_ceiling2(t_game *game)
{
	game->x2 = 0;
	while (game->x2 < game->param.screenWidth)
	{
		game->cellX = (int)game->floorX;
		game->cellY = (int)game->floorY;
		game->tx = (int)(game->floorTexture.img_width
				* (game->floorX - game->cellX))
			& (game->floorTexture.img_width - 1);
		game->ty = (int)(game->floorTexture.img_height
				* (game->floorY - game->cellY))
			& (game->floorTexture.img_height - 1);
		game->floorX += game->floorStepX;
		game->floorY += game->floorStepY;
		game->color = 65536 * game->param.C[0] + 256
			* game->param.C[1] + game->param.C[2];
		game->display.data[game->y2 * game->param.screenWidth + game->x2]
			 = game->color;
		game->color = 65536 * game->param.F[0] + 256
			* game->param.F[1] + game->param.F[2];
		game->display.data[((game->param.screenHeight - game->y2 - 1)
				* game->param.screenWidth) + game->x2] = game->color;
		game->x2++;
	}
	return (1);
}

int	ft_ceiling1(t_game *game)
{
	game->y2 = 0;
	while (game->y2 < game->param.screenHeight)
	{	
		game->rayDirX0 = game->cam.dirX - game->cam.planeX;
		game->rayDirY0 = game->cam.dirY - game->cam.planeY;
		game->rayDirX1 = game->cam.dirX + game->cam.planeX;
		game->rayDirY1 = game->cam.dirY + game->cam.planeY;
		game->p = game->y2 - game->param.screenHeight / 2;
		game->posZ = 0.5 * game->param.screenHeight;
		game->rowDistance = game->posZ / game->p;
		game->floorStepX = game->rowDistance
			* (game->rayDirX1 - game->rayDirX0) / game->param.screenWidth;
		game->floorStepY = game->rowDistance
			* (game->rayDirY1 - game->rayDirY0) / game->param.screenWidth;
		game->floorX = game->cam.posX
			+ game->rowDistance * game->rayDirX0;
		game->floorY = game->cam.posY
			+ game->rowDistance * game->rayDirY0;
		ft_ceiling2(game);
		game->y2++;
	}
	return (1);
}
