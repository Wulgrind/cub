/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:10:25 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/07 11:37:52 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_freeparams3(t_game *game)
{
	int	i;

	i = 0;
	if (game->sprite)
	{
		while (i < game->param.sprite)
		{
			free (game->sprite[i]);
			i++;
		}
	}
	if (game->sprite)
		free (game->sprite);
	if (game->fd)
		close (game->fd);
	exit (0);
}

void	ft_freeparams2(t_game *game)
{
	int	i;

	i = 0;
	if (game->param.save)
		free (game->param.save);
	if (game->map)
	{
		while (i < game->param.row)
		{
			free (game->map[i]);
			i++;
		}
	}
	if (game->map)
		free (game->map);
	ft_freeparams3(game);
}

int	ft_freeparams(t_game *game)
{
	if (game->param.no)
		free (game->param.no);
	if (game->param.so)
		free (game->param.so);
	if (game->param.we)
		free (game->param.we);
	if (game->param.ea)
		free (game->param.ea);
	if (game->param.s)
		free (game->param.s);
	if (game->param.zbuffer)
		free (game->param.zbuffer);
	if (game->param.spriteorder)
		free (game->param.spriteorder);
	if (game->param.spritedistance)
		free (game->param.spritedistance);
	ft_freeparams2(game);
	return (1);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->move.forward = 1;
	else if (keycode == KEY_S)
		game->move.backward = 1;
	else if (keycode == KEY_LEFT)
		game->move.left = 1;
	else if (keycode == KEY_RIGHT)
		game->move.right = 1;
	else if (keycode == KEY_D)
		game->move.straferight = 1;
	else if (keycode == KEY_A)
		game->move.strafeleft = 1;
	else if (keycode == KEY_ESC)
	{
		ft_freeparams(game);
		exit (0);
	}
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->move.forward = 0;
	else if (keycode == KEY_S)
		game->move.backward = 0;
	else if (keycode == KEY_LEFT)
		game->move.left = 0;
	else if (keycode == KEY_RIGHT)
		game->move.right = 0;
	else if (keycode == KEY_D)
		game->move.straferight = 0;
	else if (keycode == KEY_A)
		game->move.strafeleft = 0;
	return (0);
}
