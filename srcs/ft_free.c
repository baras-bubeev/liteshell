/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:47:19 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/27 21:46:09 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_pids(t_pl *pl)
{
	int		i;
	
	i = -1;
	free(pl->p.pids);
	while (++i < pl->p.npipes + 1)
		free(pl->p.fd[i]);
	free(pl->p.fd);
	pl->p.pids = NULL;
	pl->p.fd = NULL;
}

void	ft_free_arr(char **arr)
{
	int i;

	i = -1;
	while(arr[++i])
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
}