/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 20:57:58 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/28 18:17:25 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	ft_parse_pipe_line(char *pipe_line, t_pl *pl)
// {
// 	int		i;
// 	char	**tmp;

// 	tmp = ft_split(pipe_line, '|');
// 	pl->cmd.argv = (char***)ft_calloc(sizeof(char**), (pl->p.npipes + 3));
// 	pl->cmd.name = (char**)ft_calloc(sizeof(char*), (pl->p.npipes + 2));
// 	pl->cmd.right_path = (char**)ft_calloc(sizeof(char*), (pl->p.npipes + 2));
// 	i = -1;
// 	while (++i < pl->p.npipes + 1)
// 		pl->cmd.argv[i] = ft_split(tmp[i], ' ');
// 	pl->cmd.argv[i] = NULL;
// 	i = -1;
// 	while (++i < pl->p.npipes + 1)
// 		pl->cmd.name[i] = ft_strdup(pl->cmd.argv[i][0]);
// 	ft_free_arr(tmp);
// }

// void	ft_npipes(char *pipe_line, t_pl *pl)
// {
// 	int		i;

// 	pl->p.npipes = ft_count_char(pipe_line, '|');
// 	pl->p.pids = (int*)ft_calloc((pl->p.npipes + 1), sizeof(int));
// 	pl->p.fd = (int**)ft_calloc((pl->p.npipes + 1), sizeof(int*));
// 	i = -1;
// 	while (++i < pl->p.npipes + 1)
// 	{ 	
// 		pl->p.fd[i] = (int*)ft_calloc(2, sizeof(int));
// 	}
// }

// void	ft_waitpid(t_pl *pl, int i, int *arr)
// {
// 	int		status;

// 	i = -1;
// 	while (++i < pl->p.npipes + 1)
// 	{
// 		waitpid(arr[i], &status, 0);
// 		close(pl->p.fd[i][0]);
// 		close(pl->p.fd[i][1]);
// 	}
// 	dup2(pl->p.fd_0, 0);
// 	dup2(pl->p.fd_1, 1);
// 	close(pl->p.fd_0);
// 	close(pl->p.fd_1);
// }

// void	ft_fork(char *pipe_line, t_pl *pl, int i)
// {
// 	ft_npipes(pipe_line, pl);
// 	ft_parse_pipe_line(pipe_line, pl);
// 	pl->p.fd_0 = dup(0);
// 	pl->p.fd_1 = dup(1);
// 	while (++i < pl->p.npipes)
// 		if (pipe(pl->p.fd[i]) == -1)
// 			ft_error_undefined_error("pipe");
// 	i = -1;
// 	while (++i < pl->p.npipes + 1)
// 	{
// 		if (pl->flag == 1)
// 		{
// 			pl->p.pid = fork();
// 			if (pl->p.pid == -1)
// 				ft_error_undefined_error("fork");
// 			if (pl->p.pid > 0)
// 			{
// 				pl->p.pids[i] = pl->p.pid;
// 				if (i < pl->p.npipes - 1)
// 					close(pl->p.fd[i][1]);
// 			}
// 		}
// 		ft_child_process(pl, i);
// 	}
// 	ft_waitpid(pl, i, pl->p.pids);
// }

void	ft_parse_pipe_line(char *pipe_line, t_pl *pl)
{
	int		i;
	char	**tmp;

	tmp = ft_split(pipe_line, '|');
	pl->cmd.argv = (char***)ft_calloc(sizeof(char**), (pl->p.npipes + 3));
	pl->cmd.name = (char**)ft_calloc(sizeof(char*), (pl->p.npipes + 2));
	pl->cmd.right_path = (char**)ft_calloc(sizeof(char*), (pl->p.npipes + 2));
	i = -1;
	while (++i < pl->p.npipes + 1)
		pl->cmd.argv[i] = ft_split(tmp[i], ' ');
	pl->cmd.argv[i] = NULL;
	i = -1;
	while (++i < pl->p.npipes + 1)
		pl->cmd.name[i] = strdup(pl->cmd.argv[i][0]);
	ft_free_arr(tmp);
}

void	ft_npipes(char *pipe_line, t_pl *pl)
{
	int		i;
	int		cmd;

	pl->p.npipes = ft_count_char(pipe_line, '|');
	cmd = pl->p.npipes + 1;
	pl->p.pids = (int*)ft_calloc((cmd + 1), sizeof(int));
	pl->p.fd = (int**)ft_calloc((cmd + 2), sizeof(int*));
	i = -1;
	while (++i <= cmd + 1)
	{ 	
		pl->p.fd[i] = (int*)ft_calloc(2, sizeof(int));
	}
}

void	ft_waitpid(t_pl *pl, int i)
{
	int	status;
	i = -1;
	while (++i <= pl->p.npipes + 1)
	{
		if (i != pl->p.npipes + 1)
			close(pl->p.fd[i][0]);
		if (i != 0)
			close(pl->p.fd[i][1]);
	}
	close(pl->p.fd[pl->p.npipes + 1][0]);
	close(pl->p.fd[0][1]);
	i = -1;
	while (++i < pl->p.npipes + 1)
		waitpid(pl->p.pids[i], &status, 0);
}

void	ft_fork(char *pipe_line, t_pl *pl, int i)
{
	ft_npipes(pipe_line, pl);
	ft_parse_pipe_line(pipe_line, pl);
	while (++i <= pl->p.npipes + 1)
		if (pipe(pl->p.fd[i]) == -1)
			ft_error_undefined_error("pipe");
	i = -1;
	while (++i < pl->p.npipes + 1)
	{
		pl->p.pids[i] = fork();
		if (pl->p.pids[i] == -1)
			ft_error_undefined_error("fork");
		ft_child_process(pl, i);
	}
	ft_waitpid(pl, -1);
}
