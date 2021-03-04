/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:58:12 by masharla          #+#    #+#             */
/*   Updated: 2021/03/03 14:35:51 by ruslan           ###   ########.fr       */
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

#endif
