/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:39:06 by masharla          #+#    #+#             */
/*   Updated: 2021/03/07 00:59:37 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/utils.h"

float 	adjust_ray_angle(float angle)
{
	if (angle < 0)
		return (angle + 2 * M_PI);
	if (angle > 2 * M_PI)
		return (angle - 2 * M_PI);
	return (angle);
}

int 		is_point_on_map(int x, int y, t_conf *config, int scale)
{
	x /= scale;
	y /= scale;
	if (y >= 0 & x >= 0 && y < config->map_len && x < ft_strlen
			(config->map[y]))
		return (1);
	return (0);
}

float 		find_dist(float px, float py, float rx, float ry)
{
	return (sqrt((px - rx) * (px - rx) + (py - ry) * (py - ry)));
}

t_player	init_hor_ray(t_global *global, float angle, int scale)
{
	t_player	ray;
	float 		px;
	float 		py;

	px = global->player.x * scale;
	py = global->player.y * scale;
	angle = adjust_ray_angle(angle);
	if (angle > M_PI)
	{
		ray.y = (int)(py / scale) * scale - 0.001;
		ray.x = px + (py - ray.y) / -tan(angle);
		ray.y_offset = -scale;
		ray.x_offset = ray.y_offset / tan(angle);
	}
	else if (angle < M_PI)
	{
		ray.y = (int)(py / scale) * scale + scale;
		ray.x = px + (py - ray.y) / -tan(angle);
		ray.y_offset = scale;
		ray.x_offset = ray.y_offset / tan(angle);
	}
	return (ray);
}

t_player	init_ver_ray(t_global *global, float angle, int scale)
{
	t_player	ray;
	float 		px;
	float 		py;

	px = global->player.x * scale;
	py = global->player.y * scale;
	angle = adjust_ray_angle(angle);
	if (angle > M_PI_2 && angle < M_PI_2 * 3)
	{
		ray.x = (int)(px / scale) * scale - 0.001;
		ray.y = py + (px - ray.x) * -tan(angle);
		ray.x_offset = -scale;
		ray.y_offset = ray.x_offset * tan(angle);
	}
	else if (angle < M_PI_2 * 3 || angle > 0)
	{
		ray.x = (int)(px / scale) * scale + scale;
		ray.y = py + (px - ray.x) * -tan(angle);
		ray.x_offset = scale;
		ray.y_offset = ray.x_offset * tan(angle);
	}
	return (ray);
}

t_player	cast_ray(t_global *global, float angle,\
	t_player init_ray(t_global *, float, int), int scale)
{
	t_player	ray;
	t_player	result;
	int 		dof;

	dof = 0;
	ray = init_ray(global, angle, scale);
	result.x = global->player.x * scale;
	result.y = global->player.y * scale;
	result.dist = 100000;
	while (dof < DOF)
	{
		if (is_point_on_map((int)ray.x, (int)ray.y, global->config, scale)\
			&& global->config->map[((int)ray.y) / scale]\
			[((int)ray.x) / scale] == '1')
		{
			dof = DOF;
			ray.dist = find_dist(result.x, result.y, ray.x, ray.y) * cos
					(angle - global->player.pov);
			result = ray;
//			my_mlx_pixel_put(&global->window, result.x, result.y,0xF51207);
		}
		else
		{
			dof++;
			ray.x += ray.x_offset;
			ray.y += ray.y_offset;
		}
	}
	return (result);
}
