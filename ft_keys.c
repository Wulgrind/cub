#include "cub3d.h"

void	ft_freeparams3(t_game *game)
{
	int	i;

	i = 0;
	if (game->sprite)
	{
		while (i < game->param.sprite)
		{
			free (game->sprite[i]);
			i++;
		}
	}
	if (game->sprite)
		free (game->sprite);
	exit (0);
}

void	ft_freeparams2(t_game *game)
{
	int	i;

	i = 0;
	if (game->param.save)
		free (game->param.save);
	if (game->map)
	{
		while (i < game->param.row)
		{
			free (game->map[i]);
			i++;
		}
	}
	if (game->map)
		free (game->map);
	ft_freeparams3(game);
}

int	ft_freeparams(t_game *game)
{
	if (game->param.NO)
		free (game->param.NO);
	if (game->param.SO)
		free (game->param.SO);
	if (game->param.WE)
		free (game->param.WE);
	if (game->param.EA)
		free (game->param.EA);
	if (game->param.F)
		free (game->param.F);
	if (game->param.C)
		free (game->param.C);
	if (game->param.S)
		free (game->param.S);
	if (game->param.ZBuffer)
		free(game->param.ZBuffer);
	if (game->param.spriteOrder)
		free(game->param.spriteOrder);
	if (game->param.spriteDistance)
		free(game->param.spriteDistance);
	ft_freeparams2(game);
	return (1);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->move.forward = 1;
	else if (keycode == KEY_S)
		game->move.backward = 1;
	if (keycode == KEY_A)
		game->move.left = 1;
	else if (keycode == KEY_D)
		game->move.right = 1;
	else if (keycode == KEY_ESC)
	{
		ft_freeparams(game);
		exit (0);
	}
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->move.forward = 0;
	else if (keycode == KEY_S)
		game->move.backward = 0;
	else if (keycode == KEY_A)
		game->move.left = 0;
	else if (keycode == KEY_D)
		game->move.right = 0;
	return (0);
}
