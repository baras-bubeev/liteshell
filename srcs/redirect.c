/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 10:59:39 by mpowder           #+#    #+#             */
/*   Updated: 2021/09/10 21:07:39 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	double_redirect(char *str)
{
	int		fd;
	char	*buff;

	fd = open(".tmp", O_WRONLY | O_CREAT | O_APPEND, 0644);
	buff = readline("> ");
	if (!buff)
		return (close(fd) - 1);
	while (ft_strcmp(str, buff))
	{
		ft_putendl_fd(buff, fd);
		free(buff);
		buff = readline("> ");
		if (!buff)
			break ;
	}
	close(fd);
	free(buff);
	fd = open(".tmp", O_RDONLY, 0666);
	return (fd);
}

char	*get_fname(char *str, int *i)
{
	int	strt;
	int	len;

	strt = 0;
	if (str[0] == '>' || str[0] == '<')
	{
		write(2, "minishell: syntax error near unexpected token `", 47);
		ft_putchar_fd(str[0], 2);
		write(2, "'\n", 2);
		return (0);
	}
	while (str[strt] == ' ' || str[strt] == '\t')
		strt++;
	len = 0;
	while (str[strt + len] && str[strt + len] != ' ' && str[strt + len] != '\t')
		len++;
	*i += strt + len;
	return (ft_substr(str, strt, len));
}

int	get_fd_out(char *fname, int fl)
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

int	get_fd_in(char *fname, int fl)
{
	int	fd;

	if (fl == 0)
	{
		fd = open(fname, O_RDONLY, 0666);
		if (fd == -1)
		{
			write(2, "Minishell: ", 11);
			write(2, fname, ft_strlen(fname));
			write(2, ": No such file or directiry\n", 28);
		}
	}
	else
		fd = double_redirect(fname);
	return (fd);
}

void	redirect(char *str, int *i, t_pl *pl, char redir)
{
	int		heredoc;
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
	if (!fname)
		return ;
	if (redir == '>')
		pl->fd_out = get_fd_out(fname, heredoc);
	else
		pl->fd_in = get_fd_in(fname, heredoc);
	free(fname);
	ft_strlcat(str, str + (*i), slen);
}
