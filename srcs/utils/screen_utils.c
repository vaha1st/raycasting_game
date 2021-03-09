/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:28:04 by masharla          #+#    #+#             */
/*   Updated: 2021/03/09 01:48:51 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int    my_mlx_pixel_get(t_tex *tex, int x, int y)
{
	char	*dst;
	int		color;

	dst = tex->addr + (y * tex->l_len + x * (tex->bpp / 8));
	color = *(int*)dst;
	return (color);
}

void	my_mlx_pixel_put(t_window *window, int x, int y, int color)
{
	char	*dst;

	dst = window->address + (y * window->line_len + x *\
		(window->bit_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	generate_image(t_global *global, void draw_image(t_global *),\
	int pos_x, int pos_y)
{
	if (global->window.image)
		mlx_destroy_image(global->window.mlx, global->window.image);
	global->window.image = mlx_new_image(global->window.mlx,\
			global->config->res_x, global->config->res_y);
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
