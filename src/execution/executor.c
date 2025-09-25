/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 09:58:20 by msidry            #+#    #+#             */
/*   Updated: 2025/09/25 16:15:14 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void exec_builtin(t_cmd **cmd, t_env **env, int *error);
static void exec_chain(t_cmd **cmds, t_env **env, int *error);

void executor(t_cmd **cmds, t_env **env, int *error)
{
    if (!cmds || !*cmds || !env)
        return ;    
    heredoc_manager(*cmds, *env);
    if ((cmd_length(*cmds) == 1) && cmd_builtin(*cmds)->isbuiltin)
    {
       exec_builtin(cmds, env, error);
    }
    else
       exec_chain(cmds, env, error);
}

static void exec_builtin(t_cmd **cmds, t_env **env, int *error)
{
    // int std_io[2];

    // std_io[0] = dup(0);
    // std_io[1] = dup(1);
    if (close_pipe((*cmds)->pip, rw_end))
        return ;
    builtin_manager(*cmds, env, error);
    // print_commands(*cmds);
    // check ambiguous
}

static void exec_chain(t_cmd **cmds, t_env **env, int *error)
{
    (void)cmds;
    (void)env;
    (void)error;
     printf("exec____chain in !\n");
    //  print_commands(*cmds);
    // TODO: update env key = _ to the lates command was runned if single command !
}