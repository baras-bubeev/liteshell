/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:46:29 by jkorey            #+#    #+#             */
/*   Updated: 2021/07/20 07:25:36 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_path(t_pl *pl)
{
	int		i;
	int		count_path_str;
	char	*tmp;

	tmp = ft_find_string_char(pl, "PATH=");
	count_path_str = ft_count_char(tmp, ':') + 1;
	pl->path = ft_split(tmp, ':');
	ft_concatenate_str_in_arr(pl->path, count_path_str, "/");
	free(tmp);
}