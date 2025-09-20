/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_addback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 07:46:24 by msidry            #+#    #+#             */
/*   Updated: 2025/09/20 12:54:58 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"


t_cmd *cmd_addback(t_cmd **cmds, t_cmd *cmd)
{
    t_cmd *tail;

    if (!cmds || !cmd)
        return (NULL);
    tail = cmd_last(cmds);
    if (!tail)
        *cmds = cmd;
    else
    {
        tail->next = cmd;
        cmd->next = NULL;
    }
    return (cmd);
}