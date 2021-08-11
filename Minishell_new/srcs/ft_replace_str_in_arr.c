/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_str_in_arr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:40:15 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/21 00:09:50 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_replace_key_in_arr(char *str, char *key, char *new_mining)
{
	char	*tmp;

	tmp = ft_strdup_from(str, ft_strlen(key));
	free(str);
	str = ft_strjoin(key, tmp);
	free(tmp);
}