/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:14:58 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/07 14:13:59 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move4(t_game *game)
{
	if (game->move.straferight == 1)
	{
		if (game->map[(int)(game->cam.posx + game->cam.planex
				* game->move.movespeed)][(int)(game->cam.posy)] == 0)
			game->cam.posx += game->cam.planex * game->move.movespeed;
		if (game->map[(int)(game->cam.posx)][(int)(game->cam.posy
				+ game->cam.planey * game->move.movespeed)] == 0)
			game->cam.posy += game->cam.planey * game->move.movespeed;
	}
	if (game->move.strafeleft == 1)
	{
		if (game->map[(int)(game->cam.posx - game->cam.planex
				* game->move.movespeed)][(int)(game->cam.posy)] == 0)
			game->cam.posx -= game->cam.planex * game->move.movespeed;
		if (game->map[(int)(game->cam.posx)][(int)(game->cam.posy
				- game->cam.planey * game->move.movespeed)] == 0)
			game->cam.posy -= game->cam.planey * game->move.movespeed;
	}
}
