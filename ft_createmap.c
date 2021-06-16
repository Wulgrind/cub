#include "cub3d.h"

static int	ft_n(t_game *game)
{
	int	row;
	int	i;
	int	j;
	
	i = 0;
	row = 0;
	j = 0;
	game->map = malloc(sizeof(int *) * (game->param.row));
	if (game->map == NULL)
		return (0);
	while (game->param.save[i])
	{
		j = 0;
		while (game->param.save[i] != '\n')
		{
			i++;
			j++;
		}
		game->map[row] = malloc(sizeof(int) * (j));
		if (game->map[row] == NULL)
                                return (0);
		row++;
		i++;
	}
	return (1);
}

int		ft_createmap(t_game *game)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	j = 0;
	a = 0;
	ft_n(game);
	while (game->param.save[i])
	{
		if (game->param.save[i] == '0' || game->param.save[i] == '1' || game->param.save[i] == '2' || game->param.save[i] == '9' || game->param.save[i] == '3' || game->param.save[i] == '4' || game->param.save[i] == '5' || game->param.save[i] == '6')
		{
			game->map[j][a] = game->param.save[i] - '0';
			a++;
		}
		else if (game->param.save[i] == '\n')
		{
			game->map[j][a] = 10;
			a = 0;
			j++;	
		}
		else 
		{
			return (0);
		}
		i++;
	}
	return (1);
}
