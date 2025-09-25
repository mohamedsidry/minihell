/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expandredirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:11:34 by msidry            #+#    #+#             */
/*   Updated: 2025/09/26 00:02:11 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/main.h"

t_cmd *cmd_expandredirection(t_cmd *cmd, void *reff)
{
    int idx;
    char *expanded;
    
    expanded = NULL;
    idx = 0;
    if (!cmd || ! reff)
        return (NULL);
    while (cmd->symbols && cmd->symbols[idx])
    {
        if (!ft_strcmp(cmd->symbols[idx], "<") ||
            !ft_strcmp(cmd->symbols[idx], ">>") ||
            !ft_strcmp(cmd->symbols[idx], ">"))
        {
            expanded = expand_handler(cmd->files[idx], (t_env *)reff, cmd);
            if (expanded && !*expanded)
                return(free(expanded), cmd);
            free(cmd->files[idx]);
            cmd->files[idx] = expanded;
        }
        idx++;
    }
    return (cmd);
}
