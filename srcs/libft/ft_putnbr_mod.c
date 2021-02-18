/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:20:03 by masharla          #+#    #+#             */
/*   Updated: 2021/01/10 01:07:58 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_mod(long int n, int fd)
{
	long int	nbr;
	int			i;

	nbr = n;
	i = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
		i++;
	}
	if (nbr >= 10)
	{
		i += ft_putnbr_mod(nbr / 10, fd);
		i += ft_putnbr_mod(nbr % 10, fd);
	}
	else
	{
		ft_putchar_fd(nbr + 48, fd);
		i++;
	}
	return (i);
}
