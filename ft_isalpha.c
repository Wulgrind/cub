/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:14:49 by qbrillai          #+#    #+#             */
/*   Updated: 2021/07/15 14:14:51 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z') || c == '/' || c == '.')
	{
		return (1);
	}
	return (0);
}
