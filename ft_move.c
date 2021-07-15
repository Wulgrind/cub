#include "cub3d.h"

int	ft_move3(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->param.screenHeight)
	{
		x = 0;
		while (x < game->param.screenWidth)
		{
			game->display.data[y * game->param.screenWidth + x] = 0;
			x++;
		}
		y++;
	}
	ft_move4(game);
	return (1);
}

void	ft_movebis(t_game *game)
{
	game->move.oldDirX = game->cam.dirX;
	game->cam.dirX = game->cam.dirX * cos(game->move.rotSpeed)
		- game->cam.dirY * sin(game->move.rotSpeed);
	game->cam.dirY = game->move.oldDirX * sin(game->move.rotSpeed)
		+ game->cam.dirY * cos(game->move.rotSpeed);
	game->move.oldPlaneX = game->cam.planeX;
	game->cam.planeX = game->cam.planeX * cos(game->move.rotSpeed)
		- game->cam.planeY * sin(game->move.rotSpeed);
	game->cam.planeY = game->move.oldPlaneX * sin(game->move.rotSpeed)
		+ game->cam.planeY * cos(game->move.rotSpeed);
}

int	ft_move2(t_game *game)
{
	if (game->move.right == 1)
	{
		game->move.oldDirX = game->cam.dirX;
		game->cam.dirX = game->cam.dirX * cos(-game->move.rotSpeed)
			- game->cam.dirY * sin(-game->move.rotSpeed);
		game->cam.dirY = game->move.oldDirX * sin(-game->move.rotSpeed)
			+ game->cam.dirY * cos(-game->move.rotSpeed);
		game->move.oldPlaneX = game->cam.planeX;
		game->cam.planeX = game->cam.planeX * cos(-game->move.rotSpeed)
			- game->cam.planeY * sin(-game->move.rotSpeed);
		game->cam.planeY = game->move.oldPlaneX * sin(-game->move.rotSpeed)
			+ game->cam.planeY * cos(-game->move.rotSpeed);
	}
	if (game->move.left == 1)
	{
		ft_movebis(game);
	}
	ft_move3(game);
	return (1);
}

int	ft_move1(t_game *game)
{
	if (game->move.forward == 1)
	{
		if (game->map[(int)(game->cam.posX + game->cam.dirX
				* game->move.moveSpeed)][(int)(game->cam.posY)] == 0)
			game->cam.posX += game->cam.dirX * game->move.moveSpeed;
		if (game->map[(int)(game->cam.posX)][(int)(game->cam.posY
				+ game->cam.dirY * game->move.moveSpeed)] == 0)
			game->cam.posY += game->cam.dirY * game->move.moveSpeed;
	}
	if (game->move.backward == 1)
	{
		if (game->map[(int)(game->cam.posX - game->cam.dirX
				* game->move.moveSpeed)][(int)(game->cam.posY)] == 0)
			game->cam.posX -= game->cam.dirX * game->move.moveSpeed;
		if (game->map[(int)(game->cam.posX)][(int)(game->cam.posY
				- game->cam.dirY * game->move.moveSpeed)] == 0)
			game->cam.posY -= game->cam.dirY * game->move.moveSpeed;
	}
	ft_move2(game);
	return (1);
}
