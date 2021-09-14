/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 23:17:48 by jkorey            #+#    #+#             */
/*   Updated: 2021/09/11 00:59:19 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset_parser_utils(t_pl *pl, int *j, int i)
{
	if (i != pl->export.size)
		*j = i;
	pl->envp.key_ignore[*j] = 1;
	pl->export.key_ignore[*j] = 1;
}

void	ft_unset_parser(t_pl *pl, char *str)
{
	char	*cmd_1;
	int		i;
	int		j;

	i = -1;
	j = 1;
	while (str[++i] && j)
	{
		if (!(ft_isalpha(str[i])) && str[i] != '_')
		{
			ft_error_valid_identifier("unset", str);
			return ;
		}
	}
	cmd_1 = ft_strjoin(str, "=");
	i = -1;
	j = -1;
	while (++i < pl->export.size && (ft_strcmp(pl->export.arr[i], str)))
		;
	j = ft_find_string_int(pl->export.arr, cmd_1);
	if (i != pl->export.size || j >= 0)
		ft_unset_parser_utils(pl, &j, i);
	free(cmd_1);
}

void	ft_unset(t_pl *pl, int cmd_i)
{
	int		cmd_argc;
	int		j;

	cmd_argc = ft_count_cmd_argv(pl, cmd_i);
	if (cmd_argc != 1)
	{
		j = 0;
		while (++j < cmd_argc)
			ft_unset_parser(pl, pl->cmd.argv[cmd_i][j]);
	}
}
