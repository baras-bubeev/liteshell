/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:55:11 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/27 21:45:33 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(t_pl *pl, int cmd_i)
{
	int		cmd_argc;
	int		j;

	cmd_argc = ft_count_cmd_argv(pl, cmd_i);
	j = 0;
	if (cmd_argc == 1)
		write(1, "\n", 1);
	else
	{
		if (!(strcmp(pl->cmd.argv[cmd_i][1], "-n")))
			j = 2;
		while (j < cmd_argc - 1)
		{
			write(1, pl->cmd.argv[cmd_i][j], ft_strlen(pl->cmd.argv[cmd_i][j]));
			write(1, " ", 1);
			j++;
		}
		write(1, pl->cmd.argv[cmd_i][j], ft_strlen(pl->cmd.argv[cmd_i][j]));
		if ((strcmp(pl->cmd.argv[cmd_i][0], "-n")))
			write(1, "\n", 1);
	}
}