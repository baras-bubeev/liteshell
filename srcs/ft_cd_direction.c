/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 07:28:58 by jkorey            #+#    #+#             */
/*   Updated: 2021/09/11 01:56:36 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd_with_dot(t_pl *pl, int cmd_i)
{
	char	*tmp;
	char	*tmp_pwd;
	int		result;

	tmp_pwd = getcwd(NULL, 0);
	pl->cmd.right_path[cmd_i] = ft_strdup(pl->cmd.argv[cmd_i][1]);
	result = chdir(pl->cmd.right_path[cmd_i]);
	if (result == -1)
		ft_error_directory("cd", pl->cmd.argv[cmd_i][1]);
	if (!(pl->envp.arr[pl->envp.oldpwd]))
		pl->envp.arr[pl->envp.oldpwd] = ft_strjoin("OLDPWD=", tmp_pwd);
	else
		ft_swap_key_in_envp(pl, "PWD=", "OLDPWD=");
	tmp = getcwd(NULL, 0);
	free(pl->envp.arr[pl->envp.pwd]);
	pl->envp.arr[pl->envp.pwd] = ft_strjoin("PWD=", tmp);
	free(tmp);
	free(tmp_pwd);
}

void	ft_cd_to_top_directory(t_pl *pl, int cmd_i)
{
	int		result;
	char	*tmp_pwd;

	tmp_pwd = getcwd(NULL, 0);
	pl->cmd.right_path[cmd_i] = ft_strdup("/");
	result = chdir(pl->cmd.right_path[cmd_i]);
	if (result == -1)
		ft_error_directory("cd", pl->cmd.argv[cmd_i][1]);
	if (!(pl->envp.arr[pl->envp.oldpwd]))
		pl->envp.arr[pl->envp.oldpwd] = ft_strjoin("OLDPWD=", tmp_pwd);
	else
		ft_swap_key_in_envp(pl, "PWD=", "OLDPWD=");
	free(tmp_pwd);
	free(pl->envp.arr[pl->envp.pwd]);
	pl->envp.arr[pl->envp.pwd] = ft_strjoin("PWD=", pl->cmd.right_path[cmd_i]);
}

void	ft_cd_to_home_directory(t_pl *pl, int cmd_i)
{
	int		result;
	int		i;
	char	*tmp_pwd;

	tmp_pwd = getcwd(NULL, 0);
	i = ft_find_string_int(pl->envp.arr, "HOME=");
	if (pl->envp.key_ignore[i] == 1)
		ft_error_not_set_name("cd", "HOME");
	pl->cmd.right_path[cmd_i] = ft_find_string_char(pl, "HOME=");
	result = chdir(pl->cmd.right_path[cmd_i]);
	if (result == -1)
		ft_error_directory("cd", pl->cmd.argv[cmd_i][1]);
	if (!(pl->envp.arr[pl->envp.oldpwd]))
		pl->envp.arr[pl->envp.oldpwd] = ft_strjoin("OLDPWD=", tmp_pwd);
	else
		ft_swap_key_in_envp(pl, "PWD=", "OLDPWD=");
	free(tmp_pwd);
	free(pl->envp.arr[pl->envp.pwd]);
	pl->envp.arr[pl->envp.pwd] = NULL;
	pl->envp.arr[pl->envp.pwd] = ft_strjoin("PWD=", pl->cmd.right_path[cmd_i]);
}

void	ft_cd_with_path(t_pl *pl, int cmd_i)
{
	char	*tmp;
	int		result;
	char	*tmp_pwd;

	tmp_pwd = getcwd(NULL, 0);
	if (pl->cmd.argv[cmd_i][1][0] != '/')
	{
		pl->cmd.right_path[cmd_i] = ft_find_string_char(pl, "PWD=");
		tmp = ft_strjoin(pl->cmd.right_path[cmd_i], "/");
		free(pl->cmd.right_path[cmd_i]);
		pl->cmd.right_path[cmd_i] = ft_strjoin(tmp, pl->cmd.argv[cmd_i][1]);
	}
	else
		pl->cmd.right_path[cmd_i] = ft_strdup(pl->cmd.argv[cmd_i][1]);
	result = chdir(pl->cmd.right_path[cmd_i]);
	if (result == -1)
		ft_error_directory("cd", pl->cmd.argv[cmd_i][1]);
	if (!(pl->envp.arr[pl->envp.oldpwd]))
		pl->envp.arr[pl->envp.oldpwd] = ft_strjoin("OLDPWD=", tmp_pwd);
	else
		ft_swap_key_in_envp(pl, "PWD=", "OLDPWD=");
	free(pl->envp.arr[pl->envp.pwd]);
	pl->envp.arr[pl->envp.pwd] = ft_strjoin("PWD=", pl->cmd.right_path[cmd_i]);
}
