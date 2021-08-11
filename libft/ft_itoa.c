/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:16:36 by mpowder           #+#    #+#             */
/*   Updated: 2021/06/27 00:58:29 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int		len;

	len = 1;
	if (n < 0)
		len++;
	while (n /= 10)
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*p;

	size = ft_numlen(n);
	p = (char *)malloc(size + 1);
	if (!p)
		return (0);
	p[size] = '\0';
	if (n >= 0)
	{
		while (size)
		{
			p[--size] = 48 + (n % 10);
			n /= 10;
		}
	}
	else
	{
		while (n)
		{
			p[--size] = 48 - (n % 10);
			n /= 10;
		}
		p[--size] = '-';
	}
	return (p);
}
