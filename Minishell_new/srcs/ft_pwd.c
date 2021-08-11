/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 19:01:56 by kseniakozyr       #+#    #+#             */
/*   Updated: 2021/07/21 00:01:12 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(t_pl *pl)
{
	int		len;
	char *tmp;
	
	tmp = ft_find_string_char(pl, "PWD=");
	len = ft_strlen(tmp);
	write(2, tmp, len);
	write(2, "\n", 1);
}