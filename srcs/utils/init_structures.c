/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:33:06 by masharla          #+#    #+#             */
/*   Updated: 2021/03/18 13:19:47 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		init_window(t_global *global)
{
	int	res_x;
	int res_y;

	mlx_get_screen_size(&res_x, &res_y);
	if (global->config->res_x > res_x)
		global->config->res_x = res_x;
	if (global->config->res_y > res_y)
		global->config->res_y = res_y - 54;
	global->window.window = mlx_new_window(global->window.mlx,\
			global->config->res_x, global->config->res_y, "Cub3d");
	global->window.bit_per_pixel = BPP;
	global->window.line_len = L_LEN;
	global->window.endian = 0;
	global->window.image = NULL;
	global->window.address = NULL;
}

void		init_buttons(t_global *global)
{
	global->a_btn = 0;
	global->w_btn = 0;
	global->s_btn = 0;
	global->d_btn = 0;
	global->right_btn = 0;
	global->left_btn = 0;
}

void		init_texture(t_tex *tex)
{
	tex->img = NULL;
	tex->addr = NULL;
	tex->width = 0;
	tex->height = 0;
	tex->y = 0;
	tex->x = 0;
	tex->l_len = 0;
	tex->bpp = 0;
	tex->end = 0;
	tex->reverse = 0;
}

void		init_player(t_player *player)
{
	player->pov = 0;
	player->x = -1;
	player->y = -1;
	player->dist = 0;
	player->y_of = 0;
	player->x_of = 0;
	player->size = 0;
}
