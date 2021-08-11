/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:06:45 by mpowder           #+#    #+#             */
/*   Updated: 2020/11/02 15:56:22 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*p;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(size + 1);
	if (!p)
		return (0);
	while (j < ft_strlen(s1))
		p[i++] = s1[j++];
	j = 0;
	while (j < ft_strlen(s2))
		p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}
