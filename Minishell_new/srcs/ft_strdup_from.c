/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_from.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 20:43:52 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/21 06:59:59 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strdup_from(const char *s1, int start)
{
	char	*s2;
	size_t	len;
	size_t	j;

	len = ft_strlen(s1) - start;
	s2 = (char *)ft_calloc((len + 1), sizeof(char));
	// if ((s2 = (char *)malloc(len + 1)) == 0)
	// 	return (NULL);
	j = 0;
	while (len > j)
	{
		s2[j] = s1[j + start];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}

char	*ft_strdup_len(const char *s1, int len)
{
	char	*s2;
	size_t	j;

	s2 = (char *)ft_calloc((len + 1), sizeof(char));
	j = 0;
	while (len > j)
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}