#include "cub3d.h"

void	ft_checkdir2(int num, t_game *game)
{
	if (num == 5)
	{
		game->cam.dirX = 0;
		game->cam.dirY = -1;
		game->cam.planeX = -0.66;
		game->cam.planeY = 0;
		game->cam.posY -= -1 * 0.50;
		game->cam.posX -= -1 * 0.50;
	}
	if (num == 6)
	{
		game->cam.dirX = 0;
		game->cam.dirY = 1;
		game->cam.planeX = 0.66;
		game->cam.planeY = 0;
		game->cam.posX -= -1 * 0.50;
		game->cam.posY -= -1 * 0.50;
	}
}

void	ft_checkdir(int num, t_game *game)
{
	if (num == 3)
	{
		game->cam.dirX = -1;
		game->cam.dirY = 0;
		game->cam.planeX = 0;
		game->cam.planeY = 0.66;
		game->cam.posX -= -1 * 0.50;
		game->cam.posY -= -1 * 0.50;
	}
	if (num == 4)
	{
		game->cam.dirX = 1;
		game->cam.dirY = 0;
		game->cam.planeX = 0;
		game->cam.planeY = -0.66;
		game->cam.posX -= -1 * 0.50;
		game->cam.posY -= -1 * 0.50;
	}
}

int	ft_checkst (t_game *game)
{
	int	row;
	int	col;
	int	check;

	row = 0;
	check = 0;
	while (row < game->param.row)
	{
		col = 0;
		while (game->map[row][col] != 10)
		{
			if (game->map[row][col] == 3 || game->map[row][col] == 4 ||
				game->map[row][col] == 5 || game->map[row][col] == 6)
			{
				check++;
				game->map[row][col] = 0;
			}
			col++;
		}
		row++;
	}
	if (check != 1)
		return (0);
	return (1);
}

int	ft_checkpos(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->param.row)
	{
		col = 0;
		while (game->map[row][col] != 10)
		{
			if (game->map[row][col] == 3 || game->map[row][col] == 4 ||
				game->map[row][col] == 5 || game->map[row][col] == 6)
			{
				game->cam.posX = row;
				game->cam.posY = col;
				ft_checkdir(game->map[row][col], game);
			}	
			col++;
		}
		row++;
	}
	if (!ft_checkst(game) || game->param.false > 0)
		return (0);
	return (1);
}
