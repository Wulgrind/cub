/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:13:57 by qbrillai          #+#    #+#             */
/*   Updated: 2021/07/15 14:13:58 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	img_init(t_game *game)
{
	if (game->texNum == 0 )
	{
		if (game->cam.side == 1 && game->cam.stepY == -1)
			game->img.img = mlx_xpm_file_to_image(game->mlx, game->param.WE,
					&game->img.img_width, &game->img.img_height);
		if (game->cam.side == 1 && game->cam.stepY == 1)
			game->img.img = mlx_xpm_file_to_image(game->mlx,
					game->param.EA, &game->img.img_width,
					&game->img.img_height);
		if (game->cam.side == 0 && game->cam.stepX == -1)
			game->img.img = mlx_xpm_file_to_image(game->mlx, game->param.NO,
					&game->img.img_width, &game->img.img_height);
		if (game->cam.side == 0 && game->cam.stepX == 1)
			game->img.img = mlx_xpm_file_to_image(game->mlx, game->param.SO,
					&game->img.img_width, &game->img.img_height);
	}
	game->img.data = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
	return (1);
}

int	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->param.screenWidth,
			game->param.screenHeight, "mlx 42");
	game->display.img = mlx_new_image(game->mlx,
			game->param.screenWidth, game->param.screenHeight);
	game->display.data = (int *)mlx_get_data_addr(game->display.img,
			&game->display.bpp,
			&game->display.size_l, &game->display.endian);
	game->cam.time = 0;
	game->cam.oldtime = 0;
	game->move.forward = 0;
	game->move.backward = 0;
	game->move.right = 0;
	game->move.left = 0;
	game->move.strafeLeft = 0;
	game->move.strafeRight = 0;
	game->isDigit = 0;
	return (1);
}

void	ft_initParam(t_game *game)
{
	int	i;

	i = 0;
	game->param.S = 0;
	game->param.row = 0;
	game->param.NO = NULL;
	game->param.SO = NULL;
	game->param.WE = NULL;
	game->param.EA = NULL;
	game->param.save = NULL;
	game->param.wrong = 0;
	game->param.ZBuffer = NULL;
	game->param.spriteDistance = NULL;
	game->param.spriteOrder = NULL;
	game->sprite = NULL;
	game->map = NULL;
	game->param.screenHeight = 480;
	game->param.screenWidth = 680;
	while (i <= 2)
	{
		game->param.F[i] = 0;
		game->param.C[i] = 0;
		i++;
	}
	game->wrong2 = 0;
}
