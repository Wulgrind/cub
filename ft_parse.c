/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:10:42 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/09 11:02:03 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parseea(t_game *game, char *line)
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
	game->param.ea = malloc(sizeof(char) * (game->i - game->j + 1));
	if (game->param.ea == NULL)
		return (0);
	game->i = 0;
	game->j++;
	while (line[game->j])
	{
		game->param.ea[game->i] = line[game->j];
		game->i++;
		game->j++;
	}
	game->param.ea[game->i] = '\0';
	ft_checkmap4(game, line);
	return (1);
}

int	ft_parsewe(t_game *game, char *line)
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
	game->param.we = malloc(sizeof(char) * (game->i - game->j + 1));
	if (game->param.we == NULL)
		return (0);
	game->i = 0;
	game->j++;
	while (line[game->j])
	{
		game->param.we[game->i] = line[game->j];
		game->i++;
		game->j++;
	}
	game->param.we[game->i] = '\0';
	ft_checkmap4(game, line);
	return (1);
}

int	ft_parseso(t_game *game, char *line)
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
	game->param.so = malloc(sizeof(char) * (game->i - game->j + 1));
	if (game->param.so == NULL)
		return (0);
	game->i = 0;
	game->j++;
	while (line[game->j])
	{
		game->param.so[game->i] = line[game->j];
		game->i++;
		game->j++;
	}
	game->param.so[game->i] = '\0';
	ft_checkmap4(game, line);
	return (1);
}

int	ft_parseno(t_game *game, char *line)
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
	game->param.no = malloc(sizeof(char) * (game->i - game->j + 1));
	if (game->param.no == NULL)
		return (0);
	game->i = 0;
	game->j++;
	while (line[game->j])
	{
		game->param.no[game->i] = line[game->j];
		game->i++;
		game->j++;
	}
	game->param.no[game->i] = '\0';
	ft_checkmap4(game, line);
	return (1);
}

int	ft_parser(t_game *game, char *line)
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
	game->param.screenwidth = ret;
	ret = 0;
	while (!ft_isdigit(line[i]))
		i++;
	while (ft_isdigit(line[i]))
	{
		ret = ret * 10;
		ret += (line[i] - '0');
		i++;
	}
	game->param.screenheight = ret;
	return (1);
}
