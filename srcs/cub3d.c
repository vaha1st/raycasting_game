/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:31:03 by masharla          #+#    #+#             */
/*   Updated: 2021/03/19 16:28:55 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/utils.h"

static int	check_args(int ac, char **av)
{
	size_t	len;
	int		res;

	res = 0;
	if (ac > 1 && ac < 4)
	{
		len = ft_strlen(av[1]);
		if (len >= 4 && av[1][len - 1] == 'b' && av[1][len - 2] == 'u'\
			&& av[1][len - 3] == 'c' && av[1][len - 4] == '.')
			res = 1;
		if (res && av[2] && !ft_strncmp(av[2], "--save", 7))
			res = 2;
		else if (res && av[2] && ft_strncmp(av[2], "--save", 7))
			res = 0;
	}
	return (res);
}

static void	game_loop(t_global *global)
{
	mlx_hook(global->window.window, 17, 1L << 2, window_exit, global);
	mlx_hook(global->window.window, 2, 1L << 0, button_pressed, global);
	mlx_hook(global->window.window, 3, 1L << 1, button_released, global);
	mlx_loop_hook(global->window.mlx, move_player, global);
	mlx_loop(global->window.mlx);
}

int			main(int argc, char **argv)
{
	t_global	global;
	int			args;

	args = check_args(argc, argv);
	if (args)
	{
		init_buttons(&global);
		global.config = parser(argv[1]);
		global.plr = find_player(global.config);
		init_textures(&global);
		if (args == 2)
			make_screenshot(&global);
		init_window(&global);
		generate_image(&global, draw_floor_ceiling, 0, 0);
		draw_above_image(&global, draw_player_view, 0, 0);
		draw_above_image(&global, draw_minimap, 0, 0);
		game_loop(&global);
		clear_t_conf(global.config);
		clear_textures(&global);
	}
	else
		clean_exit(global.config, 1);
}
