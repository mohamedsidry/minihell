/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:56:51 by msidry            #+#    #+#             */
/*   Updated: 2025/09/20 14:18:43 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

char	**append_array(char **arr, void *toadd)
{
	t_list	*lst;
	char	**newarr;

	lst = dserializer(arr);
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup(toadd)));
	newarr = serializer(lst);
	ft_lstclear(&lst, free);
	free2d(&arr);
	return (newarr);
}
