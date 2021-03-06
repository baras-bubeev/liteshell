/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concatenate_str_in_arr.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:46:00 by jkorey            #+#    #+#             */
/*   Updated: 2021/09/11 01:37:18 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_concatenate_str_in_arr(char **arr, int arr_size, char *str)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = NULL;
	while (++i < arr_size)
	{
		tmp = ft_strjoin(arr[i], str);
		if (arr[i])
			free(arr[i]);
		arr[i] = ft_strdup(tmp);
		free(tmp);
		tmp = NULL;
	}
}
