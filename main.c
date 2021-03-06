/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:14:27 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/13 11:16:55 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	ft_initparam(&game);
	if (ac < 2)
	{
		write (1, "Error\nNo maps given", 20);
		return (1);
	}
	if (!ft_parsing(&game, av[1])
		|| (!ft_checksprite(&game)) || (!ft_spriteparam(&game)))
	{	
		ft_freeparams(&game);
		return (1);
	}
	window_init(&game);
	mlx_loop_hook(game.mlx, &ft_mainloop, &game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &key_release, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &ft_freeparams, &game);
	mlx_loop(game.mlx);
	return (0);
}
