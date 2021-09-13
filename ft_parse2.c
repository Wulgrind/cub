/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:12:06 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/13 13:16:08 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parses(t_game *game, char *line)
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
	game->param.s = malloc(sizeof(char) * (i - j + 1));
	if (game->param.s == NULL)
		return (0);
	i = 0;
	j++;
	while (ft_isalpha(line[j]))
	{
		game->param.s[i] = line[j];
		i++;
		j++;
	}
	game->param.s[i] = '\0';
	return (1);
}

int	ft_parsef(t_game *game, char *line)
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
			game->param.f[game->j] *= 10;
			game->param.f[game->j] += (line[game->i] - '0');
		}
		if (line[game->i] == ',')
			game->j++;
		if (!ft_isdigit(line[game->i]) && line[game->i] != ',')
			game->wrong3++;
		game->i++;
	}
	if (game->j != 2)
		game->param.wrong++;
	game->checkfc++;
	ft_checkmap4(game, line);
	return (1);
}

int	ft_parsec(t_game *game, char *line)
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
			game->param.c[game->j] *= 10;
			game->param.c[game->j] += (line[game->i] - '0');
		}
		if (line[game->i] == ',')
			game->j++;
		if (!ft_isdigit(line[game->i]) && line[game->i] != ',')
			game->wrong3++;
		game->i++;
	}
	if (game->j != 2)
		game->param.wrong++;
	game->checkfc++;
	ft_checkmap4(game, line);
	return (1);
}
