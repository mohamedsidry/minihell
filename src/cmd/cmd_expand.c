/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:27:19 by msidry            #+#    #+#             */
/*   Updated: 2025/09/22 14:34:26 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void expand_args(t_cmd *cmd, t_env *env);
//static void expand_rediections(t_cmd *cmd, t_env *env);

t_cmd   *cmd_expand(t_cmd *cmd, void *reff)
{
    t_env *env;
    
    env = (t_env *)reff;
    expand_args(cmd, env);
    //expand_rediections(cmd, env);
    return (cmd);
}


static void expand_args(t_cmd *cmd, t_env *env)
{
    int idx;
    char *result;

    idx = 0;
    if (!cmd || !cmd->args)
        return ;
   while (cmd->args[idx])
   {
        result = expand_handler(cmd->args[idx], env);
        printf("command expanded %s\n", cmd->args[idx]);
        //remove_quotes(&cmd->args[idx]);
        free(cmd->args[idx]);
        cmd->args[idx] = result;
        idx++;
   }
}

// static void expand_rediections(t_cmd *cmd, t_env *en)
// {
//     (void)cmd;
//     (void)en;
//     //TODO: expend files;
// }
