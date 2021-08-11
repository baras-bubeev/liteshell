/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:39:11 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/16 07:57:19 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_count_char(char *str, char a)
{
	int		count_char;
	int		i;

	count_char = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			count_char++;
		i++;
	}
	return (count_char);
}