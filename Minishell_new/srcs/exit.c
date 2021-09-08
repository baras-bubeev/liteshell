#include "../minishell.h"

void    ft_exit_my(int err_code, char *err_msg)
{
    printf("%s\n", err_msg);
    exit(err_code);
}