/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:44:02 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/28 18:36:14 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int		ft_is_exec(char *path)
// {
// 	struct stat	buf;
// 	int			fd;

// 	if ((fd = open(path, O_RDONLY)) == -1)
// 		return (0);
// 	fstat(fd, &buf);
// 	close(fd);
// 	if (!S_ISDIR(buf.st_mode))
// 		return (1);
// 	return (0);
// }

// int		ft_find_cmd_path(int name, t_pl *pl)
// {
// 	int		i;
// 	int		path_size;
// 	char	**tmp;

// 	path_size = -1;
// 	while(pl->path[++path_size]);
// 	tmp = (char**)ft_calloc((path_size + 1), sizeof(char*));
// 	i = -1;
// 	while(++i < path_size)
// 		tmp[i] = ft_strdup(pl->path[i]);
// 	tmp[i] = NULL;
// 	ft_concatenate_str_in_arr(tmp, i, pl->cmd.name[name]);
// 	i = 0;
// 	while (tmp[i])
// 	{
// 		if ((ft_is_exec(tmp[i])))
// 		{
// 			pl->cmd.right_path[name] = ft_strdup(tmp[i]);
// 			ft_free_arr(tmp);
// 			return (0);
// 		}
// 		i++;
// 	}
// 	ft_free_arr(tmp);
// 	return (-1);
// }

// void	ft_execve(int cmd_i, t_pl *pl)
// {
// 	int a;
	
// 	if ((a = ft_find_cmd_path(cmd_i, pl)) == -1)
// 		ft_error_cmd_not_found(pl->cmd.argv[cmd_i][0]);
// 	else
// 	{
// 		execve(pl->cmd.right_path[cmd_i], pl->cmd.argv[cmd_i], pl->envp.arr);
// 	}
// }

// void	ft_child_process(t_pl *pl, int i)
// {
// 	if (pl->p.pid == 0)
// 	{
// 		if (i == 0)
// 		{
// 			close(pl->p.fd[i][0]);
// 			dup2(pl->p.fd[i][1], 1);
// 		}
// 		else if (i < pl->p.npipes)
// 		{
// 			close(pl->p.fd[i - 1][1]);
// 			dup2(pl->p.fd[i - 1][0], 0);
// 			close(pl->p.fd[i][0]);
// 			dup2(pl->p.fd[i][1], 1);
// 		}
// 		else if (i == pl->p.npipes)
// 		{
// 			close(pl->p.fd[i - 1][1]);
// 			dup2(pl->p.fd[i - 1][0], 0);
// 			close(pl->p.fd[i - 1][0]);
			
// 		}
// 		if (!(ft_if_builtin(pl, i, "echo cd pwd export unset env exit", 1, 0)))
// 			ft_execve(i, pl);
// 		else
// 			ft_start_builtin(pl, i);
// 		exit (0);
// 	}
// }

int		ft_is_exec(char *path)
{
	struct stat	buf;
	int			fd;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	fstat(fd, &buf);
	close(fd);
	if (!S_ISDIR(buf.st_mode))
		return (1);
	return (0);
}

int		ft_find_cmd_path(int name, t_pl *pl)
{
	int		i;
	int		path_size;
	char	**tmp;

	path_size = -1;
	while(pl->path[++path_size]);
	tmp = (char**)ft_calloc((path_size + 1), sizeof(char*));
	i = -1;
	while(++i < path_size)
		tmp[i] = ft_strdup(pl->path[i]);
	tmp[i] = NULL;
	ft_concatenate_str_in_arr(tmp, i, pl->cmd.name[name]);
	i = 0;
	while (tmp[i])
	{
		if ((ft_is_exec(tmp[i])))
		{
			pl->cmd.right_path[name] = strdup(tmp[i]);
			ft_free_arr(tmp);
			return (0);
		}
		i++;
	}
	ft_free_arr(tmp);
	return (-1);
}

void	ft_execve(int cmd_i, t_pl *pl)
{
	int a;
	
	if ((a = ft_find_cmd_path(cmd_i, pl)) == -1)
		ft_error_cmd_not_found(pl->cmd.argv[cmd_i][0]);
	else
	{
		execve(pl->cmd.right_path[cmd_i], pl->cmd.argv[cmd_i], pl->envp.arr);
	}
}

void	ft_child_process(t_pl *pl, int i)
{
	int		j;

	if (pl->p.pids[i] == 0)
	{
		j = -1;
		while (++j <= pl->p.npipes + 1)
		{
			if (j != i)
				close(pl->p.fd[j][0]);
			if (j != i + 1)
				close(pl->p.fd[j][1]);
		}
		pl->p.fd_1 = pl->p.fd[i + 1][1];
		if (i == 0)
			pl->p.fd_0 = STDIN_FILENO; // или fd_read
		else
			pl->p.fd_0 = pl->p.fd[i][0];
		dup2(pl->p.fd_0, 0);
		if (i == pl->p.npipes)
			pl->p.fd_1 = STDOUT_FILENO; // или fd_write
		dup2(pl->p.fd_1, 1);
		if (!(ft_if_builtin(pl, i, "echo cd pwd export unset env exit", 1, 0)))
			ft_execve(i, pl);
		else
			ft_start_builtin(pl, i);
		close(pl->p.fd[i][0]);
		close(pl->p.fd[i + 1][0]);
		exit (0);
	}
}
