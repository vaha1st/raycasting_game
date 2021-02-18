/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:29:32 by masharla          #+#    #+#             */
/*   Updated: 2020/11/05 00:32:11 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_front(t_list **begin_list, void *data)
{
	t_list	*begin;

	if (!begin_list || !data)
		return ;
	if (*begin_list)
	{
		begin = ft_lstnew(data);
		begin->next = *begin_list;
		*begin_list = begin;
	}
	else
		*begin_list = ft_lstnew(data);
}
