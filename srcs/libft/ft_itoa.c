/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 23:07:45 by masharla          #+#    #+#             */
/*   Updated: 2021/01/09 17:38:15 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long int num)
{
	int count;

	count = 0;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static int	what_sign(long int *num)
{
	if (*num < 0)
	{
		*num *= -1L;
		return (-1);
	}
	return (1);
}

char		*ft_itoa(long int n)
{
	long int	num;
	long int	i;
	int			sign;
	int			len;
	char		*s;

	num = n;
	sign = what_sign(&num);
	i = 0;
	len = count_digits(num);
	len += (sign < 0 ? 1 : 0);
	if (num == 0)
		len = 1;
	if (!(s = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	ft_memset(s, 48, len);
	s[len--] = '\0';
	while (len >= 0)
	{
		s[len--] = num % 10 + 48;
		num /= 10;
	}
	if (sign < 0)
		s[0] = '-';
	return (s);
}
