/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 02:39:49 by masharla          #+#    #+#             */
/*   Updated: 2021/03/17 22:06:54 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/utils.h"

static int	retrieve_color(char *color)
{
	int	r;
	int	g;
	int	b;
	int i;

	i = 0;
	r = 256;
	g = 256;
	b = 256;
	if (ft_isdigit(color[i]))
		r = ft_atoi(&color[i]);
	i += ft_diglen(r) + 1;
	if (ft_isdigit(color[i]))
		g = ft_atoi(&color[i]);
	i += ft_diglen(g) + 1;
	if (ft_isdigit(color[i]))
		b = ft_atoi(&color[i]);
	i += ft_diglen(b);
	if (color[i] != '\0' || r > 255 || g > 255 || b > 255)
		return (-1);
	return (r * 256 * 256 + g * 256 + b);
}

void		draw_floor_ceiling(t_global *global)
{
	int x;
	int y;
	int floor_color;
	int ceiling_color;

	floor_color = retrieve_color(global->config->floor_c);
	ceiling_color = retrieve_color(global->config->ceiling_c);
	if (floor_color < 0 || ceiling_color < 0)
		clean_exit(global->config, 4);
	y = 0;
	while (y < global->config->res_y / 2)
	{
		x = 0;
		while (x < global->config->res_x)
			my_mlx_pixel_put(global, x++, y, ceiling_color);
		y++;
	}
	while (y < global->config->res_y)
	{
		x = 0;
		while (x < global->config->res_x)
			my_mlx_pixel_put(global, x++, y, floor_color);
		y++;
	}
}
