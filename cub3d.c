/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:31:03 by masharla          #+#    #+#             */
/*   Updated: 2021/03/04 18:42:15 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "includes/utils.h"

void		make_a_step(t_player *player, char **map, float step, float dir)
{
	player->x += cos(dir) * step;
	player->y += sin(dir) * step;
	if (map[(int)player->y][(int)player->x] == '1')
	{
		player->x -= cos(dir) * step;
		player->y -= sin(dir) * step;
	}
}

void 		make_a_turn(t_player *player, float step)
{
	player->pov += step;
	if (player->pov < 0)
		player->pov += 2 * M_PI;
	if (player->pov > 2 * M_PI)
		player->pov -= 2 * M_PI;
}

int			key_hook(int keycode, t_global *global)
{
	float step;

	step = 0.13;
	step *= (keycode == 1 || keycode == 0 || keycode == 123) ? -1 : 1;
	if (keycode == 13 || keycode == 1)
	{
		make_a_step(&global->player, global->config->map, step,\
			global->player.pov);
	}
	else if (keycode == 0 || keycode == 2)
	{
		make_a_step(&global->player, global->config->map, step,\
			global->player.pov + M_PI_2);
	}
	else if (keycode == 123 || keycode == 124)
		make_a_turn(&global->player, step);
	else
		return (-1);
	generate_image(global, draw_player_view, 0, 0);
	draw_above_image(global, draw_minimap, 0, 0);
	return (1);
}

int			main(int argc, char **argv)
{
	t_global global;

	if (argc == 2)
	{
		global.config = parser(argv[1]);
		global.player = find_player(global.config->map);
		init_window(&global, 24, 24, 0);
		generate_image(&global, draw_player_view, 0, 0);
		draw_above_image(&global, draw_minimap, 0, 0);
		mlx_key_hook(global.window.window, key_hook, &global);
		mlx_loop(global.window.mlx);
	}
}
