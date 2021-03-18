/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:32:02 by masharla          #+#    #+#             */
/*   Updated: 2021/03/14 00:38:52 by ruslan           ###   ########.fr       */
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
		if (ft_isalnumsign(str[i++]))
			count++;
	i = 0;
	result = ft_calloc(count + 1, sizeof(char));
	while (*str)
	{
		if (ft_isalnumsign(*str))
			result[i++] = *str;
		str++;
	}
	result[i] = '\0';
	return (result);
}

int		spcs_end(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !ft_isalpha(str[i]) && !ft_ispunct(str[i]))
		i++;
	return (i);
}
