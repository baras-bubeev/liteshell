/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:04:30 by jkorey            #+#    #+#             */
/*   Updated: 2021/09/11 08:42:36 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_shlvl(t_pl *pl)
{
	char	*old;
	char	*new;
	int		shlvl;
	int		i;

	i = ft_find_string_int(pl->envp.arr, "SHLVL=");
	old = ft_find_string_char(pl, "SHLVL=");
	shlvl = ft_atoi(old) + 1;
	new = ft_itoa(shlvl);
	ft_replace_mining_in_arr(&pl->envp.arr[i], "SHLVL=", new);
	free(old);
	free(new);
}
