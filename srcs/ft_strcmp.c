/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:18:59 by jkorey            #+#    #+#             */
/*   Updated: 2021/09/11 01:04:54 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;
	int		len1;
	int		len2;
	int		max_len;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 >= len2)
		max_len = len1;
	else
		max_len = len2;
	while (i < max_len)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
