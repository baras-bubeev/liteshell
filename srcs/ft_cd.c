/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 20:51:54 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/27 21:45:05 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd_flag(t_pl *pl, int cmd_i, int cmd_argc)
{
	if (cmd_argc == 1)
		ft_cd_to_home_directory(pl, cmd_i);
	else if((ft_strcmp(pl->cmd.argv[cmd_i][1], "/")) == 0)
		ft_cd_to_top_directory(pl, cmd_i);
	else if((pl->cmd.argv[cmd_i][1][0] == '.') && (pl->cmd.argv[cmd_i][1][1] == '.'))
		ft_cd_with_dot(pl, cmd_i);
	else if(pl->cmd.argv[cmd_i][1][0] == '#' || pl->cmd.argv[cmd_i][1][0] == '~' ||
		pl->cmd.argv[cmd_i][1][0] == '-')
		ft_error_subject("cd", "with only a relative or absolute path");
	else
		ft_cd_with_path(pl, cmd_i);
}

void	ft_cd(t_pl *pl, int cmd_i)
{
	int		cmd_argc;
	int		i;
	int		j;

	j = -1;
	i = -1;
	pl->envp.pwd = ft_find_string_int(pl->envp.arr, "PWD=");
	while(++i < pl->export.size && (ft_strcmp(pl->export.arr[i], "OLDPWD")));
	if ((i != pl->export.size) ||
	((j = ft_find_string_int(pl->export.arr, "OLDPWD=")) >= 0))
		if (i != pl->export.size)
			j = i;
	pl->envp.oldpwd = j;
	cmd_argc = ft_count_cmd_argv(pl, cmd_i);
	ft_cd_flag(pl, cmd_i, cmd_argc);
	free(pl->export.arr[pl->envp.pwd]);
	free(pl->export.arr[pl->envp.oldpwd]);
	pl->export.arr[pl->envp.pwd] = ft_strdup(pl->envp.arr[pl->envp.pwd]);
	pl->export.arr[pl->envp.oldpwd] = ft_strdup(pl->envp.arr[pl->envp.oldpwd]);
}