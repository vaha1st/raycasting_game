/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:31:03 by masharla          #+#    #+#             */
/*   Updated: 2021/03/09 11:46:47 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "includes/utils.h"

int			main(int argc, char **argv)
{
	t_global global;

	if (argc == 2)
	{
		init_buttons(&global);
		global.config = parser(argv[1]);
		global.player = find_player(global.config->map);
		init_window(&global, 24, 24, 0);
		init_textures(&global);
		generate_image(&global, draw_floor_ceiling, 0, 0);
		draw_above_image(&global, draw_player_view, 0, 0);
		draw_above_image(&global, draw_minimap, 0, 0);
		mlx_hook(global.window.window, 2, 1L<<0, button_pressed, &global);
		mlx_hook(global.window.window, 3, 1L<<1, button_released, &global);
		mlx_loop_hook(global.window.mlx, move_player, &global);
		mlx_loop(global.window.mlx);
	}
}
