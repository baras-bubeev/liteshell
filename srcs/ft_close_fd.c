/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:41:05 by jkorey            #+#    #+#             */
/*   Updated: 2021/09/11 01:37:57 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_close_fd(int npipes, int pipes[][2])
{
	int	i;

	i = 0;
	while (i < npipes)
	{
		close(pipes[i - 1][0]);
		close(pipes[i][1]);
		i++;
	}
}
