/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:31:03 by masharla          #+#    #+#             */
/*   Updated: 2021/02/19 19:18:55 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "includes/parser.h"

int	main(int argc, char **argv)
{
	t_conf *config;

	if (argc == 2)
		config = parser("/Users/ruslan/Documents/cub3d/srcs/map1.cub");
	clear_t_conf(config);
	while (config && argv[1])
		;
}
