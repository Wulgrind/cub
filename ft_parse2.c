/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:12:06 by qbrillai          #+#    #+#             */
/*   Updated: 2021/07/15 14:18:55 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parseS(t_game *game, char *line)
{
	int	i;
	int	j;

	i = 1;
	while (line[i] == ' ')
		i++;
	while (!ft_isalpha(line[i]))
		i++;
	j = i - 1;
	while (ft_isalpha(line[i]))
		i++;
	game->param.S = malloc(sizeof(char) * (i - j + 1));
	if (game->param.S == NULL)
		return (0);
	i = 0;
	j++;
	while (ft_isalpha(line[j]))
	{
		game->param.S[i] = line[j];
		i++;
		j++;
	}
	game->param.S[i] = '\0';
	return (1);
}

int	ft_parseF(t_game *game, char *line)
{
	game->i = 0;
	game->j = 0;
	while (line[game->i] == ' ')
		game->i++;
	game->i++;
	while (line[game->i] == ' ')
		game->i++;
	while (line[game->i])
	{
		if (ft_isdigit(line[game->i]))
		{
			game->param.F[game->j] *= 10;
			game->param.F[game->j] += (line[game->i] - '0');
		}
		if (line[game->i] == ',')
			game->j++;
		if (!ft_isdigit(line[game->i]) && line[game->i] != ',')
			game->wrong3++;
		game->i++;
	}
	ft_checkMap4(game, line);
	return (1);
}

int	ft_parseC(t_game *game, char *line)
{
	game->i = 0;
	game->j = 0;
	while (line[game->i] == ' ')
		game->i++;
	game->i++;
	while (line[game->i] == ' ')
		game->i++;
	while (line[game->i])
	{
		if (ft_isdigit(line[game->i]))
		{
			game->param.C[game->j] *= 10;
			game->param.C[game->j] += (line[game->i] - '0');
		}
		if (line[game->i] == ',')
			game->j++;
		if (!ft_isdigit(line[game->i]) && line[game->i] != ',')
			game->wrong3++;
		game->i++;
	}
	ft_checkMap4(game, line);
	return (1);
}
