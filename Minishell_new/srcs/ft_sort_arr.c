/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:54:27 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/21 08:44:19 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_sort_arr(t_size *arr)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	while (j < arr->size - 1)
	{
		i = 0;
		while (i < arr->size - 1)
		{
			if (ft_strcmp(arr->arr[i], arr->arr[i + 1]))
			{
				tmp = arr->arr[i];
				arr->arr[i] = arr->arr[i + 1];
				arr->arr[i + 1] = tmp;
			}
		i++;
		}
	j++;
	}
}