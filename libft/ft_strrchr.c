/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:44:39 by jkorey            #+#    #+#             */
/*   Updated: 2020/11/06 14:25:41 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (s[i])
	{
		if (s[i] == c)
		{
			j = i;
			i++;
		}
		else
			i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	if (j < 0)
		return (NULL);
	else
		return ((char *)&s[j]);
}
