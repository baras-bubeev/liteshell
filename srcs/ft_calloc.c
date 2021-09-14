/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:29:46 by jkorey            #+#    #+#             */
/*   Updated: 2021/09/10 18:10:54 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*link;

	link = malloc(size * count);
	if (link == 0)
		ft_error_malloc();
	ft_memset(link, 0, size * count);
	return (link);
}
