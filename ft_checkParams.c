/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkParams.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:14:42 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/07 11:33:28 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_checkparams2(t_game *game)
{
	if (game->param.c[0] > 255 || game->param.c[1] > 255)
		return (0);
	if (game->param.c[2] > 255)
		return (0);
	if (game->param.f[0] > 255 || game->param.f[1] > 255)
		return (0);
	if (game->param.f[2] > 255)
		return (0);
	return (1);
}

int	ft_checkparams(t_game *game)
{
	int	i;

	i = 4;
	if (game->param.screenheight == 0 || game->param.screenwidth == 0)
		return (i);
	if (game->param.no == NULL || game->param.so == NULL)
		return (i);
	if (game->param.we == NULL || game->param.ea == NULL)
		return (i);
	if (game->param.f[0] == 0 && game->param.f[1] == 0
		&& game->param.f[2] == 0)
		return (i);
	if (game->param.c[0] == 0 && game->param.c[1] == 0
		&& game->param.c[2] == 0)
		return (i);
	if (!ft_checkparams2(game) || game->wrong3 > 0)
	{
		i = 3;
		return (i);
	}
	return (1);
}
