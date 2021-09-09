/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:19:57 by jkorey            #+#    #+#             */
/*   Updated: 2021/09/09 17:46:31 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_set_cmd_flag(t_pl *pl, char *pipe_line)
{
	int		i;

	if (pl->round_counter > 0)
		pl->cmd.old_flag = pl->flag;
	i = -1;
	// pl->flag = 0;
	while (pipe_line[++i] && pl->flag == 0)
	// {
		if (pipe_line[i] == '|')
			pl->flag = 1;
		// else if (pipe_line[i] == '>' || pipe_line[i] == '<')
		// 	pl->flag = 3;
	// }
	if (pl->flag == 0)
	{
		if (!(ft_if_builtin(pl, 0, "echo cd pwd export unset env exit", 0, 0)))
			pl->flag = 1;
		else
			pl->flag = 2;
	}
}

void	ft_mute_oldpwd(t_pl *pl)
{
	int		i;
	int		count;

	i = -1;
	count = 1;
	while (++i < pl->envp.size && count)
	{
		if (!(ft_strncmp("OLDPWD=", pl->envp.arr[i], 7)))
		{
			pl->envp.key_ignore[i] = 0;
			pl->export.key_ignore[i] = 0;
			free(pl->export.arr[i]);
			ft_swap_str_in_arr(pl->envp.arr, pl->envp.key_ignore, i, pl->envp.size - 1);
			pl->export.arr[i] = ft_strdup("OLDPWD");
			ft_swap_str_in_arr(pl->export.arr, pl->export.key_ignore, i, pl->envp.size - 1);
			count = 0;
			free(pl->envp.arr[pl->envp.size - 1]);
			pl->envp.arr[pl->envp.size - 1] = NULL;
		}
		else
		{
			pl->envp.key_ignore[i] = 0;
			pl->export.key_ignore[i] = 0;
		}
	}
}

void	ft_clean_variables(t_pl *pl)
{
	int		i;

	if ((pl->flag == 1 || pl->flag == 2))
	{
		ft_free_pids(pl);
		i = -1;
		while (pl->cmd.argv[++i])
			ft_free_arr(pl->cmd.argv[i]);
		free(pl->cmd.argv);
		ft_free_arr(pl->cmd.name);
		ft_free_arr(pl->cmd.right_path);
		free(pl->pipe_line);
	}
	pl->flag = 0;
}

void	ft_prepare_variables(t_pl *pl, int round_counter)
{
	if (round_counter == 0)
	{
		pl->envp.key_ignore = (int*)ft_calloc(pl->envp.size + 60, sizeof(int));
		pl->export.key_ignore = (int*)ft_calloc(pl->export.size + 60, sizeof(int));
		ft_mute_oldpwd(pl);
		pl->fd_0 = dup(0);
		pl->fd_1 = dup(1);
		pl->p.fd = NULL;
		pl->cmd.argv = NULL;
		pl->cmd.name = NULL;
		pl->cmd.right_path = NULL;
		ft_path(pl);
	}
}

// void	ft_start_comands(t_pl *pl, char *pipe_line)
void	ft_start_comands(t_pl *pl)
{
	pl->round_counter++;
	ft_prepare_variables(pl, pl->round_counter);
	// pl->pipe_line = ft_strdup(pipe_line);
	ft_set_cmd_flag(pl, pl->pipe_line);
	if (pl->flag == 1 || pl->flag == 3)
		ft_fork(pl->pipe_line, pl, -1);
	if (pl->flag == 2)
		ft_single_builtin(pl->pipe_line, pl, -1);
	ft_clean_variables(pl);
	// printf("%d\n", pl->flag);
}

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
