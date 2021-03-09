/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:44:47 by masharla          #+#    #+#             */
/*   Updated: 2021/03/09 11:44:48 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_tex		new_texture(t_window *win, char *file)
{
	t_tex	tex;

	tex.img = mlx_xpm_file_to_image(win->mlx, file, &tex.width, &tex.height);
	tex.addr = mlx_get_data_addr(tex.img, &tex.bpp, &tex.l_len, &tex.endian);
	return (tex);
}

void		init_textures(t_global *global)
{
	global->north = new_texture(&global->window, global->config->north);
	global->south = new_texture(&global->window, global->config->south);
	global->west = new_texture(&global->window, global->config->west);
	global->east = new_texture(&global->window, global->config->east);
}
