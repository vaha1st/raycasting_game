/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:28:04 by masharla          #+#    #+#             */
/*   Updated: 2021/03/03 14:14:50 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void 	init_window(t_global *global, int bbp, int l_len, int endian)
{
	global->window.mlx = mlx_init();
	global->window.window = mlx_new_window(global->window.mlx,\
			global->config.res_x, global->config.res_y, "Cub3d");
	global->window.bit_per_pixel = bbp;
	global->window.line_len = l_len;
	global->window.endian = endian;
	global->window.image = NULL;
	global->window.address = NULL;
}

void	my_mlx_pixel_put(t_window *window, int x, int y, int color)
{
	char *dst;

	dst = window->address + (y * window->line_len + x *\
		(window->bit_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	generate_image(t_global *global, void draw_image(t_global *),\
	int pos_x, int pos_y)
{
	global->window.image = mlx_new_image(global->window.mlx,\
			global->config.res_x, global->config.res_y);
	global->window.address = mlx_get_data_addr(global->window.image,\
			&global->window.bit_per_pixel, &global->window.line_len,\
			&global->window.endian);
	draw_image(global);
	mlx_put_image_to_window(global->window.mlx, global->window.window,\
		global->window.image, pos_x, pos_y);
}

void	draw_above_image(t_global *global, void draw_image(t_global *),\
	int pos_x, int pos_y)
{
	draw_image(global);
	mlx_put_image_to_window(global->window.mlx, global->window.window,\
		global->window.image, pos_x, pos_y);
}
