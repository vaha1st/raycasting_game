/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:09:32 by masharla          #+#    #+#             */
/*   Updated: 2021/03/07 00:06:08 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/utils.h"

void		scale_pixel(t_window *window, int x, int y, int color, int scale)
{
	t_point	end;

	end.x = (x + 1) * scale;
	end.y = (y + 1) * scale;
	x *= scale;
	y *= scale;
	while (y < end.y)
	{
		while (x < end.x)
			my_mlx_pixel_put(window, x++, y, color);
		x -= scale;
		y++;
	}
}

void 		draw_player(t_global *global, int scale)
{
	t_player	pov_vector;
	int			pov_vector_len;
	int 		scale_x;
	int 		scale_y;

	pov_vector_len = 15;
	pov_vector.x = global->player.x * scale;
	pov_vector.y = global->player.y * scale;
	scale_y = -2;
	while (scale_y < 3)
	{
		scale_x = -2;
		while (scale_x < 3)
			my_mlx_pixel_put(&global->window, pov_vector.x + scale_x++,\
					pov_vector.y + scale_y,0xF51207);
		scale_y++;
	}
	while (pov_vector_len--)
	{
		pov_vector.x += cos(global->player.pov);
		pov_vector.y += sin(global->player.pov);
		my_mlx_pixel_put(&global->window, pov_vector.x, pov_vector.y,0xF51207);
	}
}

void		minimap_rays(t_global *global, int scale)
{
	t_player	h_ray;
	t_player	v_ray;
	float		start;
	float		end;

	start = global->player.pov - FOV / 2;
	end = global->player.pov + FOV / 2;
	while (start <= end)
	{
		h_ray = cast_ray(global, start, init_hor_ray, scale);
		v_ray = cast_ray(global, start, init_ver_ray, scale);
//		if (!h_ray.dist && v_ray.dist)
//			my_mlx_pixel_put(&global->window, v_ray.x, v_ray.y, 0x610DFF);
//		else if (!v_ray.dist && h_ray.dist)
//			my_mlx_pixel_put(&global->window, h_ray.x, h_ray.y, 0xF51207);
		if (h_ray.dist < v_ray.dist)
			my_mlx_pixel_put(&global->window, h_ray.x, h_ray.y, 0xF77E6D);
		else if (v_ray.dist < h_ray.dist)
			my_mlx_pixel_put(&global->window, v_ray.x, v_ray.y, 0x1A27FF);
		else if (h_ray.dist < 100000 && h_ray.dist == v_ray.dist)
			my_mlx_pixel_put(&global->window, v_ray.x, v_ray.y, 0x54C1F7);

		start += FOV / global->config->res_x;
	}
}

void		draw_minimap(t_global *global)
{
	t_point point;

	point.y = 0;
	while (global->config->map[point.y])
	{
		point.x = 0;
		while (global->config->map[point.y][point.x])
		{
			if (global->config->map[point.y][point.x] == '1')
				scale_pixel(&global->window, point.x, point.y, 0x20B2AA, MAP_SCALE);
			else if (global->config->map[point.y][point.x] == '2')
				scale_pixel(&global->window, point.x, point.y, 0xA75C4C, MAP_SCALE);
			else if (global->config->map[point.y][point.x] != ' ')
				scale_pixel(&global->window, point.x, point.y, 0x3C5C4C, MAP_SCALE);
			point.x++;
		}
		point.y++;
	}
	minimap_rays(global, MAP_SCALE);
	draw_player(global, MAP_SCALE);
}
