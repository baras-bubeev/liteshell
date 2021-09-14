/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:58:42 by jkorey            #+#    #+#             */
/*   Updated: 2021/09/11 02:16:31 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_error_undefined_error(char *name)
{
	write(2, "minishell: ", 11);
	write(2, name, ft_strlen(name));
	write(2, ": Undefined error: 0\n", 21);
	g_cmd_exit = 1;
	exit(1);
}

void	ft_error_oldpwd(char *name)
{
	write(2, "minishell: ", 11);
	write(2, name, ft_strlen(name));
	write(2, ": OLDPWD not set\n", 17);
	g_cmd_exit = 1;
	exit(1);
}

void	ft_error_malloc(void)
{
	write(2, "minishell: malloc: ", 20);
	write(2, "Cannot allocate memory\n", 23);
	g_cmd_exit = 2;
	exit(2);
}

void	ft_error_directory(char *cmd_name, char *argv_name)
{
	write(2, "minishell: ", 11);
	write(2, cmd_name, ft_strlen(cmd_name));
	write(2, ": ", 2);
	write(2, argv_name, ft_strlen(argv_name));
	write(2, ": No such file or directory\n", 28);
	g_cmd_exit = 1;
}

void	ft_error_cmd_not_found(char *name)
{
	write(2, "minishell: ", 11);
	write(2, name, ft_strlen(name));
	write(2, ": command not found\n", 20);
	g_cmd_exit = 127;
}
