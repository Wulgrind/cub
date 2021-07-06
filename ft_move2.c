#include "cub3d.h"

void	ft_move4(t_game *game)
{
	if (game->move.strafeRight == 1)
	{
		if (game->map[(int)(game->cam.posX + game->cam.planeX
				* game->move.moveSpeed)][(int)(game->cam.posY)] == 0)
			game->cam.posX += game->cam.planeX * game->move.moveSpeed;
		if (game->map[(int)(game->cam.posX)][(int)(game->cam.posY
				+ game->cam.planeY * game->move.moveSpeed)] == 0)
			game->cam.posY += game->cam.planeY * game->move.moveSpeed;
	}
	if (game->move.strafeLeft == 1)
	{
		if (game->map[(int)(game->cam.posX - game->cam.planeX
				* game->move.moveSpeed)][(int)(game->cam.posY)] == 0)
			game->cam.posX -= game->cam.planeX * game->move.moveSpeed;
		if (game->map[(int)(game->cam.posX)][(int)(game->cam.posY
				- game->cam.planeY * game->move.moveSpeed)] ==0)
			game->cam.posY -= game->cam.planeY * game->move.moveSpeed;
	}
}
