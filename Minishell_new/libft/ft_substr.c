/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:04:11 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/16 14:14:22 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*sub;

	if (!s)
		return (0);
	i = 0;
	len_s = ft_strlen((const char *)s);
	sub = (char *)ft_calloc((len + 1), sizeof(char));
	// if (!(sub = (char *)malloc(sizeof(char) * (len + 1))))
	// 	return (NULL);
	while (len_s >= start && s[start] && len > 0)
	{
		sub[i++] = s[start++];
		--len;
	}
	sub[i] = '\0';
	return (sub);
}
