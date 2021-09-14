/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 21:08:01 by mpowder           #+#    #+#             */
/*   Updated: 2021/09/11 06:19:22 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*apostrophe(char *str, int *i)
{
	int	slen;

	slen = ft_strlen(str);
	str[*i] = 0;
	ft_strlcat(str, str + *i + 1, slen);
	while (str[*i] && str[*i] != '\'')
		(*i)++;
	if (str[*i] == 0)
		return (ft_exit_my(APSTR_ERROR));
	str[*i] = 0;
	ft_strlcat(str, str + *i + 1, slen);
	return (str);
}

char	*get_value(char *str, int *i, int j, char **envp)
{
	char	*key;

	if (ft_isdigit(str[*i]))
		(*i)++;
	else
		while (str[*i] == '_' || ft_isalnum(str[*i]))
			(*i)++;
	if ((*i) - j == 1)
		return (str);
	key = ft_substr(str, j + 1, (*i) - j - 1);
	key = key_search(&key, envp);
	return (key);
}

char	*dollar(char *str, int *i, char **envp)
{
	int		j;
	char	*key;
	char	*tmp;

	j = (*i)++;
	if (str[*i] == '?')
	{
		key = ft_strdup(ft_itoa(g_cmd_exit));
		(*i)++;
	}
	else
	{
		key = get_value(str, i, j, envp);
		if (key == str)
			return (str);
	}
	str[j] = 0;
	tmp = ft_strjoin(str, key);
	free(key);
	key = ft_strjoin(tmp, str + (*i));
	*i = ft_strlen(tmp) - 1;
	free(tmp);
	return (key);
}

char	*quote(char *str, int *i, char **envp)
{
	int	slen;

	slen = ft_strlen(str);
	str[*i] = 0;
	ft_strlcat(str, str + *i + 1, slen);
	while (str[*i] && str[*i] != '\"')
	{
		if (str[*i] == '$')
			str = dollar(str, i, envp);
		(*i)++;
	}
	if (str[*i] == 0)
		return (ft_exit_my(QUOTE_ERROR));
	str[*i] = 0;
	ft_strlcat(str, str + (*i) + 1, slen);
	return (str);
}

char	*str_check(char *str, t_pl *pl)
{
	int	i;

	i = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	if (!count_pipe(str, pl))
		return (0);
	while (str && str[i])
	{
		if (str[i] == '\'')
			str = apostrophe(str, &i);
		else if (str[i] == '\"')
			str = quote(str, &i, pl->envp.arr);
		else if (str[i] == '>' || str[i] == '<')
			redirect(str, &i, pl, str[i]);
		else if (str[i] == '$')
			str = dollar(str, &i, pl->envp.arr);
		i++;
	}
	i = 0;
	while (str && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (!str || !str[i])
		return (0);
	return (ft_strdup(str));
}
