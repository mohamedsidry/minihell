/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_trim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:15:39 by msidry            #+#    #+#             */
/*   Updated: 2025/09/21 10:19:20 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"


t_cmd *cmd_trim(t_cmd *cmd)
{
    char *trimed_cmd;
    
    trimed_cmd = ft_strtrim(cmd->fullcmd, "\n\t\v \b\r");
    if (!trimed_cmd)
        return (NULL);
    free(cmd->fullcmd);
    cmd->fullcmd = trimed_cmd;
    return (cmd);
}