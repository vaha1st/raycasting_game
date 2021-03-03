/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:17:42 by masharla          #+#    #+#             */
/*   Updated: 2021/03/03 14:25:22 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/utils.h"

void 		init_player(t_player *player)
{
	player->pov = 0;
	player->x = 0;
	player->y = 0;
}

float		get_pov_angle(char pov)
{
	if (pov == 'N')
		return (M_PI_2 * 3);
	else if (pov == 'S')
		return (M_PI_2);
	else if (pov == 'W')
		return (M_PI);
	else
		return (0);
}

t_player	find_player(char **map)
{
	t_player player;
	int x;
	int y;

	y = 0;
	init_player(&player);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_isinset(map[y][x], "SNWE"))
			{
				if (!player.x && !player.y)
				{
					player.x = x;
					player.y = y;
					player.pov = get_pov_angle(map[y][x]);
				} else
				{
					ft_putstr_fd("Error: Not a single player", 1);
					exit(0);
				}
			}
			x++;
		}
		y++;
	}
	return (player);
}

void 		draw_wall(t_global *global, float distance, int ray_num)
{
	float	height;
	int 	top;
	int 	bottom;

	height = global->config.res_y / distance;
	top = global->config.res_y / 2 - height / 2;
	if (top < 0)
		top = 0;
	bottom = global->config.res_y / 2 + height / 2;
	if (bottom >= global->config.res_y)
		bottom = global->config.res_y - 1;
	while (top < bottom)
		my_mlx_pixel_put(&global->window, ray_num, bottom--, 0x8DD5D9);
}

void		draw_player_view(t_global *global)
{
	t_player	ray;
	float		start;
	float		end;
	int 		i;

	start = global->player.pov - FOV / 2;
	end = global->player.pov + FOV / 2;
	i = 0;
	while (start <= end)
	{
		ray = global->player;
		ray.dist = 0;
		while (global->config.map[(int)(ray.y)][(int)(ray.x)] != '1')
		{
			ray.x = global->player.x + ray.dist * cos(start);
			ray.y = global->player.y + ray.dist * sin(start);
			ray.dist += 0.01;
		}
		ray.dist *= cos(start - global->player.pov);
		draw_wall(global, ray.dist, i++);
		start += FOV/global->config.res_x;
	}
}

