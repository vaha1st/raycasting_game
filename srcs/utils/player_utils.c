/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:17:42 by masharla          #+#    #+#             */
/*   Updated: 2021/03/17 00:44:57 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/utils.h"

float			adjust_angle(float angle)
{
	if (angle < 0)
		return (angle + 2 * M_PI);
	if (angle > 2 * M_PI)
		return (angle - 2 * M_PI);
	return (angle);
}

static float	get_pov_angle(char pov)
{
	if (pov == 'N')
		return (-2.89661407);
	else if (pov == 'S')
		return (M_PI_2);
	else if (pov == 'W')
		return (M_PI);
	else
		return (0);
}

t_player		find_player(t_conf *conf)
{
	t_player	player;
	int			x;
	int			y;

	y = -1;
	init_player(&player);
	while (conf->map[++y])
	{
		x = -1;
		while (conf->map[y][++x])
			if (ft_isinset(conf->map[y][x], "SNWE"))
			{
				if (player.x < 0 && player.y < 0)
				{
					player.x = x + 0.5;
					player.y = y + 0.5;
					player.pov = get_pov_angle(conf->map[y][x]);
				}
				else
					clean_exit(conf, 6);
			}
	}
	if (player.x < 0 || player.y < 0)
		clean_exit(conf, 6);
	return (player);
}
