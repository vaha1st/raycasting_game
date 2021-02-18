/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:58:23 by masharla          #+#    #+#             */
/*   Updated: 2020/12/24 17:15:14 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isinset(char c, char *str)
{
	if (!c || !str)
		return (-1);
	while (*str)
	{
		if (c == *str++)
			return (1);
	}
	return (0);
}