/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 11:13:39 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/27 22:10:37 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_take_str_in_quotes(char *str)
{
	char	*tmp1;
	char	*tmp2;
	
	tmp1 = ft_strjoin(str, "\"");
	tmp2 = ft_strjoin("\"", tmp1);
	free(tmp1);
	return(tmp2);
}

char	*ft_connect_str_in_one(char **strings, int i_start, int argc)
{
	int		i;
	char	*tmp1;
	char	*tmp2;

	i = -1;
	tmp1 = NULL;
	tmp2 = NULL;
	while (i_start < argc)
	{
		if(!(tmp1))
			tmp1 = ft_strjoin(strings[i_start], strings[i_start + 1]);
		else
		{
			if((tmp2))
				free(tmp2);
			tmp2 = ft_strdup(tmp1);
			free(tmp1);
			tmp1 = ft_strjoin(tmp2, strings[i_start + 1]);
		}
		i_start++;
	}
	free(tmp2);
	return (tmp1);
}

void	ft_export_without_equal_sign(t_pl *pl, char *str)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = ft_strjoin(str, "=");
	while(++i < pl->export.size && (ft_strcmp(pl->export.arr[i], str)));
	if (i == pl->export.size)
		if ((i = ft_find_string_int(pl->export.arr, tmp)) < 0)
		{
			ft_add_line_in_arr(&pl->export, str, 0);
			ft_add_line_in_arr(&pl->envp, str, 1);
		}
	free(tmp);
}

void	ft_export_with_equal_sign(t_pl *pl, char *str, char **cmd)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	j = -1;
	while(++i < pl->export.size && (ft_strcmp(pl->export.arr[i], cmd[0])));
	if ((i == pl->export.size) &&
		((j = ft_find_string_int(pl->export.arr, cmd[1])) < 0))
		{
			tmp = ft_strjoin(cmd[1], cmd[3]);
			ft_add_line_in_arr(&pl->export, tmp, 0);
			ft_add_line_in_arr(&pl->envp, str, 0);
			free(tmp);
		}
	else
	{
		if (i != pl->export.size)
			j = i;
		free(pl->export.arr[j]);
		free(pl->envp.arr[j]);
		pl->export.arr[j] = ft_strjoin(cmd[1], cmd[3]);
		pl->envp.arr[j] = ft_strjoin(cmd[1], cmd[2]);
		pl->export.key_ignore[j] = 0;
		pl->envp.key_ignore[j] = 0;
	}
}

void	ft_export_parser(t_pl *pl, char *str)
{
	char	**cmd;
	int		len;
	int		i;

	if (!(ft_isalpha(str[0])) && str[0] != '_')
		ft_error_valid_identifier("export", str);
	cmd = ft_calloc(sizeof(char*), 5);
	i = 0;
	len = ft_strlen(str);
	while (str[i] && str[i] != '=')
		i++;
	if (i == len)
		ft_export_without_equal_sign(pl, str);
	else
	{
		cmd[0] = ft_strdup_len(str, i);
		cmd[1] = ft_strdup_len(str, i + 1);
		cmd[2] = ft_strdup_from(str, i + 1);
		cmd[3] = ft_take_str_in_quotes(cmd[2]);
		ft_export_with_equal_sign(pl, str, cmd);
	}
	ft_free_arr(cmd);
}

void	ft_export(t_pl *pl, int cmd_i)
{
	int		cmd_argc;
	int		j;

	cmd_argc = ft_count_cmd_argv(pl, cmd_i);
	if (cmd_argc == 1)
		ft_sort_arr_and_print(&pl->export, -1, -1);
	else
	{
		j = 0;
		while (++j < cmd_argc)
			ft_export_parser(pl, pl->cmd.argv[cmd_i][j]);
	}
}