/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:14:56 by azghibat          #+#    #+#             */
/*   Updated: 2025/09/25 15:12:20 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void builtin_manager(t_cmd *cmd, t_env **env, int *error)
{
    if (!cmd || !env)
        return ;
    if (!ft_strcmp(cmd->args[0], "echo"))
        run_echo(cmd);   
    else if (!ft_strcmp(cmd->args[0], "cd"))
        run_cd(cmd, env);
    else if (!ft_strcmp(cmd->args[0], "pwd"))
        run_pwd();
    else if (!ft_strcmp(cmd->args[0], "export"))
        run_export(cmd, env);
    else if (!ft_strcmp(cmd->args[0], "unset"))
        run_unset(cmd, env);
    else if (!ft_strcmp(cmd->args[0], "env"))
        run_env(cmd, env);
    else if (!ft_strcmp(cmd->args[0], "exit"))
        close_theprogram(cmd, env);
	(void)error;
}