/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:29:29 by masharla          #+#    #+#             */
/*   Updated: 2020/11/23 16:58:28 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t srcsize;

	i = 0;
	if (!src)
		return (0);
	srcsize = ft_strlen(src);
	if (dstsize != 0)
	{
		while (i < srcsize && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (srcsize);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t slen;
	size_t dlen;

	i = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if (dstsize < dlen + 1)
		return (dstsize + slen);
	while (i < dstsize - dlen - 1 && src[i])
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

char	*ft_strdup(const char *s1)
{
	char *p;

	p = (char *)malloc(ft_strlen(s1) + 1);
	if (p)
	{
		ft_strlcpy(p, s1, ft_strlen(s1) + 1);
		return (p);
	}
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
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
