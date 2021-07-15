/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkParams.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:14:42 by qbrillai          #+#    #+#             */
/*   Updated: 2021/07/15 14:14:44 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_checkParams2(t_game *game)
{
	if (game->param.C[0] > 255 || game->param.C[1] > 255)
		return (0);
	if (game->param.C[2] > 255)
		return (0);
	if (game->param.F[0] > 255 || game->param.F[1] > 255)
		return (0);
	if (game->param.F[2] > 255)
		return (0);
	return (1);
}

int	ft_checkParams(t_game *game)
{
	int	i;

	i = 4;
	if (game->param.screenHeight == 0 || game->param.screenWidth == 0)
		return (i);
	if (game->param.NO == NULL || game->param.SO == NULL)
		return (i);
	if (game->param.WE == NULL || game->param.EA == NULL)
		return (i);
	if (game->param.F[0] == 0 && game->param.F[1] == 0
		&& game->param.F[2] == 0)
		return (i);
	if (game->param.C[0] == 0 && game->param.C[1] == 0
		&& game->param.C[2] == 0)
		return (i);
	if (!ft_checkParams2(game) || game->wrong3 > 0)
	{
		i = 3;
		return (i);
	}
	return (1);
}
