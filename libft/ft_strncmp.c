/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:26:36 by mpowder           #+#    #+#             */
/*   Updated: 2020/11/02 15:56:36 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		rez;

	i = 0;
	rez = 0;
	while (rez == 0 && (s1[i] || s2[i]) && i < n)
	{
		rez = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (rez < 0)
			return (-1);
		if (rez > 0)
			return (1);
		i++;
	}
	return (rez);
}
