/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:58:12 by masharla          #+#    #+#             */
/*   Updated: 2021/03/18 15:17:41 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

void		my_mlx_pixel_put(t_global *global, int x, int y, int color);
int			mlx_pixel_get(t_tex *tex, int x, int y);
void		generate_image(t_global *global, void draw_image(t_global *),\
	int pos_x, int pos_y);
void		draw_above_image(t_global *global, void draw_image(t_global *),\
	int pos_x, int pos_y);
void		init_window(t_global *global);
t_player	find_player(t_conf *conf);
void		draw_minimap(t_global *glob);
void		draw_player_view(t_global *global);
float		adjust_angle(float angle);
t_player	cast_ray(t_global *global, float angle,\
	t_player init_ray(t_global *, float));
void		init_buttons(t_global *global);
void		init_player(t_player *player);
t_player	init_hor_ray(t_global *global, float angle);
t_player	init_ver_ray(t_global *global, float angle);
void		init_player(t_player *player);
void		init_texture(t_tex *tex);
void		init_textures(t_global *global);
void		clear_textures(t_global *global);
void		draw_floor_ceiling(t_global *global);
int			move_player(t_global *global);
int			button_pressed(int keycode, t_global *global);
int			button_released(int keycode, t_global *global);
float		find_dist(float px, float py, float rx, float ry);
void		count_sprites(t_global *global);
void		draw_sprites(t_global *glob, float *dist_buf);
void		make_a_step(t_player *player, char **map, float step, float dir);
void		make_a_turn(t_player *player, float step);

#endif
