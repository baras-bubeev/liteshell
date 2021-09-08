/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:34:38 by jkorey            #+#    #+#             */
/*   Updated: 2020/11/13 21:10:35 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_digit(int n, int fd)
{
	char	str;

	str = n + 48;
	write(fd, &str, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int nbr;

	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = (unsigned int)n * -1;
	}
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_digit(nbr % 10, fd);
}
