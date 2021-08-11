/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:36:29 by mpowder           #+#    #+#             */
/*   Updated: 2020/11/04 20:58:22 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	if (!s)
		return (0);
	p = (char *)malloc(len + 1);
	if (start >= ft_strlen(s))
	{
		*p = '\0';
		return (p);
	}
	if (!p)
		return (0);
	while (i < len)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}
