/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mainLoop2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:11:52 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/07 10:51:26 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mainloop2(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->display.img, 0, 0);
	if (game->move.forward == 1 || game->move.backward == 1
		|| game->move.left == 1 || game->move.right == 1
		|| game->move.strafeleft == 1 || game->move.straferight == 1)
		ft_move1(game);
}
