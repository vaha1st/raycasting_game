/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:28:14 by masharla          #+#    #+#             */
/*   Updated: 2021/03/07 02:21:05 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


# define MAP_SCALE 12
# define WALL_SCALE 64
# define DOF 100
# define FOV M_PI/3

# include "../srcs/libft/libft.h"
# include "../srcs/minilibx/mlx.h"
# include <math.h>

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_player
{
	float x;
	float y;
	float pov;
	float dist;
	float x_offset;
	float y_offset;
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
	char	*ceilling_c;
	char	**map;
	int 	map_len;
}				t_conf;

typedef struct	s_global
{
	t_player	player;
	t_conf		*config;
	t_window	window;
}				t_global;

t_conf			*parser(char *configuration_file);
void			draw_minimap(t_global *global);
void			clear_t_conf(t_conf *config);

#endif
