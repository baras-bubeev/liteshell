/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 10:59:39 by mpowder           #+#    #+#             */
/*   Updated: 2021/09/08 12:37:04 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_output_fname(char *str)
{
	int start;
	int	len;

	start = 0;
	while (str[start] == ' ' || str[start] == '\t')
		start++;
	len = 0;
	while (ft_isalnum(str[start + len])) /// какие символы может содержать имя файла????
		len++;
	return (ft_substr(str, start, len));
}

int		get_output_fd(char *fname, int fl)
{

}

void	redirect_out(char *str, int *i, t_pl *pl)
{
	if (str[*i] == '>' && str[++(*i)] == '>')
	{
		pl->redir.heredoc = 1;
		(*i)++;
	}
	pl->redir.output_fname = get_output_fname(str + (*i));
	pl->redir.output_fd = get_output_fd(pl->redir.output_fname, pl->redir.heredoc);
}