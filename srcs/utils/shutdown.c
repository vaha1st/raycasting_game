/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 13:23:03 by masharla          #+#    #+#             */
/*   Updated: 2021/03/19 18:33:05 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		clear_t_conf(t_conf *config)
{
	int i;

	i = 0;
	if (config->north)
		free(config->north);
	if (config->south)
		free(config->south);
	if (config->west)
		free(config->west);
	if (config->east)
		free(config->east);
	if (config->sprite)
		free(config->sprite);
	if (config->floor_c)
		free(config->floor_c);
	if (config->ceiling_c)
		free(config->ceiling_c);
	if (config->map)
	{
		while ((config->map)[i])
			free((config->map)[i++]);
		free(config->map);
	}
	free(config);
}

static void	additional_errors(t_conf *conf, int err_id)
{
	if (err_id == 6)
	{
		clear_t_conf(conf);
		ft_putstr_fd("Error\nInvalid plr placement", 2);
	}
	if (err_id == 7)
	{
		clear_t_conf(conf);
		ft_putstr_fd("Error\nCannot create bmp file", 2);
	}
	if (err_id == 8)
	{
		clear_t_conf(conf);
		ft_putstr_fd("Error\nNice try :) 15K limit", 2);
	}
}

void		clean_exit(t_conf *conf, int err_id)
{
	if (err_id > 5)
		additional_errors(conf, err_id);
	else if (err_id == 1)
		perror("Error\nInput arguments");
	else if (err_id == 2)
		perror("Error\nStruct malloc failure");
	else if (err_id == 3)
	{
		free(conf);
		ft_putstr_fd("Error\nGNL failure", 2);
	}
	else if (err_id == 4)
	{
		clear_t_conf(conf);
		ft_putstr_fd("Error\nConfiguration file parse failure", 2);
	}
	else if (err_id == 5)
	{
		clear_t_conf(conf);
		ft_putstr_fd("Error\nInvalid screen resolution", 2);
	}
	exit(err_id);
}
