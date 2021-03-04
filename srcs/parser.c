/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:37:07 by masharla          #+#    #+#             */
/*   Updated: 2021/03/04 14:05:51 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

char	**make_map(t_list **root, int size)
{
	char	**map;
	int		i;
	t_list	*tmp;

	map = ft_calloc(size + 1, sizeof(char *));
	i = 0;
	tmp = *root;
	while (tmp)
	{
//		map[i++] = ft_remove_spaces(tmp->content);
		map[i++] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	map[i] = NULL;
	return (map);
}

void	parse_resolution(char *str, t_conf *config)
{
	if (*str == 'R')
	{
		while (!ft_isdigit(*str))
			str++;
		config->res_x = ft_atoi(str);
		str = str + ft_diglen(config->res_x);
		while (!ft_isdigit(*str))
			str++;
		config->res_y = ft_atoi(str);
	}
}

void	parse_textures(t_list *list, t_conf *config)
{
	int		i;
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		i = 0;
		while (!ft_isalpha(((char *)(tmp->content))[i]))
			i++;
		if (!ft_strncmp(&(tmp->content[i]), "NO ", 3))
			config->north = ft_strdup(&(tmp->content[i + 3]));
		else if (!ft_strncmp(&(tmp->content[i]), "SO ", 3))
			config->south = ft_strdup(&(tmp->content[i + 3]));
		else if (!ft_strncmp(&(tmp->content[i]), "WE ", 3))
			config->west = ft_strdup(&(tmp->content[i + 3]));
		else if (!ft_strncmp(&(tmp->content[i]), "EA ", 3))
			config->east = ft_strdup(&(tmp->content[i + 3]));
		else if (!ft_strncmp(&(tmp->content[i]), "S ", 2))
			config->sprite = ft_strdup(&(tmp->content[i + 2]));
		else if (!ft_strncmp(&(tmp->content[i]), "F ", 2))
			config->floor_c = ft_strdup(&(tmp->content[i + 2]));
		else if (!ft_strncmp(&(tmp->content[i]), "C ", 2))
			config->ceilling_c = ft_strdup(&(tmp->content[i + 2]));
		tmp = tmp->next;
	}
}

int		parse_conf(t_conf *config, t_list *list)
{
	t_list *tmp;
	t_list *map;
	t_list *conf;

	map = NULL;
	conf = NULL;
	tmp = list;
	while (tmp)
	{
		if (ft_is_map(tmp->content) > 0)
			ft_list_push_back(&map, tmp->content);
		else if (!ft_is_map(tmp->content))
			ft_list_push_back(&conf, tmp->content);
		tmp = tmp->next;
	}
	parse_resolution(conf->content, config);
	parse_textures(conf, config);
	config->map = make_map(&map, ft_lstsize(map));
	ft_lstclear_save_content(&map);
	ft_lstclear_save_content(&conf);
	if (!config->res_x || !config->res_y || !config->north || !config->south\
		|| !config->north || !config->west || !config->east || !config->sprite\
		|| !config->floor_c || !config->ceilling_c || !check_map(config->map))
		return (-1);
	return (1);
}

t_conf	*parser(char *configuration_file)
{
	char	*line;
	t_list	*root;
	t_conf	*config;
	int		fd;

	line = NULL;
	root = NULL;
	// file open exception
	fd = open(configuration_file, O_RDONLY);
	config = calloc(1, sizeof(t_conf));
	init_t_conf(config);
	while (get_next_line(fd, &line))
		ft_list_push_back(&root, line);
	ft_list_push_back(&root, line);
	if (parse_conf(config, root) < 0)
		ft_putstr_fd("Config failed!\n", 1);
	ft_lstclear(&root, free);
	close(fd);
	return (config);
}
