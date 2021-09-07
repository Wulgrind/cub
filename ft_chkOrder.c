/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chkOrder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:11:41 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/07 10:54:40 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_chkorder(t_game *game)
{
	if (game->param.no == NULL
		|| game->param.so == NULL
		|| game->param.we == NULL
		|| game->param.ea == NULL
		|| (game->param.f[0] == 0 && game->param.f[1] == 0
			&& game->param.f[2] == 0)
		|| (game->param.f[0] == 0 && game->param.f[1] == 0
			&& game->param.f[2] == 0))
		game->param.wrong++;
}
