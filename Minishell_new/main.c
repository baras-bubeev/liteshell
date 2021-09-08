/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:19:57 by jkorey            #+#    #+#             */
/*   Updated: 2021/09/08 01:44:45 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_set_cmd_flag(t_pl *pl, char *pipe_line)
{
	int		i;

	if (pl->round_counter > 0)
		pl->cmd.old_flag = pl->flag;
	i = -1;
	pl->flag = 0;
	while (pipe_line[++i] && pl->flag == 0)
	{
		if (pipe_line[i] == '|')
			pl->flag = 1;
		else if (pipe_line[i] == '>' || pipe_line[i] == '<')
			pl->flag = 3;
	}
	if (pl->flag == 0)
	{
		if (!(ft_if_builtin(pl, 0, "echo cd pwd export unset env exit", 0, 0)))
			pl->flag = 1;
		else
			pl->flag = 2;
	}
}

void	ft_mute_oldpwd(t_pl *pl)
{
	int		i;
	int		count;

	i = -1;
	count = 1;
	while (++i < pl->envp.size && count)
	{
		if (!(ft_strncmp("OLDPWD=", pl->envp.arr[i], 7)))
		{
			pl->envp.key_ignore[i] = 0;
			pl->export.key_ignore[i] = 0;
			free(pl->export.arr[i]);
			ft_swap_str_in_arr(pl->envp.arr, pl->envp.key_ignore, i, pl->envp.size - 1);
			pl->export.arr[i] = ft_strdup("OLDPWD");
			ft_swap_str_in_arr(pl->export.arr, pl->export.key_ignore, i, pl->envp.size - 1);
			count = 0;
			free(pl->envp.arr[pl->envp.size - 1]);
			pl->envp.arr[pl->envp.size - 1] = NULL;
		}
		else
		{
			pl->envp.key_ignore[i] = 0;
			pl->export.key_ignore[i] = 0;
		}
	}
}

void	ft_clean_variables(t_pl *pl)
{
	int		i;

	if ((pl->flag == 1 || pl->flag == 2))
	{
		ft_free_pids(pl);
		i = -1;
		while (pl->cmd.argv[++i])
			ft_free_arr(pl->cmd.argv[i]);
		free(pl->cmd.argv);
		ft_free_arr(pl->cmd.name);
		ft_free_arr(pl->cmd.right_path);
		free(pl->pipe_line);
	}
}

void	ft_prepare_variables(t_pl *pl, int round_counter)
{
	if (round_counter == 0)
	{
		pl->envp.key_ignore = (int*)ft_calloc(pl->envp.size + 60, sizeof(int));
		pl->export.key_ignore = (int*)ft_calloc(pl->export.size + 60, sizeof(int));
		ft_mute_oldpwd(pl);
		pl->fd_0 = dup(0);
		pl->fd_1 = dup(1);
		pl->p.fd = NULL;
		pl->cmd.argv = NULL;
		pl->cmd.name = NULL;
		pl->cmd.right_path = NULL;
		ft_path(pl);
	}
}

void	ft_start_comands(t_pl *pl, char *pipe_line)
{
	pl->round_counter++;
	ft_prepare_variables(pl, pl->round_counter);
	pl->pipe_line = ft_strdup(pipe_line);
	ft_set_cmd_flag(pl, pipe_line);
	if (pl->flag == 1)
		ft_fork(pipe_line, pl, -1);
	if (pl->flag == 2)
		ft_single_builtin(pipe_line, pl, -1);
	ft_clean_variables(pl);
	// else if (pl->flag == 3)
	// 	ft_redirect(pipe_line, pl);
	
	// int	i = -1;
	// while(pl->envp.arr[++i])
	// 	printf("%d = %d = %s\n", i, pl->export.key_ignore[i], pl->envp.arr[i]);
}

int		main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	t_pl	pl;
	// char	*buff;
	/*
// 	char *env[] = {
// "USER=kseniakozyreva",
// "__CFBundleIdentifier=com.microsoft.VSCode",
// "COMMAND_MODE=unix2003",
// "LOGNAME=kseniakozyreva",
// "PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/bin",
// "SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.rOMSuAVY13/Listeners",
// "SHELL=/bin/zsh",
// "HOME=/Users/kseniakozyreva",
// "__CF_USER_TEXT_ENCODING=0x1F5:0x7:0x31",
// "TMPDIR=/var/folders/0x/y_yjywn56lddss4kp7kmtcy40000gn/T/",
// "XPC_SERVICE_NAME=0",
// "XPC_FLAGS=0x0",
// "ORIGINAL_XDG_CURRENT_DESKTOP=undefined",
// "SHLVL=1",
// "PWD=/Users/kseniakozyreva/Downloads/Minishell_new",
// "OLDPWD=/Users/kseniakozyreva/Downloads",
// "TERM_PROGRAM=vscode",
// "TERM_PROGRAM_VERSION=1.58.2",
// "LANG=en_US.UTF-8",
// "COLORTERM=truecolor",
// "VSCODE_GIT_IPC_HANDLE=/var/folders/0x/y_yjywn56lddss4kp7kmtcy40000gn/T/vscode-git-40e9285752.sock",
// "GIT_ASKPASS=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass.sh",
// "VSCODE_GIT_ASKPASS_NODE=/Applications/Visual Studio Code.app/Contents/Frameworks/Code Helper (Renderer).app/Contents/MacOS/Code Helper (Renderer)",
// "VSCODE_GIT_ASKPASS_MAIN=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass-main.js",
// "TERM=xterm-256color",
// "_=/usr/bin/env",
// NULL
// };
*/
	// char	*pipe_line = "ls | grep m | cat -e";
	char	*pipe_line;
	char	*pipe_line2 = "grep m | cat -e";
	char	*pipe_line3 = "echo a";
	char	*pipe_line4 = "env";
	char	*pipe_line5 = "export a";
	char	*pipe_line6 = "unset a";
	char	*pipe_line7 = "ls | cat -e";
	char	*pipe_line8 = "env | grep PWD";
	char	*pipe_line9 = "export HELLO | pwd";
	pl.round_counter = -1;
	cmd_exit = 0;
	pl.envp.arr = ft_make_arr_copy(&pl.envp.size, env);
	pl.export.arr = ft_make_arr_copy(&pl.export.size, env);
	ft_shlvl(&pl);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ctrl);
	loop(&pl);
	// ft_start_comands(&pl, pipe_line);
	// ft_start_comands(&pl, pipe_line2);
	// while (1)
	// {
	// 	// signal(SIGINT, ctrl_c);
	// 	// signal(SIGQUIT, ctrl_c);
	// 	buff = readline("minishell$ ");
	// 	if (!buff)
	// 	{
	// 		printf("exit\n");
	// 		break ;
	// 	}
	// 	if (ft_strncmp(buff, "\0", 1))
	// 	{
	// 		add_history(buff);
	// 		pipe_line = str_check(buff, pl.envp.arr);
	// 		ft_start_comands(&pl, pipe_line);
	// 	}
	// 	free(buff);
	// }
	
	// ft_start_comands(&pl, pipe_line3);

	// ft_start_comands(&pl, pipe_line4);
	// ft_start_comands(&pl, pipe_line5);
	// ft_start_comands(&pl, pipe_line6);

	// ft_start_comands(&pl, pipe_line7);
	// ft_start_comands(&pl, pipe_line8);
	// ft_start_comands(&pl, pipe_line9);
	// sleep (10000);
	return (0);
}
