/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:31:10 by msidry            #+#    #+#             */
/*   Updated: 2024/11/07 22:55:36 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstptr;
	t_list	*currentnode;
	void	*contentptr;

	lstptr = NULL;
	if (!lst || !f || !del)
		return (lstptr);
	while (lst)
	{
		contentptr = f(lst->content);
		currentnode = ft_lstnew(contentptr);
		if (!currentnode || !contentptr)
		{
			del(contentptr);
			ft_lstclear(&lstptr, del);
			return (NULL);
		}
		ft_lstadd_back(&lstptr, currentnode);
		lst = lst->next;
	}
	return (lstptr);
}
