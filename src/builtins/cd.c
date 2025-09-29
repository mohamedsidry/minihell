/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:11:27 by azghibat          #+#    #+#             */
/*   Updated: 2025/09/25 13:52:39 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void run_cd(t_cmd *cmd, t_env **env)
{
    char *path;
    char *old_dir;
    char *new_dir;
    
    if (cmd->args[1] && cmd->args[2])
    {
        printf("Minishell: cd: too many arguments\n");
        cmd->exitcode = ft_strdup("1");
        return;
    }
    old_dir = getcwd(NULL, 0);
    if (!cmd->args[1])
        path = getvalue(*env, "HOME");
    else if (ft_strcmp(cmd->args[1], "-") == 0)
        path = getvalue(*env, "OLDPWD");
    else
        path = cmd->args[1];
    if (chdir(path) == -1)
    {
        perror("Minishell: cd");
		free(old_dir);
        cmd->exitcode = ft_strdup("1");
    }
    else
    {
        new_dir = getcwd(NULL, 0);
        setvalue(*env, "OLDPWD", old_dir);
        setvalue(*env, "PWD", new_dir);
        cmd->exitcode = ft_strdup("0");
    }
	// fix 25 line
}