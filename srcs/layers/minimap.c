/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:09:32 by masharla          #+#    #+#             */
/*   Updated: 2021/03/18 21:30:58 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/utils.h"

static void		scale_pixel(t_global *global, t_point point, int color,\
	int scale)
{
	t_point	end;

	end.x = (point.x + 1) * scale;
	end.y = (point.y + 1) * scale;
	point.x *= scale;
	point.y *= scale;
	while (point.y < end.y)
	{
		while (point.x < end.x)
			my_mlx_pixel_put(global, point.x++, point.y, color);
		point.x -= scale;
		point.y++;
	}
}

static void		draw_player(t_global *global, int scale)
{
	t_player	pov_vector;
	int			pov_vector_len;
	int			scale_x;
	int			scale_y;

	pov_vector_len = 15;
	pov_vector.x = global->player.x * scale;
	pov_vector.y = global->player.y * scale;
	scale_y = -2;
	while (scale_y < 3)
	{
		scale_x = -2;
		while (scale_x < 3)
			my_mlx_pixel_put(global, pov_vector.x + scale_x++,\
				pov_vector.y + scale_y, 0xF51207);
		scale_y++;
	}
	while (pov_vector_len--)
	{
		pov_vector.x += cos(global->player.pov);
		pov_vector.y += sin(global->player.pov);
		my_mlx_pixel_put(global, pov_vector.x, pov_vector.y, 0xF51207);
	}
}

static void		minimap_rays(t_global *global, int scale)
{
	t_player	h_ray;
	t_player	v_ray;
	float		start;
	float		end;

	start = global->player.pov - FOV / 2;
	end = global->player.pov + FOV / 2;
	while (start <= end)
	{
		h_ray = cast_ray(global, start, init_hor_ray);
		v_ray = cast_ray(global, start, init_ver_ray);
		if (h_ray.dist < v_ray.dist)
			my_mlx_pixel_put(global, h_ray.x * scale, h_ray.y * scale,
					0xF77E6D);
		else if (v_ray.dist < h_ray.dist)
			my_mlx_pixel_put(global, v_ray.x * scale, v_ray.y * scale,
					0x1A27FF);
		start += FOV / global->config->res_x;
	}
}

void			draw_minimap(t_global *glob)
{
	t_point pnt;
	int		scale;

	scale = glob->config->res_x / 3 / 100 * glob->config->res_y / 3 / 100;
	pnt.y = 0;
	while (glob->config->map[pnt.y])
	{
		pnt.x = 0;
		while (glob->config->map[pnt.y][pnt.x])
		{
			if (find_dist(glob->player.x, glob->player.y, pnt.x, pnt.y) < DOF)
			{
				if (glob->config->map[pnt.y][pnt.x] == '1')
					scale_pixel(glob, pnt, 0x20B2AA, scale);
				else if (glob->config->map[pnt.y][pnt.x] == '2')
					scale_pixel(glob, pnt, 0xA75C4C, scale);
				else if (glob->config->map[pnt.y][pnt.x] != ' ')
					scale_pixel(glob, pnt, 0x3C5C4C, scale);
			}
			pnt.x++;
		}
		pnt.y++;
	}
	minimap_rays(glob, scale);
	draw_player(glob, scale);
}
