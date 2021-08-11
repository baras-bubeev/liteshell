/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_strings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 10:34:06 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/21 12:04:02 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_swap_str_in_arr(char **arr, int	*key_ignore, int str1, int str2)
{
	char	*tmp;
	int		c;
    tmp = NULL;
    // printf("BEFORE: str1 = %s  str2 = %s  tmp = %s\n", pl->envp.arr[pwd], pl->envp.arr[oldpwd], tmp);
    tmp = ft_strdup(arr[str1]);
	c = key_ignore[str1];
    free(arr[str1]);
    arr[str1] = ft_strdup(arr[str2]);
	key_ignore[str1] = key_ignore[str2];
    free(arr[str2]);
    arr[str2] = ft_strdup(tmp);
	key_ignore[str2] = c;
    free(tmp);
    tmp = NULL;
    // printf("AFTER: str1 = %s  str2 = %s ", arr[str1], arr[str2]);
}

void	ft_swap_key_in_envp(t_pl *pl, char *key1, char *key2)
{
	int		i_key1;
	int		i_key2;
    char	*tmp1;
	char	*tmp2;
	
	i_key1 = ft_find_string_int(pl->envp.arr, key1);
	tmp1 = ft_strdup_from(pl->envp.arr[i_key1], ft_strlen(key1));
	i_key2 = ft_find_string_int(pl->envp.arr, key2);
	tmp2 = ft_strdup_from(pl->envp.arr[i_key2], ft_strlen(key2));
    free(pl->envp.arr[i_key1]);
    free(pl->envp.arr[i_key2]);
	pl->envp.arr[i_key1] = ft_strjoin(key1, tmp2);
    pl->envp.arr[i_key2] = ft_strjoin(key2, tmp1);
    free(tmp1);
    free(tmp2);
    // printf("AFTER: str1 = %s  str2 = %s  tmp = %s\n", pl->envp.arr[pwd], pl->envp.arr[oldpwd], tmp);
}