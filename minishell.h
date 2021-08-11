#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "readline/readline.h"
# include "readline/history.h"
# include <term.h>
# include "libft/libft.h"

# define PIPE_ERROR "bash: syntax error near unexpected token `|'"
# define APOSTROPHE_ERROR "bash: unexpected EOF while looking for matching `\''"
# define QUOTE_ERROR "bash: unexpected EOF while looking for matching `\"'"

typedef struct s_env
{
	char			*path;
	char			*value;
	struct s_env	*next;	
}	t_env;

int		str_check(char *str, char **envp);
void	ft_exit(int err_code, char *err_msg);

#endif