/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:29:00 by masharla          #+#    #+#             */
/*   Updated: 2020/11/16 15:36:16 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_next(char const *s, char c, size_t i)
{
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			return (i + 1);
		i++;
	}
	return (-1);
}

static size_t	find_length(char const *s, char c, size_t i)
{
	size_t count;

	count = 0;
	while (s[i] != c && s[i])
	{
		i++;
		count++;
	}
	return (count);
}

static int		count_substrings(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void		*free_array(char **arr)
{
	size_t i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	n;
	size_t	len;
	char	**arr;

	n = 0;
	len = 0;
	if (s == 0)
		return (0);
	i = (s[0] == c ? find_next(s, c, 0) : 0);
	if (!(arr = (char **)malloc((count_substrings(s, c) + 1) * sizeof(char *))))
		return (0);
	while (i < ft_strlen(s))
	{
		len = find_length(s, c, i);
		arr[n++] = ft_substr(s, i, len);
		if (!arr[n - 1])
		{
			free_array(arr);
			return (0);
		}
		i = find_next(s, c, i);
	}
	arr[n] = 0;
	return (arr);
}
