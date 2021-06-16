#include "cub3d.h"

void	ft_mainloop2(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->display.img, 0, 0);
	if (game->move.forward == 1 || game->move.backward == 1
		|| game->move.left == 1 || game->move.right == 1)
		ft_move1(game);
}
