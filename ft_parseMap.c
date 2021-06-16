#include "cub3d.h"

static int	ft_copy(t_game *game, char *line, char **ret)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (game->param.save)
	{
		while (game->param.save[i])
		{
			ret[0][i] = game->param.save[i];
			i++;
		}
	}
	while (line[j])
	{
		ret[0][i] = line[j];
		j++;
		i++;
	}
	ret[0][i] = '\n';
	ret[0][i + 1] = '\0';
	return (1);
}

static char	*ft_cpys(t_game *game, char *line)
{
	int		len1;
	int		len2;
	char	*ret;

	len1 = ft_strlen2(game->param.save);
	len2 = ft_strlen2(line);
	ret = malloc(sizeof(char) * (len1 + len2 + 2));
	if (ret == NULL)
		return (0);
	ft_copy(game, line, &ret);
	free(game->param.save);
	return (ret);
}

static int	ft_countline(t_game *game)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (game->param.save[i])
	{
		if (game->param.save[i] == '\n')
			ret++;
		i++;
	}
	return (ret);
}

void	ft_translate(t_game *game)
{
	int	i;

	i = 0;
	while (game->param.save[i])
	{
		if (game->param.save[i] == '9' || game->param.save[i] == '3'
			|| game->param.save[i] == '4'
			|| game->param.save[i] == '5' || game->param.save[i] == '6')
			game->param.false++;
		 if (game->param.save[i] == ' ')
			game->param.save[i] = '9';
		 if (game->param.save[i] == 'N')
			game->param.save[i] = '3';
		 if (game->param.save[i] == 'S')
			game->param.save[i] = '4';
		 if (game->param.save[i] == 'W')
			game->param.save[i] = '5';
		 if (game->param.save[i] == 'E')
			game->param.save[i] = '6';
		i++;
	}
}

int	ft_parseMap(t_game *game, char *line)
{
	game->param.save = ft_cpys(game, line);
	game->param.row = ft_countline(game);
	ft_translate(game);
	return (1);
}
