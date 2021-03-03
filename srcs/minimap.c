/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:09:32 by masharla          #+#    #+#             */
/*   Updated: 2021/03/03 14:11:18 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/utils.h"

void		scale_pixel(t_window *window, int x, int y, int color)
{
	t_point end;
	int 	minimap_scale;

	minimap_scale = SCALE / 2;
	end.x = (x + 1) * minimap_scale;
	end.y = (y + 1) * minimap_scale;
	x *= minimap_scale;
	y *= minimap_scale;
	while (y < end.y)
	{
		while (x < end.x)
			my_mlx_pixel_put(window, x++, y, color);
		x -= minimap_scale;
		y++;
	}
}

void		minimap_rays(t_global *global, int scale)
{
	t_player ray;
	float start;
	float end;

	start = global->player.pov - FOV / 2;
	end = global->player.pov + FOV / 2;
	while (start <= end)
	{
		ray = global->player;
		ray.x *= scale;
		ray.y *= scale;
		while (global->config.map[(int)(ray.y / scale)][(int)(ray.x / scale)] !=
			   '1')
		{
			ray.x += cos(start);
			ray.y += sin(start);
			my_mlx_pixel_put(&global->window, ray.x, ray.y,0x990099);
		}
		start += FOV/PLANE;
	}
}

void		draw_minimap(t_global *global)
{
	t_point point;

	point.y = 0;
	while(global->config.map[point.y])
	{
		point.x = 0;
		while (global->config.map[point.y][point.x])
		{
			if (global->config.map[point.y][point.x] == '1')
				scale_pixel(&global->window, point.x, point.y, 0x20B2AA);
			else if (global->config.map[point.y][point.x] == '0')
				scale_pixel(&global->window, point.x, point.y, 0x3C5C4C);
			else
				scale_pixel(&global->window, point.x, point.y, 0xA75C4C);
			point.x++;
		}
		point.y++;
	}
	minimap_rays(global, SCALE / 2);
}
