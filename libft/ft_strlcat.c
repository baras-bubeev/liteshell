/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:13:57 by jkorey            #+#    #+#             */
/*   Updated: 2020/11/05 20:47:53 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	len_dest;
	size_t	j;

	len_dest = ft_strlen(dest);
	if (len_dest < dstsize)
	{
		j = 0;
		while (src[j] != '\0' && len_dest < dstsize - 1)
		{
			dest[len_dest] = src[j];
			len_dest++;
			j++;
		}
		dest[len_dest] = '\0';
		return (ft_strlen(dest) + ft_strlen(&src[j]));
	}
	else
		return (ft_strlen(src) + dstsize);
}
