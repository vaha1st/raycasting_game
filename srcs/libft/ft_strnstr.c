/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:15:22 by masharla          #+#    #+#             */
/*   Updated: 2020/11/05 00:32:11 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t n;

	if (needle[0] == 0)
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		n = 0;
		if (haystack[i] == needle[0])
		{
			while (i + n < len && haystack[i + n] == needle[n])
			{
				if (!needle[++n])
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (0);
}
