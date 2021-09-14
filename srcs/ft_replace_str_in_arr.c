/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_str_in_arr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:40:15 by jkorey            #+#    #+#             */
/*   Updated: 2021/09/11 02:39:54 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_replace_key_in_arr(char *str, char *key, char *new_key)
{
	char	*tmp;

	tmp = ft_strdup_from(str, ft_strlen(key));
	free(str);
	str = ft_strjoin(new_key, tmp);
	free(tmp);
}

void	ft_replace_mining_in_arr(char **str, char *key, char *new_mining)
{
	char	*tmp;

	tmp = ft_strjoin(key, new_mining);
	free(*str);
	*str = ft_strdup(tmp);
	free(tmp);
}
