/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paramsprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:16:06 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/07 11:32:23 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_spriteparam(t_game *game)
{
	game->param.zbuffer = malloc(sizeof(double) * game->param.screenwidth);
	game->param.spriteorder = malloc(sizeof(int) * game->param.sprite);
	game->param.spritedistance = malloc(sizeof(double) * game->param.sprite);
	return (1);
}
