/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 02:39:49 by masharla          #+#    #+#             */
/*   Updated: 2021/03/07 16:22:33 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/utils.h"

void 	draw_floor_ceiling(t_global *global)
{
	int x;
	int y;

	y = 0;
	while (y < global->config->res_y / 2)
	{
		x = 0;
		while (x < global->config->res_x)
			my_mlx_pixel_put(&global->window, x++, y, 0x236999);
		y++;
	}
	while (y < global->config->res_y)
	{
		x = 0;
		while (x < global->config->res_x)
			my_mlx_pixel_put(&global->window, x++, y, 0xCF9B74);
		y++;
	}
}
