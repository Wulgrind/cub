/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tester.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:55:17 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/07 11:42:13 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_tester5(t_game *game)
{
	int	i;

	i = 0;
	while (game->param.so[i])
		i++;
	if (game->param.so[--i] != 'm')
		return (0);
	if (game->param.so[--i] != 'p')
		return (0);
	if (game->param.so[--i] != 'x')
		return (0);
	if (game->param.so[--i] != '.')
		return (0);
	return (1);
}

int	ft_tester4(t_game *game)
{
	int	i;

	i = 0;
	while (game->param.no[i])
		i++;
	if (game->param.no[--i] != 'm')
		return (0);
	if (game->param.no[--i] != 'p')
		return (0);
	if (game->param.no[--i] != 'x')
		return (0);
	if (game->param.no[--i] != '.')
		return (0);
	if (!(ft_tester5(game)))
		return (0);
	return (1);
}

int	ft_tester3(t_game *game)
{
	int	i;

	i = 0;
	while (game->param.we[i])
		i++;
	if (game->param.we[--i] != 'm')
		return (0);
	if (game->param.we[--i] != 'p')
		return (0);
	if (game->param.we[--i] != 'x')
		return (0);
	if (game->param.we[--i] != '.')
		return (0);
	if (!(ft_tester4(game)))
		return (0);
	return (1);
}

int	ft_tester2(t_game *game)
{
	int	i;

	i = 0;
	while (game->param.ea[i])
		i++;
	if (game->param.ea[--i] != 'm')
		return (0);
	if (game->param.ea[--i] != 'p')
		return (0);
	if (game->param.ea[--i] != 'x')
		return (0);
	if (game->param.ea[--i] != '.')
		return (0);
	if (!(ft_tester3(game)))
		return (0);
	return (1);
}

int	ft_tester(t_game *game)
{
	game->fd = open(game->param.ea, O_RDONLY);
	if (game->fd == -1)
		return (0);
	close (game->fd);
	game->fd = open(game->param.we, O_RDONLY);
	if (game->fd == -1)
		return (0);
	close (game->fd);
	game->fd = open(game->param.so, O_RDONLY);
	if (game->fd == -1)
		return (0);
	close (game->fd);
	game->fd = open(game->param.no, O_RDONLY);
	if (game->fd == -1)
		return (0);
	close (game->fd);
	if (!(ft_tester2(game)))
		return (0);
	return (1);
}
