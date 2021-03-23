/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:37:07 by masharla          #+#    #+#             */
/*   Updated: 2021/03/20 21:53:16 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static char		**make_map(t_list **root, t_conf *config)
{
	char	**map;
	int		i;
	t_list	*tmp;

	config->map_len = ft_lstsize(*root);
	if (!(map = ft_calloc(config->map_len + 1, sizeof(char *))))
		return (NULL);
	i = 0;
	tmp = *root;
	while (tmp)
	{
		if (!(map[i++] = ft_strdup(tmp->content)))
			break ;
		tmp = tmp->next;
	}
	map[i] = NULL;
	return (map);
}

static void		parse_resolution(char *str, t_conf *config)
{
	while (ft_isspace(*str))
		str++;
	if (*str == 'R')
	{
		str++;
		while (ft_isspace(*str))
			str++;
		config->res_x = ft_atoi(str);
		str = str + ft_diglen(config->res_x);
		while (ft_isspace(*str))
			str++;
		config->res_y = ft_atoi(str);
		str = str + ft_diglen(config->res_y);
		while (ft_isspace(*str))
			str++;
		if (*str != '\0')
			clean_exit(config, 5);
	}
}

static void		parse_textures(t_list *list, t_conf *config, int i)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (!ft_strncmp(&(tmp->content[i = spcs_end(tmp->content)]), "R ", 2))
			parse_resolution(tmp->content, config);
		else if (!ft_strncmp(&(tmp->content[i]), "NO ", 3) && !config->north)
			config->north = ft_strtrim(&(tmp->content[i + 3]), " \t");
		else if (!ft_strncmp(&(tmp->content[i]), "SO ", 3) && !config->south)
			config->south = ft_strtrim(&(tmp->content[i + 3]), " \t");
		else if (!ft_strncmp(&(tmp->content[i]), "WE ", 3) && !config->west)
			config->west = ft_strtrim(&(tmp->content[i + 3]), " \t");
		else if (!ft_strncmp(&(tmp->content[i]), "EA ", 3) && !config->east)
			config->east = ft_strtrim(&(tmp->content[i + 3]), " \t");
		else if (!ft_strncmp(&(tmp->content[i]), "S ", 2) && !config->sprite)
			config->sprite = ft_strtrim(&(tmp->content[i + 2]), " \t");
		else if (!ft_strncmp(&(tmp->content[i]), "F ", 2) && !config->floor_c)
			config->floor_c = ft_remove_spaces(&(tmp->content[i + 2]));
		else if (!ft_strncmp(&(tmp->content[i]), "C ", 2) && !config->ceiling_c)
			config->ceiling_c = ft_remove_spaces(&(tmp->content[i + 2]));
		else if (((char *)tmp->content)[i] != '\0')
			clean_exit(config, 4);
		tmp = tmp->next;
	}
}

static int		parse_conf(t_conf *cfg, t_list *list)
{
	t_list	*tmp;
	t_list	*map;
	t_list	*conf;
	int		i;

	map = NULL;
	conf = NULL;
	tmp = list;
	while (tmp)
	{
		if (ft_is_map(tmp->content) > 0)
			ft_list_push_back(&map, tmp->content);
		else if (!ft_is_map(tmp->content) && !map)
			ft_list_push_back(&conf, tmp->content);
		else if (map && ft_is_map(tmp->content) < 0)
			break ;
		tmp = tmp->next;
	}
	parse_textures(conf, cfg, i);
	cfg->map = make_map(&map, cfg);
	ft_lstclear_save_content(&map);
	ft_lstclear_save_content(&conf);
	return (check_config(cfg, check_map(cfg->map)));
}

t_conf			*parser(char *configuration_file)
{
	char	*line;
	t_list	*root;
	t_conf	*config;
	int		fd;
	int		gnl;

	line = NULL;
	root = NULL;
	if ((fd = open(configuration_file, O_RDONLY)) < 0)
		clean_exit(config, 1);
	if (!(config = ft_calloc(1, sizeof(t_conf))))
		clean_exit(config, 2);
	while ((gnl = get_next_line(fd, &line)) > 0)
		ft_list_push_back(&root, line);
	if (gnl < 0)
	{
		ft_lstclear(&root, free);
		clean_exit(config, 3);
	}
	ft_list_push_back(&root, line);
	if (parse_conf(config, root) < 0)
		clean_exit(config, 4);
	ft_lstclear(&root, free);
	close(fd);
	return (config);
}
