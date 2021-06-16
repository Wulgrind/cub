#include "cub3d.h"

int	ft_checkMap3(t_game *game)
{
	int	row;
	int	col;
	row = 1;
	col = 0;
	while (row < game->param.row - 1)
	{
		if (game->map[row][0] != 1 && game->map[row][0] != 9)
			return (0);
		while (game->map[row][col] != 10)
		{
			col++;
		}
		col--;
		if (game->map[row][col] != 1 && game->map[row][col] != 9)
			return (0);
		col = 0;
		row++;
	}
	return (1);
}

int	ft_checkMap2(t_game *game)
{
	int	row;
	int	col;
	row = 1;
	col = 0;
	while (game->map[0][col] != 10)
	{
		if (game->map[0][col] != 1 && game->map[0][col] != 9)
			return (0);
		col++;
	}
	col = 0;
	while (row < game->param.row)
		row++;
	row--;
	while (game->map[row][col] != 10)
	{
		if (game->map[row][col] != 1 && game->map[row][col] != 9)
			return (0);
		col++;
	}
	return (1);
}

int	ft_checkMap(t_game *game)
{
	int	row;
	int	col;
	row = 0;
	while (row < game->param.row )
	{
		col = 0;
		while (game->map[row][col] != 10)
		{	
			if (game->map[row][col] == 9)
			{
				if (game->map[row][col + 1] == 0 || game->map[row][col + 1] == 2)
					return (0);
				if (game->map[row][col - 1] == 0 || game->map[row][col - 1] == 2)
					return (0);
				if (game->map[row - 1][col] == 0 || game->map[row - 1][col] == 2)
					return (0);
				if (game->map[row + 1][col] == 0 || game->map[row + 1][col] == 2)
					return (0);
			}
			col++;
		}
		row++;
	}
	return (1);
}
