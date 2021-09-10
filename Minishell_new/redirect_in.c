/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 23:35:25 by mpowder           #+#    #+#             */
/*   Updated: 2021/09/09 23:36:59 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_in(char *str, int *i, t_pl *pl)
{
	int 	heredoc;
	char	*fname;
	int		slen;

    heredoc = 0;
}