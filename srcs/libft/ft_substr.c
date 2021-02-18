/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:24:10 by masharla          #+#    #+#             */
/*   Updated: 2020/11/22 21:12:26 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (s == 0)
		return (0);
	i = 0;
	if ((res = (char *)malloc(len + 1)))
	{
		if (start >= ft_strlen(s))
		{
			res[0] = '\0';
			return (res);
		}
		while (i < len && s[i])
		{
			res[i] = s[start + i];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (0);
}
