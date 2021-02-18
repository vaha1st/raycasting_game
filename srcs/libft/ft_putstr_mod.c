/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:09:19 by masharla          #+#    #+#             */
/*   Updated: 2021/01/07 15:49:37 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_mod(char *s, int fd)
{
	int	count;

	count = 0;
	if (s)
		while (*s)
			count += ft_putchar_mod(*s++, fd);
	return (count);
}
