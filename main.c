/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:31:03 by masharla          #+#    #+#             */
/*   Updated: 2021/02/24 23:00:30 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void			scale_pixel(t_window *window, t_point start, int color)
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

void			scale_player(t_window *window, t_player start, int color)
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

t_player find_player(char **map) {
	t_player player;
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_isinset(map[y][x], "SNWE"))
			{
				player.x = x;
				player.y = y;
				return (player);
			}
			x++;
		}
		y++;
	}
	return (player);
}

void	draw_window(t_global *global)
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
}

int	key_hook(int keycode, t_global *global)
{
	ft_putstr_fd("Pressed key is ", 1);
	ft_putnbr_fd(keycode,1);
	ft_putchar_fd('\n', 1);
	float step;

	step = 0.2;
	step *= (keycode == 1 || keycode == 2) ? -1 : 1;
	if (keycode == 13 || keycode == 1)
	{
		keycode = -1;
		global->player.y -= step;
		if (global->config.map[(int)round(global->player.y)][(int)round\
			(global->player.x)] == '1')
			global->player.y += step;
	}
	else if (keycode == 0 || keycode == 2)
	{
		keycode = -1;
		global->player.x -= step;
		if (global->config.map[(int)round(global->player.y)][(int)round\
			(global->player.x)] == '1')
			global->player.x += step;
	}
	if (keycode < 0)
	{
		mlx_clear_window(global->window.mlx, global->window.window);
		draw_window(global);
	}
}


int	main(int argc, char **argv)
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
