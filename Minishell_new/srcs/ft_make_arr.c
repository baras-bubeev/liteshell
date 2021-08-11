/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:53:36 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/21 08:38:42 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

 char	**ft_make_arr_copy(int *size, char **arr)
{
	int		i;
	int		j;
	char	**tmp;
	i = 0;
	j = 0;
	while(arr[j] != 0)
		j++;
	tmp = (char**)ft_calloc((j + 1 + 30), sizeof(char*));
	while(i < j)
	{
		tmp[i] = ft_strdup(arr[i]);
		i++;
	}
	// tmp[i] = NULL;
	*size = j;
	return (tmp);
}
