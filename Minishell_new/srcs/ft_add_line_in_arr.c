/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_line_in_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 08:47:13 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/27 22:10:54 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

// void	ft_add_line_in_arr(char **arr, char *line, int i_before_line,
// 		int new_size)
// {
// 	char	**tmp;
// 	int		i;
// 	int		j;

// 	tmp = ft_calloc(new_size, sizeof(char));
// 	i = -1;
// 	while(++i <= i_before_line)
// 		tmp[i] = ft_strdup(arr[i]);
// 	j = i;
// 	tmp[i] = ft_strdup(line);
// 	i++;
// 	while(i < new_size - 1)
// 	{
// 		tmp[i] = ft_strdup(arr[j]);
// 		j++;
// 		i++;
// 	}
// 	tmp[i] = NULL;
// 	ft_free_arr(arr);
// 	arr = ft_make_arr_copy(&i, tmp);
// 	int a = 0;
// 	while (arr[a])
// 	{
// 		printf("%d = %s\n", a+1, arr[a]);
// 		a++;
// 	}
// 	free(tmp);
// }

void	ft_add_line_in_arr(t_size *arr, char *line, int key_ignore)
{
	arr->arr[arr->size] = ft_strdup(line);
	arr->key_ignore[arr->size] = key_ignore;
	arr->size++;
}