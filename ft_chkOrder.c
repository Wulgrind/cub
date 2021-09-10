/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chkOrder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:11:41 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/10 18:01:23 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_chkorder(t_game *game)
{
	if (game->param.no == NULL
		|| game->param.so == NULL
		|| game->param.we == NULL
		|| game->param.ea == NULL)
		game->param.wrong++;
}
