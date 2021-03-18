/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:39:06 by masharla          #+#    #+#             */
/*   Updated: 2021/03/17 22:11:53 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/utils.h"

static int	is_on_map(t_player ray, t_conf *config, int scale, char item)
{
	int x;
	int y;

	x = (int)ray.x / scale;
	y = (int)ray.y / scale;
	if (y >= 0 & x >= 0 && y < config->map_len && x < ft_strlen(config->map[y])\
		&& config->map[y][x] == item)
		return (1);
	return (0);
}

float		find_dist(float px, float py, float rx, float ry)
{
	return (sqrt((px - rx) * (px - rx) + (py - ry) * (py - ry)));
}

t_player	init_hor_ray(t_global *global, float angle, int scale)
{
	t_player	ray;
	float		px;
	float		py;

	px = global->player.x * scale;
	py = global->player.y * scale;
	angle = adjust_angle(angle);
	if (angle > M_PI)
	{
		ray.y = (int)(py / scale) * scale - 0.001;
		ray.x = px + (py - ray.y) / -tan(angle);
		ray.y_of = -scale;
		ray.x_of = ray.y_of / tan(angle);
	}
	else if (angle < M_PI)
	{
		ray.y = (int)(py / scale) * scale + scale;
		ray.x = px + (py - ray.y) / -tan(angle);
		ray.y_of = scale;
		ray.x_of = ray.y_of / tan(angle);
	}
	return (ray);
}

t_player	init_ver_ray(t_global *global, float angle, int scale)
{
	t_player	ray;
	float		px;
	float		py;

	px = global->player.x * scale;
	py = global->player.y * scale;
	angle = adjust_angle(angle);
	if (angle > M_PI_2 && angle < M_PI_2 * 3)
	{
		ray.x = (int)(px / scale) * scale - 0.001;
		ray.y = py + (px - ray.x) * -tan(angle);
		ray.x_of = -scale;
		ray.y_of = ray.x_of * tan(angle);
	}
	else if (angle < M_PI_2 * 3 || angle > 0)
	{
		ray.x = (int)(px / scale) * scale + scale;
		ray.y = py + (px - ray.x) * -tan(angle);
		ray.x_of = scale;
		ray.y_of = ray.x_of * tan(angle);
	}
	return (ray);
}

t_player	cast_ray(t_global *global, float angle,\
	t_player init_ray(t_global *, float, int), int scale)
{
	t_player	ray;
	t_player	result;

	ray = init_ray(global, angle, scale);
	result.x = global->player.x * scale;
	result.y = global->player.y * scale;
	result.dist = 0;
	while (result.dist < DOF)
		if (is_on_map(ray, global->config, scale, '1'))
		{
			ray.dist = find_dist(result.x, result.y, ray.x, ray.y)\
				* cos(angle - global->player.pov);
			result = ray;
			break ;
		}
		else
		{
			ray.x += ray.x_of;
			ray.y += ray.y_of;
			result.dist = find_dist(result.x, result.y, ray.x, ray.y)\
				* cos(angle - global->player.pov);
		}
	return (result);
}
