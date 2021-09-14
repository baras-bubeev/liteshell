/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 19:01:56 by kseniakozyr       #+#    #+#             */
/*   Updated: 2021/09/11 01:07:29 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

void	ft_pwd(t_pl *pl)
{
	int		len;
	char	*tmp;

	tmp = getcwd(NULL, 0);
	if (tmp != NULL)
	{
		len = ft_strlen(tmp);
		write(1, tmp, len);
		write(1, "\n", 1);
		free(tmp);
	}
	else
	{
		tmp = ft_find_string_char(pl, "PWD=");
		len = ft_strlen(tmp);
		write(1, tmp, len);
		write(1, "\n", 1);
		free(tmp);
	}
}
