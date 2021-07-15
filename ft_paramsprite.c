/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paramsprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:16:06 by qbrillai          #+#    #+#             */
/*   Updated: 2021/07/15 14:16:08 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_spriteparam(t_game *game)
{
	game->param.ZBuffer = malloc(sizeof(double) * game->param.screenWidth);
	game->param.spriteOrder = malloc(sizeof(int) * game->param.sprite);
	game->param.spriteDistance = malloc(sizeof(double) * game->param.sprite);
	return (1);
}
