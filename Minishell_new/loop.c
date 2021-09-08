/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:49:33 by mpowder           #+#    #+#             */
/*   Updated: 2021/09/08 12:00:28 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl(int sig)
{
	rl_on_new_line();
	rl_redisplay();
	write(1, "  ", 2);
	printf("\n");
	rl_on_new_line();
	// rl_replace_line("", 0);
	rl_redisplay();
}

void	loop(t_pl *pl)
{
	char			*buff;
	char			*pipe_line;
	struct termios	term;

	while (1)
	{
		// tcgetattr(0, &term);
		// term.c_lflag &= ~(ECHOCTL);
		// term.c_lflag &= ~(ICANON);
		// tcsetattr(0, TCSANOW, &term);
		buff = readline("minishell$ ");
		// term.c_lflag |= ~(ICANON);
		// term.c_lflag |= ~(ECHOCTL);
		// tcsetattr(0, TCSANOW, &term);
		// signal(SIGINT, ctrl);
		// signal(SIGQUIT, ctrl);
		if (!buff)
		{
			write(1, "exit\n", 5);
			break ;
		}
		if (ft_strncmp(buff, "\0", 1))
		{
			add_history(buff);
			pipe_line = str_check(buff, pl);
			ft_start_comands(pl, pipe_line);
		}
		free(buff);
	}
}