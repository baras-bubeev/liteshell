/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 06:16:46 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/21 13:27:59 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_error_subject(char *name, char *condition)
{
	int len;

	len = ft_strlen(name);
	write(2, "minishell: ", 11);
	write(2, name, len);
	write(2, ": Oops! We should use '", 23);
	write(2, name, len);
	write(2, "' ", 2);
	write(2, condition, ft_strlen(condition));
	write(2, "\n", 1);
	cmd_exit = 1;
}