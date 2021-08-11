/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:47:19 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/20 07:26:21 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_pids(t_pl *pl)
{
	int		i;
	
	i = -1;
	free(pl->p.pids);
	while (++i < pl->p.npipes + 1)
		free(pl->p.pipes[i]);
	free(pl->p.pipes);
	pl->p.pids = NULL;
	pl->p.pipes = NULL;
}

void	ft_free_arr(char **arr)
{
	int i;
	int j;

	i = -1;
	while(arr[++i])
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
}