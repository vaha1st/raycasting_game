/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:44:10 by masharla          #+#    #+#             */
/*   Updated: 2021/03/17 21:54:41 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/utils.h"

static void	find_ws_offset(t_player *player, float step)
{
	if (step > 0)
	{
		player->y_of = (player->pov > M_PI) ? -0.2 : 0.2;
		player->x_of = (player->pov > M_PI_2 && player->pov < M_PI_2 * 3) ?\
			-0.2 : 0.2;
	}
	else
	{
		player->y_of = (player->pov > M_PI) ? 0.2 : -0.2;
		player->x_of = (player->pov > M_PI_2 && player->pov < M_PI_2 * 3) ?\
			0.2 : -0.2;
	}
}

static void	find_ad_offset(t_player *player, float step)
{
	if (step > 0)
	{
		player->x_of = (player->pov > M_PI) ? 0.2 : -0.2;
		player->y_of = (player->pov > M_PI_2 && player->pov < M_PI_2 * 3) ?\
			-0.2 : 0.2;
	}
	else
	{
		player->x_of = (player->pov > M_PI) ? -0.2 : 0.2;
		player->y_of = (player->pov > M_PI_2 && player->pov < M_PI_2 * 3) ?\
			0.2 : -0.2;
	}
}

void		make_a_step(t_player *player, char **map, float step, float dir)
{
	if (dir == player->pov)
		find_ws_offset(player, step);
	else
		find_ad_offset(player, step);
	player->x += cos(dir) * step;
	player->y += sin(dir) * step;
	if (map[(int)(player->y + player->y_of)][(int)(player->x + player->x_of)]\
		== '1'\
		|| map[(int)(player->y + player->y_of / 5)]\
		[(int)(player->x + player->x_of / 5)] == '1')
	{
		player->x -= cos(dir) * step;
		player->y -= sin(dir) * step;
	}
}

void		make_a_turn(t_player *player, float step)
{
	player->pov += step;
	player->pov = adjust_angle(player->pov);
}
