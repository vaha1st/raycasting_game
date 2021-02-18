/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:34:03 by masharla          #+#    #+#             */
/*   Updated: 2020/11/05 00:32:11 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*tmp;
	t_list	*back;

	if (!begin_list || !data)
		return ;
	tmp = *begin_list;
	if (*begin_list)
		while (tmp->next)
			tmp = tmp->next;
	if (tmp)
	{
		back = ft_lstnew(data);
		tmp->next = back;
		back->next = NULL;
	}
	else
		*begin_list = ft_lstnew(data);
}
