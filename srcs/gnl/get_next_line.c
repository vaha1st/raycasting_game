/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:15:11 by masharla          #+#    #+#             */
/*   Updated: 2021/02/15 13:11:55 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strchr_mod(const char *s, int c)
{
	long	i;
	long	slen;

	i = 0;
	slen = ft_strlen(s);
	if (c == 0)
		return (-1);
	while (i < slen && s[i] != c)
		i++;
	if (i == slen)
		return (-2);
	else
		return (i);
}

static char	*ft_strjoin_mod(char *s1, char *s2)
{
	char	*p;
	size_t	len;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = (char *)malloc(len);
	if (p)
	{
		ft_strlcpy(p, s1, len);
		ft_strlcat(p, s2, len);
		free(s1);
		return (p);
	}
	free(s1);
	return (NULL);
}

static int	read_slice(int fd, char **rest)
{
	char		*buf;
	long int	rs;

	rs = BUFFER_SIZE;
	if (!*rest && !(*rest = ft_strdup("")))
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
	{
		free(*rest);
		return (-1);
	}
	while ((ft_strchr_mod(*rest, '\n')) < 0 &&\
		(rs = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rs] = '\0';
		if (!(*rest = ft_strjoin_mod(*rest, buf)))
		{
			free(buf);
			return (-1);
		}
	}
	free(buf);
	return (rs);
}

static int	split_off_line(char **dst, char **src)
{
	long int	i;
	char		*temp;

	if (!src)
		return (-1);
	i = ft_strchr_mod(*src, '\n');
	if (i >= 0)
	{
		*dst = ft_substr(*src, 0, i);
		temp = *src;
		*src = ft_substr(temp, i + 1, ft_strlen(temp) - i);
		free(temp);
		if (!dst || !src)
			return (-1);
	}
	else
	{
		if (!(*dst = ft_strdup(*src)))
			return (-1);
	}
	return (ft_strlen(*src));
}

int			get_next_line(int fd, char **line)
{
	static char	*rest;
	long int	rs;
	int			ss;

	if (fd < 0 || !line || BUFFER_SIZE <= 0\
		|| (rs = read_slice(fd, &rest)) < 0)
		return (-1);
	if ((ss = split_off_line(line, &rest)) < 0)
	{
		free(rest);
		return (-1);
	}
	if (*rest != '\n' && !rs)
	{
		free(rest);
		rest = NULL;
		return (0);
	}
	return (1);
}
