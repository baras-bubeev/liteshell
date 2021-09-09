/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 10:59:39 by mpowder           #+#    #+#             */
/*   Updated: 2021/09/09 20:26:04 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_fname_out(char *str, int *i)
{
	int start;
	int	len;

	start = 0;
	while (str[start] == ' ' || str[start] == '\t')
		start++;
	len = 0;
	while (str[start + len] && str[start + len] != ' ' && str[start + len] != '\t')
		len++;
	*i += start + len;
	return (ft_substr(str, start, len));
}

int		get_fd_out(char *fname, int fl) // close fd
{
	int	fd;

	if (fl == 1)
		fd = open(fname, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(fname, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		write(2, "The file '", 10);
		write(2, fname, ft_strlen(fname));
		write(2, "' does not exist\n", 17);
	}
	return (fd);
}

void	redirect_out(char *str, int *i, t_pl *pl)
{
	int 	heredoc;
	char	*fname;
	int		slen;

	pl->flag = 3;
	heredoc = 0;
	slen = ft_strlen(str);
	str[*i] = 0;
	if (str[++(*i)] == '>')
	{
		heredoc = 1;
		(*i)++;
	}
	fname = get_fname_out(str + (*i), i);
	pl->fd_out = get_fd_out(fname, heredoc);
	free(fname);
	ft_strlcat(str, str + *i, slen);
}