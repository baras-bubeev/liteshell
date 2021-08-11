/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:55:55 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/16 14:11:33 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;
	size_t	j;

	len = ft_strlen(s1);
	s2 = (char *)ft_calloc((len + 1), sizeof(char));
	// if ((s2 = (char *)malloc(len + 1)) == 0)
	// 	return (NULL);
	j = 0;
	while (len > j)
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}
