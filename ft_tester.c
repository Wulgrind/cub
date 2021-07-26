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

int	ft_tester5(t_game *game)
{
	int	i;

	i = 0;
	while (game->param.SO[i])
		i++;
	if (game->param.SO[--i] != 'm')
		return (0);
	if (game->param.SO[--i] != 'p')
		return (0);
	if (game->param.SO[--i] != 'x')
		return (0);
	if (game->param.SO[--i] != '.')
		return (0);
	return (1);
}

int	ft_tester4(t_game *game)
{
	int	i;

	i = 0;
	while (game->param.NO[i])
		i++;
	if (game->param.NO[--i] != 'm')
		return (0);
	if (game->param.NO[--i] != 'p')
		return (0);
	if (game->param.NO[--i] != 'x')
		return (0);
	if (game->param.NO[--i] != '.')
		return (0);
	if (!(ft_tester5(game)))
		return (0);
	return (1);
}

int	ft_tester3(t_game *game)
{
	int	i;

	i = 0;
	while (game->param.WE[i])
		i++;
	if (game->param.WE[--i] != 'm')
		return (0);
	if (game->param.WE[--i] != 'p')
		return (0);
	if (game->param.WE[--i] != 'x')
		return (0);
	if (game->param.WE[--i] != '.')
		return (0);
	if (!(ft_tester4(game)))
		return (0);
	return (1);
}

int	ft_tester2(t_game *game)
{
	int	i;

	i = 0;
	while (game->param.EA[i])
		i++;
	if (game->param.EA[--i] != 'm')
		return (0);
	if (game->param.EA[--i] != 'p')
		return (0);
	if (game->param.EA[--i] != 'x')
		return (0);
	if (game->param.EA[--i] != '.')
		return (0);
	if (!(ft_tester3(game)))
		return (0);
	return (1);
}

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
	if (!(ft_tester2(game)))
		return (0);
	return (1);
}
