/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:31:03 by masharla          #+#    #+#             */
/*   Updated: 2021/02/25 16:27:07 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void		scale_pixel(t_window *window, t_point start, int color)
{
	t_point end;

	end.x = (start.x + 1) * SCALE;
	end.y = (start.y + 1) * SCALE;
	start.x *= SCALE;
	start.y *= SCALE;
	while (start.y < end.y)
	{
		while (start.x < end.x)
			mlx_pixel_put(window->mlx, window->window, start.x++, start.y,
				 color);
		start.x -= SCALE;
		start.y++;
	}
}

void		scale_player(t_window *window, t_player start, int color)
{
	t_player end;

	end.x = (start.x + 1) * SCALE;
	end.y = (start.y + 1) * SCALE;
	start.x *= SCALE;
	start.y *= SCALE;
	while (start.y < end.y)
	{
		while (start.x < end.x)
			mlx_pixel_put(window->mlx, window->window, start.x++, start.y,
						  color);
		start.x -= SCALE;
		start.y++;
	}
}

float		get_pov_angle(char pov)
{
	if (pov == 'N')
		return (M_PI_2);
	else if (pov == 'S')
		return (M_PI);
	else if (pov == 'W')
		return (M_PI_2 * 3);
	else
		return (0);
}

void 		init_player(t_player *player)
{
	player->pov = 0;
	player->x = 0;
	player->y = 0;
}

t_player	find_player(char **map) {
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

void		cast_ray(t_global *global)
{
	t_player ray;

	ray = global->player;
	while (global->config.map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] !=
	'1')
	{
		ray.x += cos(ray.pov);
		ray.y += sin(ray.pov);
		mlx_pixel_put(global->window.mlx, global->window.window, ray.x, ray.y,
				0x990099);
	}
}

void		draw_window(t_global *global)
{
	t_point point;

	point.y = 0;
	while(global->config.map[point.y])
	{
		point.x = 0;
		while (global->config.map[point.y][point.x])
		{
			if (global->config.map[point.y][point.x] == '1')
				scale_pixel(&global->window, point, 0x20B2AA);
			point.x++;
		}
		point.y++;
	}
	scale_player(&global->window, global->player, 0xF08080);
	cast_ray(global);
}

int			key_hook(int keycode, t_global *global)
{
	ft_putstr_fd("Pressed key is ", 1);
	ft_putnbr_fd(keycode,1);
	ft_putchar_fd('\n', 1);

	float step;

	step = 0.2;
	step *= (keycode == 13 || keycode == 2 || keycode == 123) ? -1 : 1;
	if (keycode == 13 || keycode == 1)
	{
		global->player.x += cos(global->player.pov) * step;
		global->player.y += sin(global->player.pov) * step;
	}
	else if (keycode == 0 || keycode == 2)
	{
		global->player.x += cos(global->player.pov + M_PI_2) * step;
		global->player.y += sin(global->player.pov + M_PI_2) * step;
	}
	else if (keycode == 123 || keycode == 124)
	{
		global->player.pov += step;
	}else
		return (-1);
	mlx_clear_window(global->window.mlx, global->window.window);
	draw_window(global);
	return (1);
}


int			main(int argc, char **argv)
{
	t_global global;

	if (argc == 2)
	{
		global.config = parser(argv[1]);
		global.player = find_player(global.config.map);
		global.window.mlx = mlx_init();
		global.window.window = mlx_new_window(global.window.mlx,\
			global.config.res_x, global.config.res_y, "Cub3d Map");
		draw_window(&global);
		mlx_key_hook(global.window.window, key_hook, &global);
		mlx_loop(global.window.mlx);
	}
}
