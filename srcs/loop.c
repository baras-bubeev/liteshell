/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:49:33 by mpowder           #+#    #+#             */
/*   Updated: 2021/09/10 15:08:11 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ctrl(int sig)
{
	rl_on_new_line();
	rl_redisplay();
	write(1, "  ", 2);
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	loop(t_pl *pl)
{
	char			*buff;
	char			*pipe_line;
	struct termios	term;

	while (1)
	{
		signal(SIGINT, ctrl);
		signal(SIGQUIT, SIG_IGN);
		tcgetattr(1, &term);
		term.c_lflag &= ~(ECHOCTL);
		tcsetattr(1, TCSANOW, &term);
		buff = readline("minishell$ ");
		term.c_lflag |= ECHOCTL;
		tcsetattr(1, TCSANOW, &term);
		if (!buff)
			break ;
		if (ft_strncmp(buff, "\0", 1))
		{
			add_history(buff);
			pl->pipe_line = str_check(buff, pl);
			ft_start_comands(pl);
		}
		free(buff);
	}
	ft_putstr_fd("\e[1F\e[12Gexit\n", 1);
}