/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_single_buildin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 20:57:58 by jkorey            #+#    #+#             */
/*   Updated: 2021/09/11 01:06:19 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
void	ft_single_builtin(char *pipe_line, t_pl *pl, int i)
{
	(void)i;
	ft_npipes(pipe_line, pl);
	ft_parse_pipe_line(pipe_line, pl);
	ft_start_builtin(pl, 0);
}
