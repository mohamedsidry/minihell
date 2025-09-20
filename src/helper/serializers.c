/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 14:10:59 by msidry            #+#    #+#             */
/*   Updated: 2025/09/20 19:33:51 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"


t_list *dserializer(char **arr)
{
    int idx;
    t_list *lst;
    char *content;

    idx = 0;
    lst = NULL;
    if (!arr)
        return (NULL);
    while (arr[idx])
    {
        content = ft_strdup(arr[idx]);
        ft_lstadd_back(&lst, ft_lstnew(content));
        idx++;
    }
    return (lst);
}

char **serializer(t_list *list)
{
    size_t size;
    char **tokens;
    size_t idx;

    if (!list)
        return (NULL);
    size = ft_lstsize(list);
    tokens = ft_calloc(size + 1, sizeof(char *));
    idx = 0;
    if (!tokens)
        return (NULL);
    while (list)
    {
        tokens[idx] = ft_strdup((const char *)list->content);
        list = list->next;
        idx++;
    }
    return (tokens);
}
