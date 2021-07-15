/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chkOrder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:11:41 by qbrillai          #+#    #+#             */
/*   Updated: 2021/07/15 14:11:43 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_chkOrder(t_game *game)
{
	if (game->param.NO == NULL
		|| game->param.SO == NULL
		|| game->param.WE == NULL
		|| game->param.EA == NULL
		|| (game->param.F[0] == 0 && game->param.F[1] == 0
			&& game->param.F[2] == 0)
		|| (game->param.C[0] == 0 && game->param.C[1] == 0
			&& game->param.C[2] == 0))
		game->param.wrong++;
}
