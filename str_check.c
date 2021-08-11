#include "minishell.h"

    // все символы - ascii
    // не начинается на пайп, пропустив пробелы
    // апостроф и кавычки закрываются
    // после >, <, >>, << есть символы

char	*apostrophe(char *str, int *i)
{
	int	slen;

	slen = ft_strlen(str);
	str[*i] = 0;
	ft_strlcat(str, str + *i + 1, slen);
	while (str[*i] && str[*i] != '\'')
		(*i)++;
	if (str[*i] == 0)
		ft_exit(-1, APOSTROPHE_ERROR);
	str[*i] = 0;
	ft_strlcat(str, str + *i + 1, slen);
	return (str);
}

char	*key_search(char **key, char **envp)
{
	int	i;
	int	keylen;
	char	*tmp;

	i = 0;
	keylen = ft_strlen(*key);
	tmp = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], *key, keylen))
		{
			if (envp[i][keylen] == '=')
				tmp = ft_substr(envp[i], ++keylen, ft_strlen(envp[i]) - keylen);
		}
		i++;
	}
	if (!tmp)
		tmp = ft_strdup("");
	free(*key);
	return (tmp);
}

char	*dollar(char *str, int *i, char **envp)
{
	int	j;
	char	*key;
	char	*tmp;//утечки str

	j = (*i)++;
	if (ft_isdigit(str[*i]))
		while (ft_isdigit(str[*i]))
			(*i)++;
	else
		while (str[*i] == '_' || ft_isalnum(str[*i]))
			(*i)++;
	if ((*i) - j == 1)
		return (str);
	key = ft_substr(str, j + 1, (*i) - j - 1);
	key = key_search(&key, envp);
	str[j] = 0;
	tmp = ft_strjoin(str, key);
	free(key);
	j = ft_strlen(tmp);
	key = ft_strjoin(tmp, str + (*i));
	free(tmp);
	*i = j;
	return (key);
}

char	*quote(char *str, int *i, char **envp)
{
	int	slen;

	slen = ft_strlen(str);
	str[*i] = 0;
	ft_strlcat(str, str + (*i) + 1, slen);
	while (str[*i] && str[*i] != '\"')
	{
		if (str[*i] == '$')
			str = dollar(str, i, envp);
		(*i)++;
	}
	if (str[*i] == 0)
		ft_exit(-1, QUOTE_ERROR);
	str[*i] = 0;
	ft_strlcat(str, str + (*i) + 1, slen);
	return (str);
}

int	str_check(char *str, char **envp)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '|')
		ft_exit(-1, PIPE_ERROR);
	while (str[i])
	{
		if (str[i] == '\'')
			str = apostrophe(str, &i);
		if (str[i] == '\"')
			str = quote(str, &i, envp);
		// if (str[i] == '>' || str[i] == '<')
		// 	str = angle_bracket(str, &i);
		if (str[i] == '$')
			str = dollar(str, &i, envp);
		i++;
	}
	printf("%s", str);

	return (0);///
}