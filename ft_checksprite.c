#include "cub3d.h"

int	ft_checksprite3(t_game *game, int sprite)
{
	game->param.row2 = 0;
	game->param.i = 0;
	game->sprite = malloc(sizeof(int *) * sprite);
	if (!(game->sprite))
		return (0);
	return (1);
}

int	ft_checksprite2(t_game *game, int sprite)
{
	if (!ft_checksprite3(game, sprite))
		return (0);
	while (game->param.row2 < game->param.row)
	{
		game->param.col2 = 0;
		while (game->map[game->param.row2][game->param.col2] != 10)
		{
			if (game->map[game->param.row2][game->param.col2] == 2)
			{
				game->sprite[game->param.i] = malloc(sizeof(double) * 3);
				if (!game->sprite[game->param.i])
					return (0);
				game->sprite[game->param.i][0] = game->param.row2 + 0.5;
				game->sprite[game->param.i][1] = game->param.col2 + 0.5;
				game->sprite[game->param.i][2] = 2;
				game->param.i++;
				game->map[game->param.row2][game->param.col2] = 0;
			}
			game->param.col2++;
		}
		game->param.row2++;
	}
	return (1);
}

int	ft_checksprite(t_game *game)
{
	int	row;
	int	col;
	int	sprite;

	row = 0;
	sprite = 0;
	while (row < game->param.row)
	{
		col = 0;
		while (game->map[row][col] != 10)
		{
			if (game->map[row][col] == 2)
				sprite++;
			col++;
		}
		row++;
	}
	if (!(ft_checksprite2(game, sprite)))
		return (0);
	game->param.sprite = sprite;
	return (1);
}
