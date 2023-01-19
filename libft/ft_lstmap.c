/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:59:27 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/03/18 17:24:16 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_el;
	t_list	*new_lst;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	tmp = lst;
	while (tmp)
	{
		new_el = ft_lstnew((*f)(tmp->content));
		if (!new_el)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_el);
		tmp = tmp->next;
	}
	return (new_lst);
}
