/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:33:27 by adespond          #+#    #+#             */
/*   Updated: 2016/03/18 11:20:18 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <time.h>

# define WIDTH 800
# define HEIGHT 600

# define KEY_UP 13
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_DOWN 1
# define KEY_JUMP 49
# define KEY_ESC 53

# define KEY_PRESS_MASK (1L<<0)
# define KEY_PRESS 2

typedef struct		s_ixy
{
	int				x;
	int				y;
}					t_ixy;

typedef struct		s_dxy
{
	double			x;
	double			y;
}					t_dxy;

typedef struct		s_player
{
	struct s_dxy	pos;
	struct s_dxy	dir;
	struct s_dxy	plane;
	double			speed_turn;
	double			speed_move;
	int				z;
	char			is_jump;
	char			move_left;
	char			move_right;
	char			move_up;
	char			move_down;
	char			move_jump;
}					t_player;

typedef struct		s_ray
{
	struct s_dxy	pos;
	struct s_dxy	dir;
	struct s_ixy	map;
	struct s_dxy	side;
	struct s_dxy	delta;
	struct s_ixy	step;
	double			dist;
	double			cam;
	int				hit;
	int				hit_side;
}					t_ray;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pxl;
	int				bpp;
	int				s_line;
	int				ed;
	clock_t			last_frame;
	clock_t			next_frame;
}					t_mlx;

typedef struct		s_env
{
	struct s_mlx	mlx;
	struct s_player	player;
	struct s_ray	ray;
	int				height;
	int				width;
	int				**map;
	int				map_width;
	int				map_height;
	unsigned int	color_1;
	unsigned int	color_2;
	unsigned int	color_3;
	unsigned int	color_4;
	unsigned int	color_sky;
	unsigned int	color_ground;
	int				start_x;
	int				start_y;
}					t_env;

int					loop_hook(t_env *e);
int					open_file(t_env *e, char *f);
int					key_hook(int k, t_env *e);
int					key_press(int k, t_env *e);
int					key_release(int k, t_env *e);
t_env				*init_env(void);
void				draw_line(t_env *e, int x, int start, int end);
void				raycasting(t_env *e);
void				move_left(t_env *e);
void				move_right(t_env *e);
void				move_up(t_env *e);
void				move_down(t_env *e);
void				move_jump(t_env *e);
void				error_map(void);
void				error_arg(void);
void				error_malloc(void);
#endif
