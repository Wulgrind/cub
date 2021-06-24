#include "cub3d.h"

int	ft_loop6(t_game *game)
{
	game->y = game->drawStart;
	game->step = 1.0 * game->img.img_height / game->lineHeight;
	game->texPos = (game->drawStart - game->param.screenHeight
			/ 2 + game->lineHeight / 2) * game->step;
	while (game->y < game->drawEnd)
	{
		game->texY = (int)game->texPos & (game->img.img_height - 1);
		game->texPos += game->step;
		game->color = game->img.data[game->texY
			* game->img.img_width + game->texX];
		game->display.data[game->y * game->param.screenWidth
			+ game->x] = game->color;
		game->y++;
	}
	game->move.moveSpeed = 0.05;
	game->move.rotSpeed = 0.05;
	return (1);
}
