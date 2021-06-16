#include "cub3d.h"

int	ft_parseS(t_game *game, char *line)
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

	i = 0;
	while (ft_isalpha(line[i]))
		i++;
	while (!ft_isalpha(line[i]))
		i++;
	j = i - 1;
	while (ft_isalpha(line[i]))
		i++;
	game->param.F = malloc(sizeof(char) * (i - j + 1));
	if (game->param.F == NULL)
		return (0);
	i = 0;
	j++;
	while (ft_isalpha(line[j]))
	{
		game->param.F[i] = line[j];
		i++;
		j++;
	}
	game->param.F[i] = '\0';
	return (1);
}

int	ft_parseC(t_game *game, char *line)
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
	game->param.C = malloc(sizeof(char) * (i - j + 1));
	if (game->param.C == NULL)
		return (0);
	i = 0;
	j++;
	while (ft_isalpha(line[j]))
	{
		game->param.C[i] = line[j];
		i++;
		j++;
	}
	game->param.C[i] = '\0';
	return (1);
}
