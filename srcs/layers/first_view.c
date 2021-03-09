/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 02:37:52 by masharla          #+#    #+#             */
/*   Updated: 2021/03/09 02:31:12 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/utils.h"

int 		find_img_x(float raw_x, t_tex tex)
{
	double mod;

	mod = WALL_SCALE;
	return (floor(modf(raw_x, &mod) * tex.width));
}


void		draw_wall(t_global *global, t_player ray, t_tex tex, int ray_num)
{
	float	height;
	int		top;
	int		bottom;
	int		color;

	height = WALL_SCALE * global->config->res_y / ray.dist;
	tex.x = find_img_x(ray.x, tex);
	tex.y = 0;
	if (height > global->config->res_y)
		height = global->config->res_y;
	top = global->config->res_y / 2 - height / 2;
	if (top < 0)
		top = 0;
	bottom = global->config->res_y / 2 + height / 2;
	if (bottom >= global->config->res_y)
		bottom = global->config->res_y - 1;
	while (top < bottom)
	{
		color = my_mlx_pixel_get(&tex, tex.x, tex.y);
		tex.y += tex.height/height;
		my_mlx_pixel_put(&global->window, ray_num, bottom--, color);
	}
}

t_player 	swap_x_y(t_player ray)
{
	t_player result;

	result = ray;
	result.x = ray.y;
	result.y = ray.x;
	return (result);
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
		v_ray = swap_x_y(cast_ray(global, start, init_ver_ray, WALL_SCALE));
		if (h_ray.dist < v_ray.dist)
		{
			if (adjust_ray_angle(start) < M_PI)
				draw_wall(global, h_ray, global->north, i++);
			else
				draw_wall(global, h_ray, global->south, i++);
		}
		else if (v_ray.dist < h_ray.dist)
		{
			if (adjust_ray_angle(start) > M_PI_2\
				&& adjust_ray_angle(start) < M_PI_2 * 3)
				draw_wall(global, v_ray, global->west, i++);
			else
				draw_wall(global, v_ray, global->east, i++);
		}
		start += FOV / global->config->res_x;
	}
}
