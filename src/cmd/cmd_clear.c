/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:03:59 by msidry            #+#    #+#             */
/*   Updated: 2025/09/20 14:23:39 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void cmd_clear(t_cmd **cmds)
{
    t_cmd *current;
    t_cmd *tmp;
    
    if (!cmds || !(*cmds))
        return ;
    current = *cmds;
    while (current)
    {
        tmp = current->next;
        cmd_delete(current);
        current = tmp;
    }
    *cmds = NULL;
}