/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tester.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:55:17 by qbrillai          #+#    #+#             */
/*   Updated: 2021/07/15 16:17:46 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_tester(t_game *game)
{
	game->fd = open(game->param.EA, O_RDONLY);
	if (game->fd == -1)
		return (0);
	close (game->fd);
	game->fd = open(game->param.WE, O_RDONLY);
	if (game->fd == -1)
		return (0);
	close (game->fd);
	game->fd = open(game->param.SO, O_RDONLY);
	if (game->fd == -1)
		return (0);
	close (game->fd);
	game->fd = open(game->param.NO, O_RDONLY);
	if (game->fd == -1)
		return (0);
	close (game->fd);
	return (1);
}
