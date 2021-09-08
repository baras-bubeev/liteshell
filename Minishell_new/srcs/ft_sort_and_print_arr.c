/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_and_print_arr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:54:27 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/26 14:05:31 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print_arr(char **arr, int *key_ignore, int type)
{
	int		i;

	i = -1;
	while (arr[++i])
	{
		if(key_ignore[i] == 0)
		{
			if (type)
				write(1, "declare -x ", 11);
			write(1, arr[i], ft_strlen(arr[i]));
			write(1, "\n", 1);
		}
	}
}

static void	ft_sort_arr_second(char **copy_arr, int *copy_key_ignore, int i)
{
	char	*tmp;
	int		tmp_ignore;

	tmp = copy_arr[i];
	tmp_ignore = copy_key_ignore[i];
	copy_arr[i] = copy_arr[i + 1];
	copy_key_ignore[i] = copy_key_ignore[i + 1];
	copy_arr[i + 1] = tmp;
	copy_key_ignore[i + 1] = tmp_ignore;
}

void		ft_sort_arr_and_print(t_size *arr, int i, int j)
{
	char	**copy_arr;
	int		*copy_key_ignore;

	copy_arr = ft_make_arr_copy(&i, arr->arr);
	copy_key_ignore = ft_calloc(sizeof(int), arr->size);
	while(++j < arr->size)
		copy_key_ignore[j] = arr->key_ignore[j];
	j = -1;
	while (++j < arr->size - 1)
	{
		i = -1;
		while (++i < arr->size - 1)
			if (ft_strcmp(copy_arr[i], copy_arr[i + 1]) > 0)
				ft_sort_arr_second(copy_arr, copy_key_ignore, i);
	}
	ft_print_arr(copy_arr, copy_key_ignore, 1);
	ft_free_arr(copy_arr);
	free(copy_key_ignore);
}