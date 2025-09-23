/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:25:37 by msidry            #+#    #+#             */
/*   Updated: 2025/09/23 12:38:47 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int has_redirections(t_cmd *cmd)
{
    int idx;

    
    if (!cmd)
        return (0);
    while (cmd)
    {
        idx = -1;
        while (cmd->symbols && cmd->symbols[++idx])
        {
            return (1);
        }
        cmd = cmd->next;
    }
    return (0);
}