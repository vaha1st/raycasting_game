/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:28:14 by masharla          #+#    #+#             */
/*   Updated: 2021/03/18 14:41:48 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WALL_SCALE 64
# define DOF 30 * WALL_SCALE
# define FOV M_PI / 3
# define BPP 32
# define L_LEN 24
# define ENDIAN 0

# include "../srcs/libft/libft.h"
# include "../srcs/minilibx/mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_fov
{
	float start;
	float end;
}				t_fov;

typedef struct	s_player
{
	float	x;
	float	y;
	float	pov;
	float	dist;
	float	x_of;
	float	y_of;
	float	size;
}				t_player;

typedef struct	s_window
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*address;
	int		bit_per_pixel;
	int		line_len;
	int		endian;
}				t_window;

typedef struct	s_conf
{
	int		res_x;
	int		res_y;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	char	*floor_c;
	char	*ceiling_c;
	char	**map;
	int		map_len;
}				t_conf;

typedef struct	s_tex
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		l_len;
	int		end;
	int		reverse;
	float	x;
	float	y;
}				t_tex;

typedef struct	s_global
{
	t_player	player;
	t_conf		*config;
	t_window	window;
	int			w_btn;
	int			s_btn;
	int			a_btn;
	int			d_btn;
	int			left_btn;
	int			right_btn;
	t_tex		north;
	t_tex		south;
	t_tex		west;
	t_tex		east;
	t_tex		sprite;
	int			count_sprt;
}				t_global;

t_conf			*parser(char *configuration_file);
void			make_screenshot(t_global *global);
void			clean_exit(t_conf *conf, int err_id);
void			clear_t_conf(t_conf *config);

#endif
