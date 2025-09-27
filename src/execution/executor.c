/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 09:58:20 by msidry            #+#    #+#             */
/*   Updated: 2025/09/26 19:15:25 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void exec_builtin(t_cmd **cmd, t_env **env, int *error);
static void exec_chain(t_cmd **cmds, t_env **env, int *error);

void executor(t_cmd **cmds, t_env **env, int *error)
{
    if (!cmds || !*cmds || !env || !*env)
        return ;    
    heredoc_manager(*cmds, *env);
    if ((cmd_length(*cmds) == 1) && cmd_builtin(*cmds)->isbuiltin)
       exec_builtin(cmds, env, error);
    else
       exec_chain(cmds, env, error);
}

static void exec_builtin(t_cmd **cmds, t_env **env, int *error)
{
    int std_io[2];
    
    if (save_fds(std_io) == -1)
    {
        *error = 1;
        return;
    }
    if (close_pipe((*cmds)->pip, rw_end))
        return ;
    if (setup_redirection(*cmds, error))
    {
        restore_fds(std_io);
        return ;
    }
    builtin_manager(*cmds, env, error);
    restore_fds(std_io);
}

static void exec_chain(t_cmd **cmds, t_env **env, int *error)
{
    (void)cmds;
    (void)env;
    (void)error;
    printf("exec____chain in !\n");
    // TODO: update env key = _ to the lates command was runned if single command !
}