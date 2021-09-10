/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:58:42 by mpowder           #+#    #+#             */
/*   Updated: 2021/09/10 14:59:14 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	t_pl	pl;
	char	*pipe_line;

	pl.round_counter = -1;
	cmd_exit = 0;
	pl.fd_in = 0;
	pl.fd_out = 1;
	pl.envp.arr = ft_make_arr_copy(&pl.envp.size, env);
	pl.export.arr = ft_make_arr_copy(&pl.export.size, env);
	ft_shlvl(&pl);
	loop(&pl);
	return (0);
}