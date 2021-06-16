#include "cub3d.h"

void	ft_sortSprites(t_game *game)
{
	int	temp;
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < game->param.sprite - 1)
	{
		j = game->param.spriteOrder[i];
		k = game->param.spriteOrder[i + 1];
		if (game->param.spriteDistance[j] < game->param.spriteDistance[k])
		{
			temp = game->param.spriteOrder[i + 1];
			game->param.spriteOrder[i + 1] = game->param.spriteOrder[i];
			game->param.spriteOrder[i] = temp;
			i = -1;
		}
		i++;
	}
}

void	ft_createsprites3(t_game *game, int *i)
{
	int	spriteWidth;
	int	drawStartX;
	int	drawEndX;
	int	stripe;
	int	texX;
	int	y;
	int	drawStartY;
	int	drawEndY;
	int	d;
	int	texY;
	unsigned int	color;

	drawStartY = -game->param.spriteHeight / 2 + game->param.screenHeight / 2;
	if(drawStartY < 0)
		drawStartY = 0;
	drawEndY = game->param.spriteHeight / 2 + game->param.screenHeight / 2;
	if (drawEndY >= game->param.screenHeight)
		drawEndY = game->param.screenHeight - 1;
	spriteWidth = abs((int)(game->param.screenHeight / (game->param.transformY)));
	drawStartX = -spriteWidth / 2 + game->param.spriteScreenX;
	if(drawStartX < 0)
		drawStartX = 0;
	drawEndX = spriteWidth / 2 + game->param.spriteScreenX;
	if(drawEndX >= game->param.screenWidth)
		drawEndX = game->param.screenWidth - 1;
	stripe = drawStartX;
	while (stripe < drawEndX)
	{
		texX = (int)(256 * (stripe - (-spriteWidth / 2 + game->param.spriteScreenX)) * game->img.img_width / spriteWidth) / 256;
		if (game->param.transformY > 0 && stripe > 0 && stripe < game->param.screenWidth && game->param.transformY < game->param.ZBuffer[stripe])
		y = drawStartY;
		while (y < drawEndY)
		{
			d = (y) * 256 - game->param.screenHeight * 128 + game->param.spriteHeight * 128;
			texY = ((d * game->img.img_height) / game->param.spriteHeight) / 256;
			color = game->img.data[texWidth * texY + texX];
			if((color & 0x00FFFFFF) != 0)
				game->display.data[y * game->param.screenWidth + stripe] = color;
			y++;
		}
		stripe++;
	}
}

void	ft_createsprites2(t_game *game)
{
	int	i;
	
	i = 0;
	while (i < game->param.sprite)
	{
		game->param.spriteX = game->sprite[game->param.spriteOrder[i]][0] - game->cam.posX;
		game->param.spriteY = game->sprite[game->param.spriteOrder[i]][1] - game->cam.posY;
		game->param.invDet = 1.0 / (game->cam.planeX * game->cam.dirY - game->cam.dirX * game->cam.planeY);
		game->param.transformX = game->param.invDet * (game->cam.dirY * game->param.spriteX - game->cam.dirX * game->param.spriteY);
		game->param.transformY = game->param.invDet * (-game->cam.planeY * game->param.spriteX + game->cam.planeX * game->param.spriteY);
		game->param.spriteScreenX = (int)((game->param.screenWidth / 2) * (1 + game->param.transformX / game->param.transformY));
		game->param.spriteHeight = abs((int)(game->param.screenHeight / (game->param.transformY)));
		ft_createsprites3(game, &i);
		i++;
	}
}

int	ft_createsprites(t_game *game)
{
	int	i;
	
	game->img.img = mlx_xpm_file_to_image(game->mlx, game->param.S, &game->img.img_width, &game->img.img_height);
        game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
	game->param.ZBuffer[game->x] = game->cam.perpWallDist;
	i = 0;
	while (i < game->param.sprite )
	{
		game->param.spriteOrder[i] = i;
		game->param.spriteDistance[i] = ((game->cam.posX - game->sprite[i][0]) * (game->cam.posX - game->sprite[i][0]) + (game->cam.posY - game->sprite[i][1]) * (game->cam.posY - game->sprite[i][1]));
		i++;
	}
	ft_sortSprites(game);
	ft_createsprites2(game);
	return (1);
}

int     ft_loop6(t_game *game)
{
	game->y = game->drawStart;
	game->step = 1.0 * texHeight / game->lineHeight;
	game->texPos = (game->drawStart - game->param.screenHeight / 2 + game->lineHeight / 2) * game->step;
	while (game->y < game->drawEnd)
	{
		game->texY = (int)game->texPos & (game->img.img_height - 1);
		game->texPos += game->step;
		game->color = game->img.data[game->texY * game->img.img_width + game->texX];
		game->display.data[game->y * game->param.screenWidth + game->x] = game->color;
		game->y++;
        }
	game->move.moveSpeed = 0.05;
	game->move.rotSpeed = 0.05;
	ft_createsprites(game);
	return (1);
}
