/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:13:57 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/13 11:21:13 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	img_init(t_game *game)
{
	if (game->texnum == 0 )
	{
		if (game->cam.side == 1 && game->cam.stepy == -1)
			game->img.img = mlx_xpm_file_to_image(game->mlx, game->param.we,
					&game->img.img_width, &game->img.img_height);
		if (game->cam.side == 1 && game->cam.stepy == 1)
			game->img.img = mlx_xpm_file_to_image(game->mlx,
					game->param.ea, &game->img.img_width,
					&game->img.img_height);
		if (game->cam.side == 0 && game->cam.stepx == -1)
			game->img.img = mlx_xpm_file_to_image(game->mlx, game->param.no,
					&game->img.img_width, &game->img.img_height);
		if (game->cam.side == 0 && game->cam.stepx == 1)
			game->img.img = mlx_xpm_file_to_image(game->mlx, game->param.so,
					&game->img.img_width, &game->img.img_height);
	}
	game->img.data = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
	return (1);
}

int	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->param.screenwidth,
			game->param.screenheight, "mlx 42");
	game->display.img = mlx_new_image(game->mlx,
			game->param.screenwidth, game->param.screenheight);
	game->display.data = (int *)mlx_get_data_addr(game->display.img,
			&game->display.bpp,
			&game->display.size_l, &game->display.endian);
	game->cam.time = 0;
	game->cam.oldtime = 0;
	game->move.forward = 0;
	game->move.backward = 0;
	game->move.right = 0;
	game->move.left = 0;
	game->move.strafeleft = 0;
	game->move.straferight = 0;
	game->isdigit = 0;
	return (1);
}

void	ft_initparam2(t_game *game)
{
	int	i;

	i = 0;
	while (i <= 2)
	{
		game->param.f[i] = 0;
		game->param.c[i] = 0;
		i++;
	}
	game->wrong2 = 0;
	game->checkfc = 0;
}

void	ft_initparam(t_game *game)
{
	game->param.s = 0;
	game->param.row = 0;
	game->param.no = NULL;
	game->param.so = NULL;
	game->param.we = NULL;
	game->param.ea = NULL;
	game->param.save = NULL;
	game->param.wrong = 0;
	game->param.zbuffer = NULL;
	game->param.spritedistance = NULL;
	game->param.spriteorder = NULL;
	game->sprite = NULL;
	game->map = NULL;
	game->param.screenheight = 360;
	game->param.screenwidth = 480;
	ft_initparam2(game);
}
