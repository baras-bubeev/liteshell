/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:29:28 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/16 14:09:00 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_words(char const *s, char c)
{
	size_t	i;
	char	*str;
	size_t	len_str;

	i = 0;
	len_str = ft_len(s, c);
	str = (char *)ft_calloc((len_str + 1),sizeof(char));
	// if (!(str = (char *)malloc(sizeof(char) * len_str + 1)))
		// return (NULL);
	while (len_str > 0)
	{
		str[i] = s[i];
		i++;
		--len_str;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_col_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	**ft_strings(size_t count_w, char **split, const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < count_w)
	{
		while (s[j] == c && s[j])
			j++;
		if (!(split[i] = ft_words(s + j, c)))
		{
			while (i - 1 > 0)
			{
				free(split[i]);
				i--;
			}
			return (0);
		}
		while (s[j] != c && s[j])
			j++;
		i++;
	}
	split[i] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	count_w;
	char	**split;

	if (!s)
		return (0);
	count_w = ft_col_words(s, c);
	split = (char **)ft_calloc((count_w + 1), (sizeof(split)));
	// if (!(split = (char **)malloc(sizeof(split) * (count_w + 1))))
	// 	return (NULL);
	split = ft_strings(count_w, split, s, c);
	return (split);
}
