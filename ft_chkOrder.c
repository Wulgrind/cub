#include "cub3d.h"

void	ft_chkOrder(t_game *game)
{
	if (game->param.NO == NULL
	|| game->param.SO == NULL
	|| game->param.WE == NULL
	|| game->param.EA == NULL
	|| game->param.F == NULL
	|| game->param.C == NULL)
		game->param.false++; 
}
