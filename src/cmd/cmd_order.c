/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 07:47:57 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 09:46:20 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"


t_cmd *cmd_last(t_cmd **cmds)
{
    t_cmd *head;
    
    if (!cmds || !(*cmds))
        return (NULL);

    head = *cmds;
    while (head->next)
        head = head->next;
    return (head);
}


t_cmd *cmd_first(t_cmd **cmds)
{
    t_cmd *first;
    
    if (!cmds || !(*cmds))
        return (NULL);

    first = *cmds;
    while (first->prev)
        first = first->prev;
    return (first);
}