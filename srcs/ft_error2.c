/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 06:16:46 by jkorey            #+#    #+#             */
/*   Updated: 2021/09/11 02:16:47 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_error_subject(char *name, char *condition)
{
	int	len;

	len = ft_strlen(name);
	write(1, "minishell: ", 11);
	write(1, name, len);
	write(1, ": Oops! We should use '", 23);
	write(1, name, len);
	write(1, "' ", 2);
	write(1, condition, ft_strlen(condition));
	write(1, "\n", 1);
	g_cmd_exit = 1;
}

void	ft_error_valid_identifier(char *name, char *condition)
{
	int	len;

	len = ft_strlen(name);
	write(1, "minishell: ", 11);
	write(1, name, len);
	write(1, ": '", 1);
	write(1, condition, ft_strlen(condition));
	write(1, "' not a valid identifier", 24);
	write(1, "\n", 1);
	g_cmd_exit = 1;
}

void	ft_error_not_set_name(char *name, char *condition)
{
	int	len;

	len = ft_strlen(name);
	write(1, "minishell: ", 11);
	write(1, name, len);
	write(1, ": ", 1);
	write(1, condition, ft_strlen(condition));
	write(1, " not set", 8);
	write(1, "\n", 1);
	g_cmd_exit = 1;
}

void	ft_error_too_many_argv(char *name)
{
	int	len;

	len = ft_strlen(name);
	write(1, "minishell: ", 11);
	write(1, name, len);
	write(1, ": too many arguments", 20);
	write(1, "\n", 1);
	g_cmd_exit = 258;
}

void	ft_error_numeric(char *name, char *condition)
{
	int	len;

	len = ft_strlen(name);
	write(1, "minishell: ", 11);
	write(1, name, len);
	write(1, ": ", 1);
	write(1, condition, ft_strlen(condition));
	write(1, ": numeric argument required", 26);
	write(1, "\n", 1);
	g_cmd_exit = 258;
	exit(258);
}
