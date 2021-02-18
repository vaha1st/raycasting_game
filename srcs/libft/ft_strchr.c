/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:06:08 by masharla          #+#    #+#             */
/*   Updated: 2020/11/05 00:32:11 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	long	i;
	long	slen;

	i = 0;
	slen = ft_strlen(s);
	if (c == 0)
		return ((char *)&s[slen]);
	while (i < slen && s[i] != c)
		i++;
	if (i == slen)
		return (0);
	else
		return ((char *)&s[i]);
}
