/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:14:56 by azghibat          #+#    #+#             */
/*   Updated: 2025/09/28 18:35:22 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void builtin_manager(t_cmd *cmd, t_env **env, int *error)
{
    if (!cmd || !env || !error)
        return ;
    *error = 0;
    if (!ft_strcmp(cmd->args[0], "echo"))
        run_echo(cmd, error);   
    else if (!ft_strcmp(cmd->args[0], "cd"))
        run_cd(cmd, env, error);
    else if (!ft_strcmp(cmd->args[0], "pwd"))
        run_pwd(error);
    else if (!ft_strcmp(cmd->args[0], "export"))
        run_export(cmd, env, error);
    else if (!ft_strcmp(cmd->args[0], "unset"))
        run_unset(cmd, env, error);
    else if (!ft_strcmp(cmd->args[0], "env"))
        run_env(cmd, env, error);
    else if (!ft_strcmp(cmd->args[0], "exit"))
        close_theprogram(cmd, env, error);
    else
        *error = 1;
}