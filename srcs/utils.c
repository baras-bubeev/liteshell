/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 23:54:45 by mpowder           #+#    #+#             */
/*   Updated: 2021/09/11 06:18:00 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*key_search(char **key, char **envp)
{
	int		i;
	int		keylen;
	char	*tmp;

	i = 0;
	keylen = ft_strlen(*key);
	tmp = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], *key, keylen))
		{
			if (envp[i][keylen] == '=' && keylen++)
				tmp = ft_substr(envp[i], keylen, ft_strlen(envp[i]) - keylen);
		}
		i++;
	}
	if (!tmp)
		tmp = ft_strdup("");
	free(*key);
	return (tmp);
}

void	ft_mute_oldpwd_utils(t_pl *pl, int i, int *count)
{
	if ((ft_strncmp("OLDPWD=", pl->envp.arr[i], 7)))
	{
		pl->envp.key_ignore[i] = 0;
		pl->export.key_ignore[i] = 0;
		free(pl->export.arr[i]);
		ft_swap_str_in_arr(pl->envp.arr, pl->envp.key_ignore, i,
			pl->envp.size - 1);
		pl->export.arr[i] = ft_strdup("OLDPWD");
		ft_swap_str_in_arr(pl->export.arr, pl->export.key_ignore, i,
			pl->envp.size - 1);
		*count = 0;
		free(pl->envp.arr[pl->envp.size - 1]);
		pl->envp.arr[pl->envp.size - 1] = NULL;
	}
	else
	{
		pl->envp.key_ignore[i] = 0;
		pl->export.key_ignore[i] = 0;
	}
}

char	*ft_take_str_in_quotes(char *str)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strjoin(str, "\"");
	tmp2 = ft_strjoin("\"", tmp1);
	free(tmp1);
	return (tmp2);
}

void	ft_export_with_equal_sign_utils(t_pl *pl, char *str, char **cmd)
{
	char	*tmp;

	tmp = ft_strjoin(cmd[1], cmd[3]);
	ft_add_line_in_arr(&pl->export, tmp, 0);
	ft_add_line_in_arr(&pl->envp, str, 0);
	free(tmp);
}

char	*count_pipe(char *str, t_pl *pl)
{
	int	i;

	i = 0;
	pl->p.npipes = 0;
	if (str[0] == '|')
		return (ft_exit_my(PIPE_ERROR));
	while (str[i])
	{
		if (str[i] == '|')
			pl->p.npipes++;
		if (str[i] == '\'')
			while (str[++i] && str[i] != '\'')
				;
		if (str[i] == '\"')
			while (str[++i] && str[i] != '\"')
				;
		i++;
	}
	if (pl->p.npipes != 0)
		pl->flag = 1;
	return (str);
}
