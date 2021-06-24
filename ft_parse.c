#include "cub3d.h"

int	ft_parseEA(t_game *game, char *line)
{
	int	i;
	int	j;

	i = 0;
	while (ft_isalpha(line[i]))
		i++;
	while (!ft_isalpha(line[i]))
		i++;
	j = i - 1;
	while (ft_isalpha(line[i]))
		i++;
	game->param.EA = malloc(sizeof(char) * (i - j + 1));
	if (game->param.EA == NULL)
		return (0);
	i = 0;
	j++;
	while (ft_isalpha(line[j]))
	{
		game->param.EA[i] = line[j];
		i++;
		j++;
	}
	game->param.EA[i] = '\0';
	return (1);
}

int	ft_parseWE(t_game *game, char *line)
{
	int	i;
	int	j;

	i = 0;
	while (ft_isalpha(line[i]))
		i++;
	while (!ft_isalpha(line[i]))
		i++;
	j = i - 1;
	while (ft_isalpha(line[i]))
		i++;
	game->param.WE = malloc(sizeof(char) * (i - j + 1));
	if (game->param.WE == NULL)
		return (0);
	i = 0;
	j++;
	while (ft_isalpha(line[j]))
	{
		game->param.WE[i] = line[j];
		i++;
		j++;
	}
	game->param.WE[i] = '\0';
	return (1);
}

int	ft_parseSO(t_game *game, char *line)
{
	int	i;
	int	j;

	i = 0;
	while (ft_isalpha(line[i]))
		i++;
	while (!ft_isalpha(line[i]))
		i++;
	j = i - 1;
	while (ft_isalpha(line[i]))
		i++;
	game->param.SO = malloc(sizeof(char) * (i - j + 1));
	if (game->param.SO == NULL)
		return (0);
	i = 0;
	j++;
	while (ft_isalpha(line[j]))
	{
		game->param.SO[i] = line[j];
		i++;
		j++;
	}
	game->param.SO[i] = '\0';
	return (1);
}

int	ft_parseNO(t_game *game, char *line)
{
	int	i;
	int	j;

	i = 0;
	while (ft_isalpha(line[i]))
		i++;
	while (!ft_isalpha(line[i]))
		i++;
	j = i - 1;
	while (ft_isalpha(line[i]))
		i++;
	game->param.NO = malloc(sizeof(char) * (i - j + 1));
	if (game->param.NO == NULL)
		return (0);
	i = 0;
	j++;
	while (ft_isalpha(line[j]))
	{
		game->param.NO[i] = line[j];
		i++;
		j++;
	}
	game->param.NO[i] = '\0';
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
