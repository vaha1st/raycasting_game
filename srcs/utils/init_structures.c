/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:33:06 by masharla          #+#    #+#             */
/*   Updated: 2021/03/09 11:45:40 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_window(t_global *global, int bbp, int l_len, int endian)
{
	global->window.mlx = mlx_init();
	global->window.window = mlx_new_window(global->window.mlx,\
			global->config->res_x, global->config->res_y, "Cub3d");
	global->window.bit_per_pixel = bbp;
	global->window.line_len = l_len;
	global->window.endian = endian;
	global->window.image = NULL;
	global->window.address = NULL;
}

void 		init_buttons(t_global *global)
{
	global->a_btn = 0;
	global->w_btn = 0;
	global->s_btn = 0;
	global->d_btn = 0;
	global->right_btn = 0;
	global->left_btn = 0;
}

void	init_t_conf(t_conf *config)
{
	config->res_x = 0;
	config->res_y = 0;
	config->map_len = 0;
	config->north = NULL;
	config->south = NULL;
	config->west = NULL;
	config->east = NULL;
	config->sprite = NULL;
	config->floor_c = NULL;
	config->ceilling_c = NULL;
}

void		init_player(t_player *player)
{
	player->pov = 0;
	player->x = 0;
	player->y = 0;
	player->dist = 100000;
}
