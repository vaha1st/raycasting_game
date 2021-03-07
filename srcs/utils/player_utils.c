/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:17:42 by masharla          #+#    #+#             */
/*   Updated: 2021/03/07 02:32:04 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/utils.h"

void		init_player(t_player *player)
{
	player->pov = 0;
	player->x = 0;
	player->y = 0;
	player->dist = 100000;
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
	t_player	player;
	int			x;
	int			y;

	y = -1;
	init_player(&player);
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_isinset(map[y][x], "SNWE"))
			{
				if (!player.x && !player.y)
				{
					player.x = x + 0.5;
					player.y = y + 0.5;
					player.pov = get_pov_angle(map[y][x]);
				}
				else
					ft_putstr_fd("Error: Not a single player", 1);
			}
		}
	}
	return (player);
}
