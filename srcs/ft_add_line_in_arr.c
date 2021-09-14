/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_line_in_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 08:47:13 by jkorey            #+#    #+#             */
/*   Updated: 2021/09/11 02:08:55 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_add_line_in_arr(t_size *arr, char *line, int key_ignore)
{
	arr->arr[arr->size] = ft_strdup(line);
	arr->key_ignore[arr->size] = key_ignore;
	arr->size++;
}
