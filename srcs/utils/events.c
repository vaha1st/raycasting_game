/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:18:52 by masharla          #+#    #+#             */
/*   Updated: 2021/03/09 11:31:11 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/utils.h"

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
	player->pov = adjust_ray_angle(player->pov);
}

int			button_pressed(int keycode, t_global *global)
{
	if (keycode == 13)
		global->w_btn = 1;
	if (keycode == 1)
		global->s_btn = 1;
	if (keycode == 0)
		global->a_btn = 1;
	if (keycode == 2)
		global->d_btn = 1;
	if (keycode == 123)
		global->left_btn = 1;
	if (keycode == 124)
		global->right_btn = 1;
	return (1);
}

int			button_released(int keycode, t_global *global)
{
	if (keycode == 13)
		global->w_btn = 0;
	if (keycode == 1)
		global->s_btn = 0;
	if (keycode == 0)
		global->a_btn = 0;
	if (keycode == 2)
		global->d_btn = 0;
	if (keycode == 123)
		global->left_btn = 0;
	if (keycode == 124)
		global->right_btn = 0;
	return (1);
}

int			move_player(t_global *global)
{
	float step;

	step = 0.03;
	if (global->w_btn || global->s_btn)
	{
		make_a_step(&global->player, global->config->map,\
			(global->w_btn ? step : -step), global->player.pov);
	}
	if (global->a_btn || global->d_btn)
	{
		make_a_step(&global->player, global->config->map,\
			(global->d_btn ? step : -step),global->player.pov + M_PI_2);
	}
	if (global->left_btn || global->right_btn)
		make_a_turn(&global->player, (global->right_btn ? step : -step));
	generate_image(global, draw_floor_ceiling, 0, 0);
	draw_above_image(global, draw_player_view, 0, 0);
	draw_above_image(global, draw_minimap, 0, 0);
	return (1);
}
