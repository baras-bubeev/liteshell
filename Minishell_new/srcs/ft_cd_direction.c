/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 07:28:58 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/21 13:36:38 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	ft_cd_last_directory(t_pl *pl, int cmd_i)
// {
// 	if (pl->envp.key_ignore[pl->envp.oldpwd])
// 		ft_error_oldpwd("cd");
// 	write(2, pl->envp.arr[pl->envp.oldpwd],
// 		ft_strlen( pl->envp.arr[pl->envp.oldpwd]));
// 	write(2, "\n", 1);
// 	ft_swap_str_in_envp(pl, pl->envp.pwd, pl->envp.oldpwd);
// }

void	ft_cd_with_dot(t_pl *pl, int cmd_i)
{
	char	*tmp;
	int		result;

	pl->cmd.right_path[cmd_i] = ft_strdup(pl->cmd.argv[cmd_i][1]);
	if ((result = chdir(pl->cmd.right_path[cmd_i])) == -1)
		ft_error_directory("cd", pl->cmd.argv[cmd_i][1]);
	ft_swap_key_in_envp(pl, "PWD=", "OLDPWD=");
	tmp = (char*)ft_calloc(100, sizeof(char));
	getcwd(tmp, 100);
	free(pl->envp.arr[pl->envp.pwd]);
	pl->envp.arr[pl->envp.pwd] = ft_strjoin("PWD=", tmp);
	free(tmp);
	
}

void	ft_cd_to_top_directory(t_pl *pl, int cmd_i)
{
	int		result;

	pl->cmd.right_path[cmd_i] = ft_strdup("/");
	if ((result = chdir(pl->cmd.right_path[cmd_i])) == -1)
		ft_error_directory("cd", pl->cmd.argv[cmd_i][1]);
	ft_swap_key_in_envp(pl, "PWD=", "OLDPWD=");
	free(pl->envp.arr[pl->envp.pwd]);
	pl->envp.arr[pl->envp.pwd] = ft_strjoin("PWD=", pl->cmd.right_path[cmd_i]);
}

void	ft_cd_to_home_directory(t_pl *pl, int cmd_i)
{
	int		result;

	pl->cmd.right_path[cmd_i] = ft_find_string_char(pl, "HOME=");
	if ((result = chdir(pl->cmd.right_path[cmd_i])) == -1)
		ft_error_directory("cd", pl->cmd.argv[cmd_i][1]);
	ft_swap_key_in_envp(pl, "PWD=", "OLDPWD=");
	free(pl->envp.arr[pl->envp.pwd]);
	pl->envp.arr[pl->envp.pwd] = NULL;
	pl->envp.arr[pl->envp.pwd] = ft_strjoin("PWD=", pl->cmd.right_path[cmd_i]);
	
}

void	ft_cd_with_path(t_pl *pl, int cmd_i)
{
	char	*tmp;
	int		result;

	pl->cmd.right_path[cmd_i] = ft_find_string_char(pl, "PWD=");
	tmp = ft_strjoin(pl->cmd.right_path[cmd_i], "/");
	free(pl->cmd.right_path[cmd_i]);
	pl->cmd.right_path[cmd_i] = ft_strjoin(tmp, pl->cmd.argv[cmd_i][0]);
	if ((result = chdir(pl->cmd.right_path[cmd_i])) == -1)
		ft_error_directory("cd", pl->cmd.argv[cmd_i][1]);
	ft_swap_key_in_envp(pl, "PWD=", "OLDPWD=");
	free(pl->envp.arr[pl->envp.pwd]);
	pl->envp.arr[pl->envp.pwd] = ft_strjoin("PWD=", pl->cmd.right_path[cmd_i]);
}