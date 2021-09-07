/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:11:26 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/07 11:43:53 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line/get_next_line.h"
# include <mlx.h>
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
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef struct s_param
{
	int		screenheight;
	int		screenwidth;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
	char	*s;
	int		row;
	char	*save;
	int		wrong;
	int		sprite;
	double	*zbuffer;
	int		*spriteorder;
	double	*spritedistance;
	double	spritex;
	double	spritey;
	double	invdet;
	double	transformx;
	double	transformy;
	int		spritescreenx;
	int		spriteheight;
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
	int		straferight;
	int		strafeleft;
	double	movespeed;
	double	rotspeed;
	double	olddirx;
	double	oldplanex;
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
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	time;
	double	oldtime;
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
}		t_cam;

typedef struct s_game
{
	int				fd;
	int				wrong2;
	void			*mlx;
	void			*win;
	t_img			img;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				texnum;
	double			wallx;
	int				texx;
	int				**map;
	double			step;
	double			texpos;
	int				texy;
	unsigned int	color;
	int				x;
	int				y;
	t_img			display;
	t_cam			cam;
	t_move			move;
	t_param			param;
	double			**sprite;
	int				isdigit;
	int				y2;
	int				x2;
	float			raydirx0;
	float			raydiry0;
	float			raydirx1;
	float			raydiry1;
	int				p;
	float			posz;
	float			rowdistance;
	float			floorstepx;
	float			floorstepy;
	float			floorx;
	float			floory;
	int				cellx;
	int				celly;
	int				tx;
	int				ty;
	t_img			floortexture;
	t_img			ceilingtexture;
	int				countp;
	int				wrong3;
	int				i;
	int				j;
}		t_game;

int		ft_parsing(t_game *game, char *map);
int		ft_mainloop(t_game *game);
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
int		ft_parser(t_game *game, char *line);
int		ft_isdigit(char i);
void	ft_initparam(t_game *game);
int		ft_parseno(t_game *game, char *line);
int		ft_parseso(t_game *game, char *line);
int		ft_parsewe(t_game *game, char *line);
int		ft_parseea(t_game *game, char *line);
int		ft_parses(t_game *game, char *line);
int		ft_parsef(t_game *game, char *line);
int		ft_parsec(t_game *game, char *line);
int		ft_parsemap(t_game *game, char *line);
int		ft_isalpha(int c);
int		ft_strlen2(char *str);
int		ft_createmap(t_game *game);
int		ft_checkparams(t_game *game);
int		ft_checkmap(t_game *game);
int		ft_checkmap2(t_game *game);
int		ft_checkmap3(t_game *game);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_checkpos(t_game *game);
int		ft_freeparams(t_game *game);
int		ft_checksprite(t_game *game);
int		ft_spriteparam(t_game *game);
void	ft_mainloop2(t_game *game);
void	ft_chkorder(t_game *game);
void	ft_move4(t_game *game);
int		ft_checkmap4(t_game *game, char *line);
int		ft_tester(t_game *game);
#endif
