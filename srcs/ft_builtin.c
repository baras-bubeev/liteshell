/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:48:19 by jkorey            #+#    #+#             */
/*   Updated: 2021/09/11 06:11:23 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_start_builtin(t_pl *pl, int cmd_i)
{
	if (!(ft_strcmp(pl->cmd.argv[cmd_i][0], "echo")))
		ft_echo(pl, cmd_i);
	else if (!(ft_strcmp(pl->cmd.argv[cmd_i][0], "cd")))
		ft_cd(pl, cmd_i);
	else if (!(ft_strcmp(pl->cmd.argv[cmd_i][0], "pwd")))
		ft_pwd(pl);
	else if (!(ft_strcmp(pl->cmd.argv[cmd_i][0], "unset")))
		ft_unset(pl, cmd_i);
	else if (!(ft_strcmp(pl->cmd.argv[cmd_i][0], "env")))
		ft_env(pl, cmd_i);
	else if (!(ft_strcmp(pl->cmd.argv[cmd_i][0], "export")))
		ft_export(pl, cmd_i);
	else if (!(ft_strcmp(pl->cmd.argv[cmd_i][0], "exit")))
		ft_exit(pl, cmd_i, 0);
}

int	ft_if_builtin(t_pl *pl, int cmd_i, int key, int size)
{
	int		i;
	int		count;
	char	**tmp;
	char	*tmp_cmd;

	i = 1;
	count = 0;
	tmp = ft_split(BUILTIN, ' ');
	while (pl->pipe_line[size] && pl->pipe_line[size] != ' ')
		size++;
	tmp_cmd = ft_strdup_len(pl->pipe_line, size);
	while (tmp[i] && count == 0)
	{
		if (key == 0)
			if (ft_strcmp(tmp[i], tmp_cmd) == 0)
				count = 1;
		if (key == 1)
			if (ft_strcmp(tmp[i], pl->cmd.name[cmd_i]) == 0)
				count = 1;
		i++;
	}
	ft_free_arr(tmp);
	free(tmp_cmd);
	return (count);
}
