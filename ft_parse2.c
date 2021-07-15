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
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			game->param.F[j] *= 10;
			game->param.F[j] += (line[i] - '0');
		}
		if (line[i] == ',')
			j++;
		if (!ft_isdigit(line[i]) && line[i] != ',')
			game->wrong3++;
		i++;
	}
	ft_checkMap4(game, line);
	return (1);
}

int	ft_parseC(t_game *game, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (!ft_isdigit(line[i]))
		i++;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			game->param.C[j] *= 10;
			game->param.C[j] += (line[i] - '0');
		}
		if (line[i] == ',')
			j++;
		if (!ft_isdigit(line[i]) && line[i] != ',')
			game->wrong3++;
		i++;
	}
	ft_checkMap4(game, line);
	return (1);
}
