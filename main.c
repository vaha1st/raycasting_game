/*
 * ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:52:32 by masharla          #+#    #+#             */
/*   Updated: 2021/02/14 18:36:30 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "includes/cub3d.h"

int ft_is_map(char *str) {
	while (*str == ' ')
		str++;
	if (*str == '\0')
		return (-1);
	if (ft_isdigit(*str))
		return (1);
	return (0);
}

void	ft_lstclear_save_content(t_list **lst)
{
	t_list *tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = tmp->next;
		free(tmp);
	}
}

char *ft_remove_spaces(char *str)
{
	int count;
	char *result;
	int i;

	count = 0;
	i = 0;
	while (str[i])
		if (ft_isalnum(str[i++]))
			count++;
	i = 0;
	result = ft_calloc(count + 1, sizeof(char));
	while (*str)
	{
		if (ft_isalnum(*str))
			result[i++] = *str;
		str++;
	}
	return (result);
}

char	**make_map(t_list **root, int size)
{
	char 	**map = ft_calloc(size + 1, sizeof(char *));
	int		i = 0;
	t_list	*tmp;

	tmp = *root;
	while (tmp)
	{
		map[i++] = ft_remove_spaces(tmp->content);
		tmp= tmp->next;
	}
	return (map);
}

void parse_resolution(char *str, t_conf *config)
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

void parse_textures(t_list *list, t_conf *config)
{
	int i;
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		i = 0;
		while (!ft_isalpha(((char *)(tmp->content))[i]))
			i++;
		if(!ft_strncmp(&(tmp->content[i]), "NO ", 3))
			config->north = ft_strdup(&(tmp->content[i + 3]));
		else if(!ft_strncmp(&(tmp->content[i]), "SO ", 3))
			config->south = ft_strdup(&(tmp->content[i + 3]));
		else if(!ft_strncmp(&(tmp->content[i]), "WE ", 3))
			config->west = ft_strdup(&(tmp->content[i + 3]));
		else if(!ft_strncmp(&(tmp->content[i]), "EA ", 3))
			config->east = ft_strdup(&(tmp->content[i + 3]));
		else if(!ft_strncmp(&(tmp->content[i]), "S ", 2))
			config->sprite = ft_strdup(&(tmp->content[i + 2]));
		else if(!ft_strncmp(&(tmp->content[i]), "F ", 2))
			config->floor_c = ft_strdup(&(tmp->content[i + 2]));
		else if(!ft_strncmp(&(tmp->content[i]), "C ", 2))
			config->ceilling_c = ft_strdup(&(tmp->content[i + 2]));
		tmp = tmp->next;
	}
}

void initialize_t_conf(t_conf *config){
	config->res_x = 0;
	config->res_y = 0;
	config->north = NULL;
	config->south = NULL;
	config->west = NULL;
	config->east = NULL;
	config->sprite = NULL;
	config->floor_c = NULL;
	config->ceilling_c = NULL;
}

void clear_t_conf(t_conf *config) {
	int i;

	i = 0;
	free(config->north);
	free(config->south);
	free(config->west);
	free(config->east);
	free(config->sprite);
	free(config->floor_c);
	free(config->ceilling_c);
	while ((config->map)[i])
		free((config->map)[i++]);
	free(config->map);
	free(config);
}

int parse_conf(t_conf *config, t_list *list){
	t_list *tmp;
	t_list *map;
	t_list *conf;

	map = NULL;
	conf = NULL;
	tmp = list;
	while (tmp) {
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
		|| !config->floor_c || !config->ceilling_c)
		return (-1);
	return (1);
}

int main()
{
	char *line = NULL;
	t_list *root;
	t_conf *config = calloc(1, sizeof(t_conf));
	initialize_t_conf(config);
	int fd = open("/Users/ruslan/Documents/cub3d/srcs/map1.cub", O_RDONLY);
	while (get_next_line(fd, &line))
		ft_list_push_back(&root, line);
	ft_list_push_back(&root, line);

	if (parse_conf(config, root) < 0)
		printf("Config failed!\n");

//	while (root) {
//		printf("%s\n", root->content);
//		root = root->next;
//	}

	ft_lstclear(&root, free);
	clear_t_conf(config);
	close(fd);

	while (1)
		;
}
