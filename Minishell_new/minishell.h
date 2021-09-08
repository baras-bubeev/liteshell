/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:20:11 by jkorey            #+#    #+#             */
/*   Updated: 2021/09/08 12:22:19 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <string.h>
# include <fcntl.h>
# include "minishell2.h"
# include <termios.h>

int	cmd_exit;

// key_ignore = 1 - игнорировать
// key_ignore = 0 - работать

typedef struct		s_size
{
	char	**arr;
	int		*key_ignore;
	int		size;
	// int		oldsize;
	// int		newsize;
	int		oldpwd;
	int		pwd;

}					t_size;

// cmd_flag = 1 - pipe and not subject cmd;
// cmd flag = 2 - simple builtin comand;
// cmd flag = 3 - redirect;

typedef struct		s_pipe
{
	int		npipes;
	int		fd_0;
	int		fd_1;
	int		*pids;
	pid_t	pid;
	int		**fd;
}					t_pipe;

//структура нижнего уровня - для команд (внутри ;)
typedef struct		s_cmd
{
	char	***argv;
	char	**name;
	char	**right_path;
	int		old_flag;
}					t_cmd;

typedef struct		s_redirect
{
	char	*output_fname;
	char	*input_fname;
	int		heredoc;
	int		output_fd;
	int		input_fd;
}					t_redirect;


//структура верхнего уровня - для пайплайнов (до ;)
typedef struct		s_pl
{
	t_size		envp;
	t_size		export;
	t_pipe		p;
	t_cmd		cmd;
	t_redirect	redir;
	int			fd_0;
	int			fd_1;
	char		*pipe_line;
	int			flag;
	int			round_counter;
	char		**path;
}					t_pl;

void	ft_add_line_in_arr(t_size *arr, char *line, int key_ignore);
void	*ft_calloc(size_t count, size_t size);
void	ft_cd(t_pl *pl, int cmd_i);
void	ft_cd_to_home_directory(t_pl *pl, int cmd_i);
void	ft_cd_to_top_directory(t_pl *pl, int cmd_i);
void	ft_cd_with_dot(t_pl *pl, int cmd_i);
void	ft_cd_with_path(t_pl *pl, int cmd_i);
void	ft_child_process(t_pl *pl, int i);
void	ft_close_fd(int npipes, int pipes[][2]);
void	ft_concatenate_str_in_arr(char **arr, int arr_size, char *str);
int		ft_count_char(char *str, char a);
int		ft_count_cmd_argv(t_pl *pl, int cmd_i);
void	ft_echo(t_pl *pl, int cmd_i);
void	ft_env(t_pl *pl, int cmd_i);
void	ft_error_cmd_not_found(char *name);
void	ft_error_valid_identifier(char *name, char *condition);
void	ft_error_directory(char *cmd_name, char *argv_name);
void	ft_error_malloc();
void	ft_error_not_set_name(char *name, char *condition);
void	ft_error_numeric(char *name, char *condition);
void	ft_error_oldpwd(char *name);
void	ft_error_subject(char *name, char *condition);
void	ft_error_too_many_argv(char *name);
void	ft_error_undefined_error(char *name);
void	ft_error (int i);
void	ft_execve(int cmd_i, t_pl *pl);
void	ft_exit(t_pl *pl, int cmd_i, int j);
void	ft_export(t_pl *pl, int cmd_i);
void	ft_export_without_equal_sign(t_pl *pl, char *str);
int		ft_find_cmd_path(int name, t_pl *pl);
char	*ft_find_string_char(t_pl *pl, char *name);
int		ft_find_string_int(char **arr, char *name);
void	ft_fork(char *pipe_line, t_pl *pl, int i);
void	ft_free_arr(char **arr);
void	ft_free_pids(t_pl *pl);
int		ft_if_builtin(t_pl *pl, int cmd_i, char *builtin, int key, int size);
int		ft_is_exec(char *path);
char	**ft_make_arr_copy(int *size, char **arr);
void	ft_npipes(char *pipe_line, t_pl *pl);
void	ft_parse_pipe_line(char *pipe_line, t_pl *pl);
void	ft_path(t_pl *pl);
void	ft_prepare_variables(t_pl *pl, int round_counter);
void	ft_print_arr(char **arr, int *key_ignore, int type);
void	ft_pwd(t_pl *pl);
void	ft_replace_key_in_arr(char *str, char *key, char *new_key);
void	ft_replace_mining_in_arr(char *str, char *key, char *new_mining);
void	ft_set_cmd_flag(t_pl *pl, char *pipe_line);
void	ft_shlvl(t_pl *pl);
void	ft_single_builtin(char *pipe_line, t_pl *pl, int i);
void	ft_sort_arr_and_print(t_size *arr, int i, int j);
void	ft_start_builtin(t_pl *pl, int cmd_i);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup_from(const char *s1, int start);
char	*ft_strdup_len(const char *s1, int len);
void	ft_swap_key_in_envp(t_pl *pl, char *key1, char *key2);
void	ft_swap_str_in_arr(char **arr, int	*key_ignore, int str1, int str2);
void	ft_unset(t_pl *pl, int cmd_i);
void	ft_waitpid(t_pl *pl, int i);
void	loop(t_pl *pl);
void	ft_start_comands(t_pl *pl, char *pipe_line);
char	*str_check(char *str, t_pl *pl);

#endif
