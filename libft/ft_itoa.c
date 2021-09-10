/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:10:20 by jkorey            #+#    #+#             */
/*   Updated: 2020/11/11 19:20:51 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lenint(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	ft_putnbr(int n, char str)
{
	if (n < 0)
		n = n * -1;
	str = n + 48;
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_lenint(n);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	len = len - 1;
	while (len >= 0 && str[len] != '-')
	{
		str[len] = ft_putnbr(n % 10, *str + len);
		len--;
		n = n / 10;
	}
	return (str);
}
