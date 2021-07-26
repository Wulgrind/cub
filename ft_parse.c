/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:10:42 by qbrillai          #+#    #+#             */
/*   Updated: 2021/07/15 14:10:44 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parseEA(t_game *game, char *line)
{
	game->i = 0;
	while (line[game->i] == ' ')
		game->i++;
	while (ft_isalpha(line[game->i]))
		game->i++;
	while (!ft_isalpha(line[game->i]))
		game->i++;
	game->j = game->i - 1;
	while (ft_isalpha(line[game->i]))
		game->i++;
	game->param.EA = malloc(sizeof(char) * (game->i - game->j + 1));
	if (game->param.EA == NULL)
		return (0);
	game->i = 0;
	game->j++;
	while (ft_isalpha(line[game->j]))
	{
		game->param.EA[game->i] = line[game->j];
		game->i++;
		game->j++;
	}
	game->param.EA[game->i] = '\0';
	ft_checkMap4(game, line);
	return (1);
}

int	ft_parseWE(t_game *game, char *line)
{
	game->i = 0;
	while (line[game->i] == ' ')
		game->i++;
	while (ft_isalpha(line[game->i]))
		game->i++;
	while (!ft_isalpha(line[game->i]))
		game->i++;
	game->j = game->i - 1;
	while (ft_isalpha(line[game->i]))
		game->i++;
	game->param.WE = malloc(sizeof(char) * (game->i - game->j + 1));
	if (game->param.WE == NULL)
		return (0);
	game->i = 0;
	game->j++;
	while (ft_isalpha(line[game->j]))
	{
		game->param.WE[game->i] = line[game->j];
		game->i++;
		game->j++;
	}
	game->param.WE[game->i] = '\0';
	ft_checkMap4(game, line);
	return (1);
}

int	ft_parseSO(t_game *game, char *line)
{
	game->i = 0;
	while (line[game->i] == ' ')
		game->i++;
	while (ft_isalpha(line[game->i]))
		game->i++;
	while (!ft_isalpha(line[game->i]))
		game->i++;
	game->j = game->i - 1;
	while (ft_isalpha(line[game->i]))
		game->i++;
	game->param.SO = malloc(sizeof(char) * (game->i - game->j + 1));
	if (game->param.SO == NULL)
		return (0);
	game->i = 0;
	game->j++;
	while (ft_isalpha(line[game->j]))
	{
		game->param.SO[game->i] = line[game->j];
		game->i++;
		game->j++;
	}
	game->param.SO[game->i] = '\0';
	ft_checkMap4(game, line);
	return (1);
}

int	ft_parseNO(t_game *game, char *line)
{
	game->i = 0;
	while (line[game->i] == ' ')
		game->i++;
	while (ft_isalpha(line[game->i]))
		game->i++;
	while (!ft_isalpha(line[game->i]))
		game->i++;
	game->j = game->i - 1;
	while (ft_isalpha(line[game->i]))
		game->i++;
	game->param.NO = malloc(sizeof(char) * (game->i - game->j + 1));
	if (game->param.NO == NULL)
		return (0);
	game->i = 0;
	game->j++;
	while (ft_isalpha(line[game->j]))
	{
		game->param.NO[game->i] = line[game->j];
		game->i++;
		game->j++;
	}
	game->param.NO[game->i] = '\0';
	ft_checkMap4(game, line);
	return (1);
}

int	ft_parseR(t_game *game, char *line)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (!ft_isdigit(line[i]))
		i++;
	while (ft_isdigit(line[i]))
	{
		ret = ret * 10;
		ret += (line[i] - '0');
		i++;
	}
	game->param.screenWidth = ret;
	ret = 0;
	while (!ft_isdigit(line[i]))
		i++;
	while (ft_isdigit(line[i]))
	{
		ret = ret * 10;
		ret += (line[i] - '0');
		i++;
	}
	game->param.screenHeight = ret;
	return (1);
}
