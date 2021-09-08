/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 08:20:42 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/26 13:50:12 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void	ft_env(t_pl *pl, int cmd_i)
{
	int		cmd_argc;

	cmd_argc = ft_count_cmd_argv(pl, cmd_i);
	if (cmd_argc == 1)
		ft_print_arr(pl->envp.arr, pl->envp.key_ignore, 0);
	else
		ft_error_subject("env", "with no options or arguments");
}