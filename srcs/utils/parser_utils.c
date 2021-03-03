/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:32:02 by masharla          #+#    #+#             */
/*   Updated: 2021/02/27 19:02:54 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_is_map(char *str)
{
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

char	*ft_remove_spaces(char *str)
{
	int		count;
	char	*result;
	int		i;

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
	result[i] = '\0';
	return (result);
}

void	init_t_conf(t_conf *config)
{
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

void	clear_t_conf(t_conf *config)
{
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
