/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:04:21 by msidry            #+#    #+#             */
/*   Updated: 2025/09/21 10:11:18 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void cmd_iter(t_cmd **cmds, t_cmd *(func)(t_cmd *cmd))
{
    t_cmd *head;
    t_cmd *ret;

    if (!cmds || !(*cmds) || !func)
        return ;
    head = *cmds;
    while (head)
    {
        ret = func(head);
        if (!ret)
            return (cmd_clear(cmds));
        head = head->next;
    }
}