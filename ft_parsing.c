/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:14:18 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/07 11:18:59 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_checkend(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i -= 4;
	if (map[i] == '.')
		i++;
	if (map[i] == 'c')
		i++;
	if (map[i] == 'u')
		i++;
	if (map[i] == 'b')
	{
		return (1);
	}
	write(1, "Error\nBad parameter extension", 30);
	return (0);
}

int	ft_parseline(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O')
		ft_parseno(game, line);
	if (line[i] == 'S' && line[i + 1] == 'O')
		ft_parseso(game, line);
	if (line[i] == 'W' && line[i + 1] == 'E')
		ft_parsewe(game, line);
	if (line[i] == 'E' && line[i + 1] == 'A')
		ft_parseea(game, line);
	if (line[i] == 'F')
		ft_parsef(game, line);
	if (line[i] == 'C')
		ft_parsec(game, line);
	if (ft_isdigit(line[i]))
	{
		ft_parsemap(game, line);
		game->isdigit = 1;
	}
	if (!(ft_isdigit(line[i])) && game->isdigit == 1)
		game->param.wrong++;
	return (1);
}

int	ft_parsing2(t_game *game)
{
	int	i;

	i = 0;
	i = ft_checkparams(game);
	if (i == 4 || i == 3 || game->countp > 6)
	{
		if (i == 4)
			write (1, "Error\nLacking parameters in the .cub file", 42);
		if (i == 3)
			write (1, "Error\nIncorrect parameters", 26);
		if (game->countp > 6)
			write (1, "Error\nMore parameters than expected", 35);
		return (0);
	}
	if (!ft_checkmap(game) || !ft_checkmap2(game) || !ft_checkmap3(game))
	{
		write(1, "Error\nInvalid map", 18);
		return (0);
	}
	if (!ft_checkpos(game) || !ft_tester(game))
	{
		write(1, "Error\nInvalid map", 18);
		return (0);
	}
	return (1);
}

int	ft_parsingbis(t_game *game)
{
	if (!ft_createmap(game))
	{
		write(1, "Error\nbad map argument", 23);
		return (0);
	}
	if (!ft_parsing2(game))
		return (0);
	return (1);
}

int	ft_parsing(t_game *game, char *map)
{
	int		count;
	char	*line;

	if (!(ft_checkend(map)))
		return (0);
	count = open(map, O_RDONLY);
	if (count < 0)
	{
		write(1, "Error\nCan't read map", 21);
		return (0);
	}
	while (get_next_line(count, &line))
	{
		ft_parseline(game, line);
		free(line);
	}
	free (line);
	close (count);
	if (!ft_parsingbis(game))
		return (0);
	return (1);
}
