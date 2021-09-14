/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 23:17:11 by jkorey            #+#    #+#             */
/*   Updated: 2021/09/11 08:53:43 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_exit_my(char *err_msg)
{
	printf("%s\n", err_msg);
	g_cmd_exit = 1;
	return (0);
}

void	ft_exit(t_pl *pl, int cmd_i, int j)
{
	int	cmd_argc;
	int	len;

	cmd_argc = ft_count_cmd_argv(pl, cmd_i);
	if (cmd_argc == 1)
		exit(0);
	else if (cmd_argc > 2)
		ft_error_too_many_argv("exit");
	len = ft_strlen(pl->cmd.argv[cmd_i][1]);
	if (pl->cmd.argv[cmd_i][1][0] == '-')
		j = 1;
	while ((pl->cmd.argv[cmd_i][1]) && ((pl->cmd.argv[cmd_i][1][j] >= '0'
	&& pl->cmd.argv[cmd_i][1][j] <= '9')))
		j++;
	if (len != j)
		ft_error_numeric("exit", pl->cmd.argv[cmd_i][1]);
	j = ft_atoi(pl->cmd.argv[cmd_i][1]);
	if (j <= -256 && j != 0)
		j = ((((-j / 256) + 1) * 256) + j);
	else if (j >= 256 && j != 0)
		j = j - ((j / 256) * 256);
	g_cmd_exit = j;
	exit (g_cmd_exit);
}
