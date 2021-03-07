/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:58:12 by masharla          #+#    #+#             */
/*   Updated: 2021/03/07 15:27:46 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

void		my_mlx_pixel_put(t_window *window, int x, int y, int color);
void		generate_image(t_global *global, void draw_image(t_global *),\
	int pos_x, int pos_y);
void		draw_above_image(t_global *global, void draw_image(t_global *),\
	int pos_x, int pos_y);
void		init_window(t_global *global, int bbp, int l_len, int endian);
t_player	find_player(char **map);
void		draw_player_view(t_global *global);
float		adjust_ray_angle(float angle);
void		init_player(t_player *player);
t_player	cast_ray(t_global *global, float angle,\
	t_player init_ray(t_global *, float, int), int scale);
t_player	init_hor_ray(t_global *global, float angle, int scale);
t_player	init_ver_ray(t_global *global, float angle, int scale);
void		init_player(t_player *player);
void 		draw_floor_ceiling(t_global *global);

#endif
