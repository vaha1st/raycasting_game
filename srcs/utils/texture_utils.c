/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:44:47 by masharla          #+#    #+#             */
/*   Updated: 2021/03/17 22:13:14 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/utils.h"

void			clear_textures(t_global *global)
{
	mlx_destroy_image(global->window.mlx, global->north.img);
	mlx_destroy_image(global->window.mlx, global->south.img);
	mlx_destroy_image(global->window.mlx, global->east.img);
	mlx_destroy_image(global->window.mlx, global->west.img);
	mlx_destroy_image(global->window.mlx, global->sprite.img);
}

static t_tex	new_texture(t_window *win, char *file)
{
	t_tex	tex;

	init_texture(&tex);
	tex.img = mlx_xpm_file_to_image(win->mlx, file, &tex.width, &tex.height);
	if (tex.img != NULL)
		tex.addr = mlx_get_data_addr(tex.img, &tex.bpp, &tex.l_len, &tex.end);
	return (tex);
}

void			init_textures(t_global *global)
{
	global->window.mlx = mlx_init();
	global->north = new_texture(&global->window, global->config->north);
	global->south = new_texture(&global->window, global->config->south);
	global->west = new_texture(&global->window, global->config->west);
	global->east = new_texture(&global->window, global->config->east);
	global->sprite = new_texture(&global->window, global->config->sprite);
	if (global->north.img == NULL || global->south.img == NULL\
		|| global->west.img == NULL || global->east.img == NULL\
		|| global->sprite.img == NULL)
		clean_exit(global->config, 4);
	global->south.reverse = 1;
	global->west.reverse = 1;
}
