/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:19:57 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/21 13:33:05 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_set_cmd_flag(t_pl *pl, char *pipe_line)
{
	int		i;
	int		j;
	char	*tmp;

	if (pl->round_counter > 0)
		pl->cmd.old_flag = pl->flag;
	i = -1;
	pl->flag = 0;
	while (pipe_line[++i] && pl->flag == 0)
	{
		if (pipe_line[i] == '|')
			pl->flag = 1;
		else if (pipe_line[i] == '>' || pipe_line[i] == '<')
			pl->flag = 3;
	}
	if (pl->flag == 0)
	{
		if ((ft_if_builtin(pl, 0, "echo cd pwd export unset env exit", 0, j)))
			pl->flag = 1;
		else
			pl->flag = 2;
	}
}

void	ft_mute_oldpwd(t_pl *pl)
{
	int		i;

	i = -1;
	while (++i < pl->envp.size)
	{
		if (!(ft_strncmp("OLDPWD=", pl->envp.arr[i], 7)))
		{
			pl->envp.key_ignore[i] = 1;
			pl->export.key_ignore[i] = 0;
			free(pl->export.arr[i]);
			ft_swap_str_in_arr(pl->envp.arr, pl->envp.key_ignore, i, pl->envp.size - 1);
			pl->export.arr[i] = ft_strdup("OLDPWD");
			ft_swap_str_in_arr(pl->export.arr, pl->export.key_ignore, i, pl->envp.size - 1);
			
		}
		else
		{
			pl->envp.key_ignore[i] = 0;
			pl->export.key_ignore[i] = 0;
		}
	}
}

void	ft_prepare_variables(t_pl *pl, int round_counter)
{
	int		i;

	if (round_counter == 0)
	{
		pl->envp.key_ignore = (int*)ft_calloc(pl->envp.size, sizeof(int));
		pl->export.key_ignore = (int*)ft_calloc(pl->export.size, sizeof(int));
		ft_mute_oldpwd(pl);
		pl->p.pids = NULL;
		pl->p.pipes = NULL;
		pl->cmd.argv = NULL;
		pl->cmd.name = NULL;
		pl->cmd.right_path = NULL;
		ft_path(pl);
	}
	else if (round_counter > 0 && (pl->cmd.old_flag == 1 || pl->cmd.old_flag == 2))
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
}

void	ft_start_comands(t_pl *pl, char *pipe_line, char **envp)
{
	pl->round_counter++;
	ft_prepare_variables(pl, pl->round_counter);
	// int	i = -1;
	// while(pl->envp.arr[++i])
	// 	printf("%d = %d = %s\n", i, pl->export.key_ignore[i], pl->envp.arr[i]);
	pl->pipe_line = ft_strdup(pipe_line);
	ft_set_cmd_flag(pl, pipe_line);
	if (pl->flag == 1 || pl->flag == 2)
		ft_fork(pipe_line, pl, -1);

	// else if (pl->flag == 3)
	// 	ft_redirect(pipe_line, pl);
	
	// int	i = -1;
	// while(pl->envp.arr[++i])
	// 	printf("%d = %s\n", i, pl->envp.arr[i]);
	// printf("num of pwd = %s\n", ft_find_string_char(pl, "PWD="));
}

int		main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	t_pl	pl;

	char	*pipe_line = "cd #";
	char	*pipe_line2 = "env";
	pl.round_counter = -1;
	cmd_exit = 0;
	pl.envp.arr = ft_make_arr_copy(&pl.envp.size, env);
	pl.export.arr = ft_make_arr_copy(&pl.export.size, env);
	ft_start_comands(&pl, pipe_line, env);
	ft_start_comands(&pl, pipe_line2, env);

	// sleep (1000);
	return (0);
}
