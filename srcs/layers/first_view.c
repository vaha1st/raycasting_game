/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 02:37:52 by masharla          #+#    #+#             */
/*   Updated: 2021/03/23 16:13:22 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/utils.h"

static t_player	swap_x_y(t_player ray)
{
	t_player result;

	result = ray;
	result.x = ray.y;
	result.y = ray.x;
	return (result);
}

static void		find_tex_x(t_player ray, t_tex *tex)
{
	tex->x = fmod(ray.x, 1) * tex->width;
	if (tex->reverse)
		tex->x = tex->width - tex->x;
	if (tex->x < 2)
		tex->x = floor(tex->x);
	if (tex->x > tex->width - 1)
		tex->x = tex->width;
}

static void		draw_wall(t_global *global, t_player ray, t_tex tex,\
	int ray_num)
{
	float	height;
	float	top;
	float	bottom;
	float	step;

	height = global->config->res_y / ray.dist *
			global->config->res_x / global->config->res_y;
	step = tex.width / height;
	find_tex_x(ray, &tex);
	tex.y = 0;
	if (height > global->config->res_y)
	{
		tex.y = (height - global->config->res_y) / 2 * step;
		height = global->config->res_y;
	}
	top = global->config->res_y / 2 - height / 2;
	bottom = global->config->res_y / 2 + height / 2;
	while (top < bottom)
	{
		my_mlx_pixel_put(global, ray_num, top++,
			mlx_pixel_get(&tex, tex.x, tex.y));
		tex.y += step;
	}
}

static float	select_ray(t_global *global, t_player h_ray,\
	t_player v_ray, int i)
{
	if (h_ray.dist < v_ray.dist && h_ray.dist < DOF)
	{
		if (adjust_angle(h_ray.pov) < M_PI)
			draw_wall(global, h_ray, global->south, i);
		else
			draw_wall(global, h_ray, global->north, i);
		return (h_ray.dist);
	}
	else if (v_ray.dist < h_ray.dist && v_ray.dist < DOF)
	{
		if (adjust_angle(v_ray.pov) > M_PI_2\
				&& adjust_angle(v_ray.pov) < M_PI_2 * 3)
			draw_wall(global, v_ray, global->west, i);
		else
			draw_wall(global, v_ray, global->east, i);
		return (v_ray.dist);
	}
	return (global->plr.dist);
}

void			draw_player_view(t_global *global)
{
	t_player	h_ray;
	t_player	v_ray;
	t_fov		fov;
	float		dist_buf[global->config->res_x];
	int			i;

	count_sprites(global);
	fov.start = global->plr.pov - FOV / 2;
	fov.end = global->plr.pov + FOV / 2 - FOV / global->config->res_x;
	i = 0;
	while (fov.start < fov.end && i <= global->config->res_x)
	{
		h_ray = cast_ray(global, fov.start, init_hor_ray);
		v_ray = swap_x_y(cast_ray(global, fov.start, init_ver_ray));
		h_ray.pov = fov.start;
		v_ray.pov = fov.start;
		dist_buf[i] = select_ray(global, h_ray, v_ray, i);
		fov.start += FOV / global->config->res_x;
		i++;
	}
	draw_sprites(global, dist_buf);
}
