/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:14:18 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/13 13:26:49 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parseline2(t_game *game, char *line, int *i)
{
	if (ft_isdigit(line[*i]))
	{
		ft_parsemap(game, line);
		game->isdigit = 1;
	}
	else if (line[0] == '\n' || line[0] == '\0')
		game->param.wrong *= 1;
	else
		game->param.wrong++;
	return (1);
}

int	ft_parseline(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		ft_parseno(game, line);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		ft_parseso(game, line);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		ft_parsewe(game, line);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		ft_parseea(game, line);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		ft_parsef(game, line);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		ft_parsec(game, line);
	else
		ft_parseline2(game, line, &i);
	if (!(ft_isdigit(line[i])) && game->isdigit == 1
		&& line[i] != '\n' && line[i] != '\0')
		game->param.wrong++;
	if (!ft_checkempty(game, line))
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
		if (i == 3 || game->countp > 6)
			write (1, "Error\nIncorrect parameters", 26);
		return (0);
	}
	if (!ft_lastline(game) || !ft_checkmap(game)
		|| !ft_checkmap2(game) || !ft_checkmap3(game) || game->checkfc != 2)
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
	if (count < 0 || ft_directory(map))
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
