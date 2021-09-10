/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:23:40 by jkorey            #+#    #+#             */
/*   Updated: 2020/11/16 17:51:17 by jkorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *tmp;

	tmp = NULL;
	if (lst)
	{
		while (lst)
		{
			if (!(new = ft_lstnew(f(lst->content))))
			{
				ft_lstclear(&tmp, del);
				return (NULL);
			}
			ft_lstadd_back(&tmp, new);
			lst = lst->next;
		}
		return (tmp);
	}
	return (NULL);
}
