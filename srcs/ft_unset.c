/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 23:17:48 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/26 14:01:52 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset_parser(t_pl *pl, char *str)
{
	char	*cmd_1;
	int		i;
	int		j;

	i = -1;
	j = 1;
	while(str[++i] && j)
		if (!(ft_isalpha(str[i])) && str[i] != '_')
		{
			ft_error_valid_identifier("unset", str);
			j = 0;
			return ;
		}
	cmd_1 = ft_strjoin(str, "=");
	i = -1;
	j = -1;
	while(++i < pl->export.size && (ft_strcmp(pl->export.arr[i], str)));
	if ((i != pl->export.size) ||
		((j = ft_find_string_int(pl->export.arr, cmd_1)) >= 0))
	{
		if (i != pl->export.size)
			j = i;
		pl->envp.key_ignore[j] = 1;
		pl->export.key_ignore[j] = 1;
	}
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