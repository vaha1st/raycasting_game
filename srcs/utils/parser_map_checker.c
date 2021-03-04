/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:10:01 by masharla          #+#    #+#             */
/*   Updated: 2021/03/04 15:22:32 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int		check_element(char **map, int i, int j, int len)
{
	if (i == 0 || i == len || j >= ft_strlen(map[i - 1])\
		|| j >= ft_strlen(map[i + 1]))
		return (0);
	if (!map[i - 1][j - 1] || map[i - 1][j - 1] == ' ' || !map[i - 1][j + 1]\
		|| map[i - 1][j + 1] == ' ' || !map[i - 1][j] || map[i - 1][j] == ' '\
		|| !map[i][j - 1] || map[i][j - 1] == ' ' || !map[i][j + 1]\
		|| map[i][j + 1] == ' ' || !map[i + 1][j - 1]\
		|| map[i + 1][j - 1] == ' ' || !map[i + 1][j + 1]\
		|| map[i + 1][j + 1] == ' ' || !map[i + 1][j] || map[i + 1][j] == ' ')
		return (0);
	return (1);
}

int		check_map(char **map)
{
	int i;
	int j;
	int arr_len;

	i = 0;
	arr_len = -1;
	while (map[i++])
		arr_len++;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
				if (!check_element(map, i, j, arr_len))
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}
