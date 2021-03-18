/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:01:55 by masharla          #+#    #+#             */
/*   Updated: 2021/03/18 13:28:39 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/utils.h"

void		count_sprites(t_global *global)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (global->config->map[i])
	{
		j = 0;
		while (global->config->map[i][j])
		{
			if (global->config->map[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	global->count_sprt = count;
}

static void	sort_sprites(int num, t_player *sprs)
{
	int			i;
	int			j;
	t_player	tmp;

	i = 0;
	while (i < num - 1)
	{
		j = (num - 1);
		while (j > i)
		{
			if ((sprs)[j - 1].dist < (sprs)[j].dist)
			{
				tmp = (sprs)[j - 1];
				(sprs)[j - 1] = (sprs)[j];
				(sprs)[j] = tmp;
			}
			j--;
		}
		i++;
	}
}

static void	draw_stripe(t_global *glob, t_player sprite, int i)
{
	int		top;
	int		bottom;
	float	step;
	int 	color;

	step = glob->sprite.width / sprite.size;
	glob->sprite.x = i * step;
	glob->sprite.y = 0;
	top = glob->config->res_y / 2 - sprite.size / 2;
	if (top < 0)
	{
		glob->sprite.y -= top * step;
		top = 0;
	}
	bottom = glob->config->res_y / 2 + sprite.size / 2;
	if (bottom > glob->config->res_y)
		bottom = glob->config->res_y;
	while (top < bottom)
	{
		color = mlx_pixel_get(&glob->sprite, glob->sprite.x, glob->sprite.y);
		if (color)
			my_mlx_pixel_put(glob, sprite.x_of + i, top, color);
		top++;
		glob->sprite.y += step;
	}
}

static void	init_sprite(t_global *glob, t_player *spr, t_point pnt)
{
	spr->x = pnt.x + 0.5;
	spr->y = pnt.y + 0.5;
	spr->dist = find_dist(glob->player.x, glob->player.y, spr->x, spr->y);
	spr->pov = atan2(spr->y - glob->player.y, spr->x - glob->player.x);
	while (spr->pov - glob->player.pov > M_PI)
		spr->pov -= 2 * M_PI;
	while (spr->pov - glob->player.pov < -M_PI)
		spr->pov += 2 * M_PI;
	spr->size = glob->config->res_y / spr->dist * glob->config->res_x /
		glob->config->res_y;
	spr->x_of = (spr->pov - glob->player.pov) * glob->config->res_x /
		(FOV) + (glob->config->res_x / 2) - spr->size / 2;
	spr->y_of = glob->config->res_y / 2 - spr->size / 2;
}

void		draw_sprites(t_global *glob, float *dist_buf)
{
	t_player	sprs[glob->count_sprt];
	t_point		pnt;
	int			i;
	int			j;

	i = 0;
	pnt.y = -1;
	while (glob->count_sprt && glob->config->map[++pnt.y])
	{
		pnt.x = -1;
		while (glob->config->map[pnt.y][++pnt.x])
			if (glob->config->map[pnt.y][pnt.x] == '2')
				init_sprite(glob, &sprs[i++], pnt);
	}
	sort_sprites(glob->count_sprt, sprs);
	i = -1;
	while (++i < glob->count_sprt)
	{
		j = -1;
		while (++j < sprs[i].size)
			if (sprs[i].x_of + j >= 0 && sprs[i].x_of + j < glob->config->res_x)
				if (dist_buf[(int)sprs[i].x_of + j] / WALL_SCALE > sprs[i].dist)
					draw_stripe(glob, sprs[i], j);
	}
}
