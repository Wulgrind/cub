#include "cub3d.h"

typedef struct	s_ceiling
{
	int		y;
	int		x;
	float		rayDirX0;
	float		rayDirY0;
	float		rayDirX1;
	float		rayDirY1;
	int		p;
	float		posZ;
	float		rowDistance;
	float		floorStepX;
	float		floorStepY;
	float		floorX;
	float		floorY;
	int 		cellX;
	int 		cellY;
	int 		tx;
	int 		ty;
	t_img		floorTexture;
	t_img		ceilingTexture;
	unsigned int	color;
	
}		t_ceiling;

int	ft_generate(t_game *game, t_ceiling *ceiling)
{
	ceiling->floorTexture.img = mlx_xpm_file_to_image(game->mlx, game->param.F, &ceiling->floorTexture.img_width, &ceiling->floorTexture.img_height); 
	ceiling->floorTexture.data = (int *)mlx_get_data_addr(ceiling->floorTexture.img, &ceiling->floorTexture.bpp, &ceiling->floorTexture.size_l, &ceiling->floorTexture.endian);
	ceiling->ceilingTexture.img = mlx_xpm_file_to_image(game->mlx, game->param.C, &ceiling->ceilingTexture.img_width, &ceiling->ceilingTexture.img_height);
	ceiling->ceilingTexture.data = (int *)mlx_get_data_addr(ceiling->ceilingTexture.img, &ceiling->ceilingTexture.bpp, &ceiling->ceilingTexture.size_l, &ceiling->ceilingTexture.endian);
	return (1);
}

int	ft_ceiling2(t_game *game, t_ceiling *ceiling)
{
	ceiling->x = 0;
	while (ceiling->x < game->param.screenWidth)
	{
		ceiling->cellX = (int)ceiling->floorX;
		ceiling->cellY = (int)ceiling->floorY;
		ceiling->tx = (int)(ceiling->floorTexture.img_width * (ceiling->floorX - ceiling->cellX)) & (ceiling->floorTexture.img_width - 1);
		ceiling->ty = (int)(ceiling->floorTexture.img_height * (ceiling->floorY - ceiling->cellY)) & (ceiling->floorTexture.img_height - 1);
		ceiling->floorX += ceiling->floorStepX;
		ceiling->floorY += ceiling->floorStepY;
		ceiling->color = ceiling->floorTexture.data[ceiling->floorTexture.img_width * ceiling->ty + ceiling->tx];
		game->display.data[ceiling->y *game->param. screenWidth +  ceiling->x] = ceiling->color;
		ceiling->color = ceiling->ceilingTexture.data[ceiling->floorTexture.img_width * ceiling->ty + ceiling->tx];
		game->display.data[((game->param.screenHeight - ceiling->y - 1) * game->param.screenWidth) + ceiling->x] = ceiling->color;
		ceiling->x++;
	}
	return (1);
}

int	ft_ceiling1(t_game *game)
{
	t_ceiling	ceiling;

	ceiling.y = 0;
	ft_generate(game, &ceiling);
	while (ceiling.y < game->param.screenHeight)
	{	
		ceiling.rayDirX0 = game->cam.dirX - game->cam.planeX;
		ceiling.rayDirY0 = game->cam.dirY - game->cam.planeY;
		ceiling.rayDirX1 = game->cam.dirX + game->cam.planeX;
		ceiling.rayDirY1 = game->cam.dirY + game->cam.planeY;
		ceiling.p = ceiling.y - game->param.screenHeight / 2;
		ceiling.posZ = 0.5 * game->param.screenHeight;
		ceiling.rowDistance = ceiling.posZ / ceiling.p;
		ceiling.floorStepX = ceiling.rowDistance * (ceiling.rayDirX1 - ceiling.rayDirX0) / game->param.screenWidth;
		ceiling.floorStepY = ceiling.rowDistance * (ceiling.rayDirY1 - ceiling.rayDirY0) / game->param.screenWidth;
		ceiling.floorX = game->cam.posX + ceiling.rowDistance * ceiling.rayDirX0;
		ceiling.floorY = game->cam.posY + ceiling.rowDistance * ceiling.rayDirY0;
		ft_ceiling2(game, &ceiling);
		ceiling.y++;
	}
	return (1);
}
