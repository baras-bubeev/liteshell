/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:18:40 by jkorey            #+#    #+#             */
/*   Updated: 2020/11/13 21:28:35 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;
	size_t	j;

	len_needle = ft_strlen(needle);
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while ((haystack[j]) && j + len_needle < len + 1)
	{
		if (haystack[j] == needle[0])
		{
			if (!(ft_strncmp(haystack + j, needle, len_needle)))
				return (&((char *)haystack)[j]);
		}
		j++;
	}
	return (NULL);
}
