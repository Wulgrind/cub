#include "cub3d.h"

int	ft_checkParams(t_game *game)
{
	if (game->param.screenHeight == 0 || game->param.screenWidth == 0)
		return (0);
	if (game->param.NO == NULL || game->param.SO == NULL)
		return (0);
	if (game->param.WE == NULL || game->param.EA == NULL)
		return (0);
	if (game->param.F == NULL || game->param.C == NULL || game->param.S == NULL)
		return (0);
	if (game->param.row == 0)
		return (0);
	return (1);
}
