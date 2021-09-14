/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:19:57 by jkorey            #+#    #+#             */
/*   Updated: 2021/09/11 06:20:57 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_set_cmd_flag(t_pl *pl, char *pipe_line)
{
	(void)pipe_line;
	if (pl->round_counter > 0)
		pl->cmd.old_flag = pl->flag;
	if (pl->flag == 0)
	{
		if (!(ft_if_builtin(pl, 0, 0, 0)))
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
		ft_mute_oldpwd_utils(pl, i, &count);
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
		pl->envp.key_ignore = (int *)ft_calloc(pl->envp.size + 60, sizeof(int));
		pl->export.key_ignore = (int *)ft_calloc(pl->export.size + 60,
				sizeof(int));
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

void	ft_start_comands(t_pl *pl)
{
	if (pl->fd_in != -1 && pl->fd_out != -1)
	{
		pl->round_counter++;
		ft_prepare_variables(pl, pl->round_counter);
		ft_set_cmd_flag(pl, pl->pipe_line);
		if (pl->flag == 1 || pl->flag == 3)
			ft_fork(pl->pipe_line, pl, -1);
		if (pl->flag == 2)
			ft_single_builtin(pl->pipe_line, pl, -1);
		ft_clean_variables(pl);
	}
	if (pl->fd_in != 0)
		close(pl->fd_in);
	pl->fd_in = 0;
	if (pl->fd_out != 1)
		close(pl->fd_out);
	pl->fd_out = 1;
	unlink(".tmp");
}
