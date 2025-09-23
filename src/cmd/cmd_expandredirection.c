/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expandredirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:11:34 by msidry            #+#    #+#             */
/*   Updated: 2025/09/23 14:33:55 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/main.h"

t_cmd *cmd_expandredirection(t_cmd *cmd, void *reff)
{
    t_env *env;
    int idx;
    char *expanded;
    
    expanded = NULL;
    idx = 0;
    env = (t_env *)reff;
    if (!cmd || ! reff)
        return (NULL);
    while (cmd->symbols && cmd->symbols[idx])
    {
        if (!ft_strcmp(cmd->symbols[idx], "<") ||
            !ft_strcmp(cmd->symbols[idx], ">>") ||
            !ft_strcmp(cmd->symbols[idx], ">"))
        {
            expanded = expand_handler(cmd->files[idx], reff, cmd);
            if (expanded && !*expanded)
                return(free(expanded), cmd);
            free(cmd->files[idx]);
            cmd->files[idx] = expanded;
        }
        idx++;
    }
    return (cmd);
}
