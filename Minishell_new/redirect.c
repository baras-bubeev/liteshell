/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 10:59:39 by mpowder           #+#    #+#             */
/*   Updated: 2021/09/10 02:41:58 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_fname(char *str, int *i)
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

int		get_fd_in(char *fname, int fl)
{
	int	fd;

	if (fl == 0)
		fd = open(fname, O_RDONLY, 0666);
	else
		fd = 0;
	if (fd == -1)
	{
		write(2, "Minishell: ", 11);
		write(2, fname, ft_strlen(fname));
		write(2, ": No such file or directiry\n", 28);
	}
	return (fd);
}

void	redirect(char *str, int *i, t_pl *pl, char redir)
{
	int 	heredoc;
	char	*fname;
	int		slen;

	pl->flag = 3;
	heredoc = 0;
	slen = ft_strlen(str);
	if (str[*i] == '>' && str[(*i) + 1] == '>')
		heredoc = 1;
	else if (str[*i] == '<' && str[(*i) + 1] == '<')
		heredoc = 1;
	str[*i] = 0;
	if (heredoc)
		(*i)++;
	fname = get_fname(str + (++(*i)), i);
	if (redir == '>')
		pl->fd_out = get_fd_out(fname, heredoc);
	else
		pl->fd_in = get_fd_in(fname, heredoc);
	free(fname);
	ft_strlcat(str, str + (*i), slen);
}