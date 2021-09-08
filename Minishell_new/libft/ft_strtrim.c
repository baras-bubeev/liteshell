/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:32:38 by jkorey            #+#    #+#             */
/*   Updated: 2020/11/13 22:47:33 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	begin(char const *s1, char const *set)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s1[i] && set[j])
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	return (i);
}

size_t	end(char const *s1, char const *set)
{
	size_t i;
	size_t j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (i > 0 && set[j])
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i--;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	a;

	if (!s1 || !set)
		return (0);
	a = ft_strlen(s1);
	i = begin(s1, set);
	if (a == 0 || a == i)
		return (ft_strdup(""));
	a = 0;
	j = end(s1, set);
	new = ft_substr(s1, i, j - i + 1);
	return (new);
}
