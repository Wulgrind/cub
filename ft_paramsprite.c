#include "cub3d.h"

int	ft_spriteparam(t_game *game)
{
	game->param.ZBuffer = malloc(sizeof(double) * game->param.screenWidth);
	game->param.spriteOrder = malloc(sizeof(int) * game->param.sprite);
	game->param.spriteDistance = malloc(sizeof(double) * game->param.sprite);
	return (1);
}
