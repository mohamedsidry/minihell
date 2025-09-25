/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expandargs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:27:19 by msidry            #+#    #+#             */
/*   Updated: 2025/09/25 07:27:24 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_cmd   *cmd_expandargs(t_cmd *cmd, void *reff)
{
    int idx;
    char *result;
    t_env *env;

    idx = 0;
    env = (t_env *)reff;
    if (!cmd || !cmd->args)
        return (cmd);
   while (cmd->args && cmd->args[idx])
   {
        result = expand_handler(cmd->args[idx], env, cmd);
        free(cmd->args[idx]);
        cmd->args[idx] = result;
        idx++;
   }
   return (cmd);
}
