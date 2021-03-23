/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:01:55 by masharla          #+#    #+#             */
/*   Updated: 2021/03/23 17:03:45 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/utils.h"

void		count_sprites(t_global *global)
{
	int i;
	int j;
	int count;

	i = (global->plr.y - DOF > 0) ? global->plr.y - DOF : 0;
	count = 0;
	while (global->config->map[i] && i < global->plr.y + DOF)
	{
		j = (global->plr.x - DOF > 0) ? global->plr.x - DOF : 0;
		while (global->config->map[i][j] && j < global->plr.x + DOF)
		{
			if (global->config->map[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	global->count_sprt = count;
}

static void	q_sort_spr(t_player *sprs, int first, int last)
{
	int			left;
	int			right;
	float		middle;
	t_player	tmp;

	left = first;
	right = last;
	middle = sprs[(left + right) / 2].dist;
	if (first >= last)
		return ;
	while (left <= right)
	{
		while (sprs[left].dist > middle)
			left++;
		while (sprs[right].dist < middle)
			right--;
		if (left <= right)
		{
			tmp = sprs[left];
			sprs[left++] = sprs[right];
			sprs[right--] = tmp;
		}
	}
	q_sort_spr(sprs, first, right);
	q_sort_spr(sprs, left, last);
}

static void	draw_stripe(t_global *glob, t_player sprite, int i)
{
	int		top;
	int		bottom;
	float	step;
	int		color;

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
	float correction;

	spr->x = pnt.x + 0.5;
	spr->y = pnt.y + 0.5;
	spr->dist = find_dist(glob->plr.x, glob->plr.y, spr->x, spr->y);
	spr->pov = atan2(spr->y - glob->plr.y, spr->x - glob->plr.x);
	while (spr->pov - glob->plr.pov > M_PI)
		spr->pov -= 2 * M_PI;
	while (spr->pov - glob->plr.pov < -M_PI)
		spr->pov += 2 * M_PI;
	correction = cos(spr->pov - glob->plr.pov);
	if (correction > 0.67)
		spr->dist *= cos(spr->pov - glob->plr.pov);
	spr->size = glob->config->res_y / spr->dist * glob->config->res_x /
		glob->config->res_y;
	spr->x_of = (spr->pov - glob->plr.pov) * glob->config->res_x /
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
	pnt.y = (glob->plr.y - DOF - 1 > 0) ? glob->plr.y - DOF - 1 : -1;
	while (glob->config->map[++pnt.y] && pnt.y < glob->plr.y + DOF)
	{
		pnt.x = (glob->plr.x - DOF - 1 > 0) ? glob->plr.x - DOF - 1 : -1;
		while (glob->config->map[pnt.y][++pnt.x] && pnt.x < glob->plr.x + DOF)
			if (glob->config->map[pnt.y][pnt.x] == '2')
				init_sprite(glob, &sprs[i++], pnt);
	}
	q_sort_spr(sprs, 0, glob->count_sprt - 1);
	i = -1;
	while (++i < glob->count_sprt)
	{
		j = -1;
		while (++j < sprs[i].size)
			if (sprs[i].x_of + j >= 0 && sprs[i].x_of + j < glob->config->res_x)
				if (dist_buf[(int)sprs[i].x_of + j] > sprs[i].dist\
					|| !dist_buf[(int)sprs[i].x_of + j])
					draw_stripe(glob, sprs[i], j);
	}
}
