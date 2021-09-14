/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:44:02 by jkorey            #+#    #+#             */
/*   Updated: 2021/09/11 02:06:23 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_exec(char *path)
{
	struct stat	buf;
	int			fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	fstat(fd, &buf);
	close(fd);
	if (!S_ISDIR(buf.st_mode))
		return (1);
	return (0);
}

int	ft_find_cmd_path(int name, t_pl *pl)
{
	int		i;
	int		path_size;
	char	**tmp;

	path_size = -1;
	while (pl->path[++path_size])
		;
	tmp = (char **)ft_calloc((path_size + 1), sizeof(char *));
	i = -1;
	while (++i < path_size)
		tmp[i] = ft_strdup(pl->path[i]);
	tmp[i] = NULL;
	ft_concatenate_str_in_arr(tmp, i, pl->cmd.name[name]);
	i = -1;
	while (tmp[++i])
	{
		if ((ft_is_exec(tmp[i])))
		{
			pl->cmd.right_path[name] = strdup(tmp[i]);
			ft_free_arr(tmp);
			return (0);
		}
	}
	ft_free_arr(tmp);
	return (-1);
}

void	ft_execve(int cmd_i, t_pl *pl)
{
	int	a;

	a = ft_find_cmd_path(cmd_i, pl);
	if (a == -1)
		ft_error_cmd_not_found(pl->cmd.argv[cmd_i][0]);
	else
		execve(pl->cmd.right_path[cmd_i], pl->cmd.argv[cmd_i], pl->envp.arr);
}

void	ft_child_process_utils(t_pl *pl, int i)
{
	if (i == 0)
	{
		close(pl->p.fd_0);
		pl->p.fd_0 = pl->fd_in;
	}
	else
		pl->p.fd_0 = pl->p.fd[i][0];
	dup2(pl->p.fd_0, 0);
	if (i == pl->p.npipes)
		pl->p.fd_1 = pl->fd_out;
	dup2(pl->p.fd_1, 1);
	if (!(ft_if_builtin(pl, i, 1, 0)))
		ft_execve(i, pl);
	else
		ft_start_builtin(pl, i);
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
		ft_child_process_utils(pl, i);
		close(pl->p.fd[i][0]);
		close(pl->p.fd[i + 1][0]);
		exit (0);
	}
}
