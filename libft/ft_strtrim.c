/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:18:23 by mpowder           #+#    #+#             */
/*   Updated: 2020/11/05 17:26:19 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	size;
	char	*p;

	i = 0;
	if (!s1 || !set)
		return (0);
	while (ft_check(*s1, set) && *s1)
		s1++;
	size = ft_strlen(s1);
	if (size)
		while (size > 0 && ft_check(s1[size - 1], set))
			size--;
	if (!(p = (char *)malloc(size + 1)))
		return (0);
	while (i < size)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
