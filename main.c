/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:58:42 by mpowder           #+#    #+#             */
/*   Updated: 2021/09/11 07:28:53 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_pl	pl;

	(void)argc;
	(void)argv;
	pl.round_counter = -1;
	g_cmd_exit = 0;
	pl.fd_in = 0;
	pl.fd_out = 1;
	pl.envp.arr = ft_make_arr_copy(&pl.envp.size, env);
	pl.export.arr = ft_make_arr_copy(&pl.export.size, env);
	ft_shlvl(&pl);
	loop(&pl);
	ft_putstr_fd("\e[1F\e[12Gexit\n", 1);
	return (0);
}
