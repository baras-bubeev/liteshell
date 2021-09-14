/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:39:11 by jkorey            #+#    #+#             */
/*   Updated: 2021/09/11 01:37:07 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_count_char(char *str, char a)
{
	int	count_char;
	int	i;

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
