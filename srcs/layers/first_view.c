/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 02:37:52 by masharla          #+#    #+#             */
/*   Updated: 2021/03/07 16:14:47 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/utils.h"

void		draw_wall(t_global *global, float distance, int ray_num, int color)
{
	float	height;
	int		top;
	int		bottom;

	height = WALL_SCALE * global->config->res_y / distance;
	if (height > global->config->res_y)
		height = global->config->res_y;
	top = global->config->res_y / 2 - height / 2;
	if (top < 0)
		top = 0;
	bottom = global->config->res_y / 2 + height / 2;
	if (bottom >= global->config->res_y)
		bottom = global->config->res_y - 1;
	while (top < bottom)
		my_mlx_pixel_put(&global->window, ray_num, bottom--, color);
}

void		draw_player_view(t_global *global)
{
	t_player	h_ray;
	t_player	v_ray;
	float		start;
	float		end;
	int			i;

	start = global->player.pov - FOV / 2;
	end = global->player.pov + FOV / 2;
	i = 0;
	while (start <= end)
	{
		h_ray = cast_ray(global, start, init_hor_ray, WALL_SCALE);
		v_ray = cast_ray(global, start, init_ver_ray, WALL_SCALE);
		if (h_ray.dist < v_ray.dist)
		{
			if (adjust_ray_angle(start) < M_PI)
				draw_wall(global, h_ray.dist, i++, 0x36AD93);
			else
				draw_wall(global, h_ray.dist, i++, 0x44DBD9);
		}
		else if (v_ray.dist < h_ray.dist)
		{
			if (adjust_ray_angle(start) > M_PI_2\
				&& adjust_ray_angle(start) < M_PI_2 * 3)
				draw_wall(global, v_ray.dist, i++, 0x4ACFBF);
			else
				draw_wall(global, v_ray.dist, i++, 0x3BB39F);
		}
		start += FOV / global->config->res_x;
	}
}
