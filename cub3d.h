#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17
# define KEY_ESC 53
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_param
{
	int		screenHeight;
	int		screenWidth;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
	char	*S;
	int		row;
	char	*save;
	int		false;
	int		sprite;
	double	*ZBuffer;
	int		*spriteOrder;
	double	*spriteDistance;
	double	spriteX;
	double	spriteY;
	double	invDet;
	double	transformX;
	double	transformY;
	int		spriteScreenX;
	int		spriteHeight;
	int		row2;
	int		col2;
	int		i;
}		t_param;

typedef struct s_move
{
	int		forward;
	int		backward;
	int		right;
	int		left;
	double	moveSpeed;
	double	rotSpeed;
	double	oldDirX;
	double	oldPlaneX;
}		t_move;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}		t_img;

typedef struct s_cam
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	time;
	double	oldtime;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
}		t_cam;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_img			img;
	int				lineHeight;
	int				drawStart;
	int				drawEnd;
	int				texNum;
	double			wallX;
	int				texX;
	int				**map;
	double			step;
	double			texPos;
	int				texY;
	unsigned int	color;
	int				x;
	int				y;
	t_img			display;
	t_cam			cam;
	t_move			move;
	t_param			param;
	double			**sprite;
}		t_game;

int		ft_parsing(t_game *game, char *map);
int		ft_mainLoop(t_game *game);
void	ft_loop2(t_game *game);
int		ft_loop3(t_game *game);
int		ft_loop4(t_game *game);
int		ft_loop5(t_game *game);
int		ft_loop6(t_game *game);
int		ft_move1(t_game *game);
int		ft_move2(t_game *game);
int		ft_move3(t_game *game);
int		key_release(int keycode, t_game *game);
int		key_press(int keycode, t_game *game);
int		window_init(t_game *game);
int		img_init(t_game *game);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_ceiling1(t_game *game);
int		ft_parsing(t_game *game, char *map);
int		ft_parseR(t_game *game, char *line);
int		ft_isdigit(char i);
void	ft_initParam(t_game *game);
int		ft_parseNO(t_game *game, char *line);
int		ft_parseSO(t_game *game, char *line);
int		ft_parseWE(t_game *game, char *line);
int		ft_parseEA(t_game *game, char *line);
int		ft_parseS(t_game *game, char *line);
int		ft_parseF(t_game *game, char *line);
int		ft_parseC(t_game *game, char *line);
int		ft_parseMap(t_game *game, char *line);
int		ft_isalpha(int c);
int		ft_strlen2(char *str);
int		ft_createmap(t_game *game);
int		ft_checkParams(t_game *game);
int		ft_checkMap(t_game *game);
int		ft_checkMap2(t_game *game);
int		ft_checkMap3(t_game *game);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_checkpos(t_game *game);
void	ft_freeparams(t_game *game);
int		ft_checksprite(t_game *game);
int		ft_spriteparam(t_game *game);
void	ft_mainloop2(t_game *game);

#endif
