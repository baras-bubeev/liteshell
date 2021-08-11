#include "minishell.h"

//	', ", $, >, <, >>, <<, |

int main(int ac, char **av, char **env)
{
	char	*buff;
	// t_env	*envp;
	// int i = 0;
	(void)ac;
	(void)av;
	while (1)
	{
		buff = readline("minishell$ ");
		if (ft_strncmp(buff, "\0", 1))
		{
			add_history(buff);
			str_check(buff, env);
		}
		free(buff);
	}
	
	// char s[] = "jds$a bc $123vnsdv ' sdvsd\"vs$USER dg'\"s'sdv$USER fc \"   'sdsdvsd' ";
	// char *s2 = "";
	// printf("%s\n", ft_strjoin(s, s2));
	// while (++i < ac)
	// 	parser(av[i]);
	// str_check(s, env);
	printf("\n");
	return (0);
}