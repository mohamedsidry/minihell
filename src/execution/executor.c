/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 09:58:20 by msidry            #+#    #+#             */
/*   Updated: 2025/09/23 14:55:36 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void exec_builtin(t_cmd **cmd, t_env **env, int *error);
static void exec_chain(t_cmd **cmds, t_env **env, int *error);

void executor(t_cmd **cmds, t_env **env, int *error)
{
    if (!cmds || !env)
        return ;
    cmd_iter2(cmds, error, cmd_expandstatus); // find $1 and replace it with exit code of prev or '\0' if multi commands !
    cmd_iter2(cmds, *env, cmd_expandprev); // find $_ and replace it with prev program .
    heredoc_manager(*cmds, *env);
    cmd_iter2(cmds, *env, cmd_expand); // expand args ! 
    cmd_iter2(cmds, *env, cmd_expandredirection); // expand redirection ! 
    cmd_iter2(cmds, error, cmd_removequotes); //TODO: remove quotes;
    if ((cmd_length(*cmds) == 1) && cmd_builtin(*cmds)->isbuiltin)
       exec_builtin(cmds, env, error);
    else
       exec_chain(cmds, env, error);
}



static void exec_builtin(t_cmd **cmds, t_env **env, int *error)
{
    (void)cmds;
    (void)env;
    (void)error;
    printf("exec____built________ in !\n");
    // TODO: update key = _ to the lates command was runned !
}

static void exec_chain(t_cmd **cmds, t_env **env, int *error)
{
    (void)cmds;
    (void)env;
    (void)error;
     printf("exec____chain in !\n");
    // TODO: update key = _ to the lates command was runned !
}