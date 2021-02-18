/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:00:54 by masharla          #+#    #+#             */
/*   Updated: 2020/11/05 00:32:11 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	len;
	size_t	start;
	size_t	size;

	if (s1 == 0 || set == 0)
		return (0);
	len = ft_strlen(s1) - 1;
	start = 0;
	while (start < len)
		if (is_in_set(s1[start], set) == 1)
			start++;
		else
			break ;
	while (len)
		if (is_in_set(s1[len], set) == 1)
			len--;
		else
			break ;
	size = (len < start ? 0 : len - start + 1);
	p = ft_substr(s1, start, size);
	return (p);
}
