/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:58:42 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/21 13:35:34 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_error_undefined_error(char *name)
{
	write(2, "minishell: ", 11);
	write(2, name, ft_strlen(name));
	write(2, ": Undefined error: 0\n", 21);
	cmd_exit = 1;
	exit(1);
}

void	ft_error_oldpwd(char *name)
{
	write(2, "minishell: ", 11);
	write(2, name, ft_strlen(name));
	write(2, ": OLDPWD not set\n", 17);
	cmd_exit = 1;
	exit(1);
}

void	ft_error_malloc()
{
	write(2, "minishell: malloc: ", 20);
	write(2, "Cannot allocate memory\n", 23);
	cmd_exit = 2;
	exit(2);
}

void	ft_error_directory(char *cmd_name, char *argv_name)
{
	write(2, "minishell: ", 11);
	write(2, cmd_name, ft_strlen(cmd_name));
	write(2, ": ", 2);
	write(2, argv_name, ft_strlen(argv_name));
	write(2, ": No such file or directory\n", 28);
	cmd_exit = 1;
	// exit(1);
}

void	ft_error_cmd_not_found(char *name)
{
	write(2, "minishell: ", 11);
	write(2, name, ft_strlen(name));
	write(2, ": command not found\n", 20);
	cmd_exit = 127;
	// exit(127);
}

// void	ft_error (int i)
// {
// 	if (i == -1)
// 		write(1, "Error with memory allocation\n", 29);
// 	if (i == -2)
// 		write(1, "Erorr with creating fork\n", 25);
	
// 	perror("fork");
// 	exit(EXIT_FAILURE);

// 	perror("pipe");
//     exit(EXIT_FAILURE);
// }