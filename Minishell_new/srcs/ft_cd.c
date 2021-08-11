/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 20:51:54 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/21 13:38:42 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	ft_cd_tilda(t_pl *pl, int cmd_i, int cmd_argc)
// {
// 	if(pl->cmd.argv[cmd_i][1][1])
// 		ft_error_directory("cd", pl->cmd.argv[cmd_i][1]);
// 	ft_cd_to_home_directory(pl, cmd_i);
// }

// cd, cd ~, cd /, cd .., cd #, cd -, cd --, cd ..


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

	
	//|| !(ft_strcmp(pl->cmd.argv[cmd_i][1], "--")))
	// else if (!(ft_strcmp(pl->cmd.argv[cmd_i][1], "/")))
	// 	ft_cd_to_top_directory(pl, cmd_i);
	// else if (!(ft_strcmp(pl->cmd.argv[cmd_i][1], "-")))
	// 	ft_cd_last_directory(pl, cmd_i);	
}

void	ft_cd(t_pl *pl, int cmd_i)
{
	int		result;
	int		cmd_argc;

	pl->envp.pwd = ft_find_string_int(pl->envp.arr, "PWD=");
	pl->envp.oldpwd = ft_find_string_int(pl->envp.arr, "OLDPWD=");
	cmd_argc = ft_count_cmd_argv(pl, cmd_i);
	ft_cd_flag(pl, cmd_i, cmd_argc);
	pl->envp.key_ignore[pl->envp.oldpwd] = 0;
	free(pl->export.arr[pl->envp.pwd]);
	free(pl->export.arr[pl->envp.oldpwd]);
	pl->export.arr[pl->envp.pwd] = ft_strdup(pl->envp.arr[pl->envp.pwd]);
	pl->export.arr[pl->envp.oldpwd] = ft_strdup(pl->envp.arr[pl->envp.oldpwd]);

	// printf("pwd = %d = %s\nold_pwd = %d = %s\n", pl->envp.pwd, pl->envp.arr[pl->envp.pwd], pl->envp.oldpwd, pl->envp.arr[pl->envp.oldpwd]);
	
	// if ((oldpwd = ft_find_string_int(pl->envp.arr, "OLDPWD=")) == -1)
	// {	
	// 	pl->envp.newsize = pl->envp.size + 1;
	// 	ft_add_line_in_arr(pl->envp.arr, "OLDPWD=", pwd, pl->envp.newsize);
	// 	oldpwd = pwd + 1;
	// }
	
}