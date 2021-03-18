/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:28:04 by masharla          #+#    #+#             */
/*   Updated: 2021/03/14 14:58:16 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		mlx_pixel_get(t_tex *tex, int x, int y)
{
	char	*dst;
	int		color;

	dst = tex->addr + (y * tex->l_len + x * (tex->bpp / 8));
	color = *(int*)dst;
	return (color);
}

void	my_mlx_pixel_put(t_global *global, int x, int y, int color)
{
	char	*dst;

	dst = global->window.address + (y * global->window.line_len + x\
		* (global->window.bit_per_pixel / 8));
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
}

void	draw_above_image(t_global *global, void draw_image(t_global *),\
	int pos_x, int pos_y)
{
	draw_image(global);
	mlx_put_image_to_window(global->window.mlx, global->window.window,\
		global->window.image, pos_x, pos_y);
}
