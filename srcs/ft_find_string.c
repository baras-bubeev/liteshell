/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:36:28 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/27 21:45:50 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_find_string_int(char **arr, char *name)
{
	int		i;
	int		count;
	int		name_len;
	
	i = 0;
	count = 0;
	name_len = ft_strlen(name);
	while (count == 0 && arr[i])
	{
		if (ft_strnstr(arr[i], name, name_len) == NULL)
			i++;
		else
		{ 
			if (ft_strncmp(arr[i], name, name_len) == 0)
				count = 1;
			else
				i++;
		} 
	}
	if (!count)
		return (-1);
	return (i);
}

char	*ft_find_string_char(t_pl *pl, char *name)
{
	int		i;
	char	*string;
	
	string = NULL;
	i = ft_find_string_int(pl->envp.arr, name);
	if (i >= 0)
		string = ft_strdup_from(pl->envp.arr[i], ft_strlen(name));
	return (string);
}