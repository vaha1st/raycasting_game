/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:20:43 by masharla          #+#    #+#             */
/*   Updated: 2020/11/05 00:32:11 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	size_t			i;

	temp1 = (unsigned char *)dst;
	temp2 = (unsigned char *)src;
	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (dst < src)
	{
		while (i < len)
		{
			temp1[i] = temp2[i];
			i++;
		}
	}
	else
	{
		while (len--)
			temp1[len] = temp2[len];
	}
	return (dst);
}
