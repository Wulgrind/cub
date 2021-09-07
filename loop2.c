/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:13:19 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/07 11:48:04 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_loop6(t_game *game)
{
	game->y = game->drawstart;
	game->step = 1.0 * game->img.img_height / game->lineheight;
	game->texpos = (game->drawstart - game->param.screenheight
			/ 2 + game->lineheight / 2) * game->step;
	while (game->y < game->drawend)
	{
		game->texy = (int)game->texpos & (64 - 1);
		game->texpos += game->step;
		game->color = game->img.data[game->texy
			* 64 + game->texx];
		game->display.data[game->y * game->param.screenwidth
			+ game->x] = game->color;
		game->y++;
	}
	mlx_destroy_image(game->mlx, game->img.img);
	game->move.movespeed = 0.2;
	game->move.rotspeed = 0.2;
	return (1);
}
