#include "cub3d.h"

int	ft_checkParams2(t_game *game)
{
	int	i;

	i = 0;
	while (game->param.C[i])
	{
		if (game->param.C[i] > 255)
			return (0);
		i++;
	}
	i = 0;
	while (game->param.F[i])
	{
		if (game->param.F[i] > 255)
			return (0);
		i++;
	}
	return (1);
}

int	ft_checkParams(t_game *game)
{
	if (game->param.screenHeight == 0 || game->param.screenWidth == 0)
		return (0);
	if (game->param.NO == NULL || game->param.SO == NULL)
		return (0);
	if (game->param.WE == NULL || game->param.EA == NULL)
		return (0);
	if (game->param.F[0] == 0 && game->param.F[1] == 0
		&& game->param.F[2] == 0)
		return (0);
	if (game->param.C[0] == 0 && game->param.C[1] == 0
		&& game->param.C[2] == 0)
		return (0);
	if (!ft_checkParams2(game))
		return (0);
	return (1);
}
