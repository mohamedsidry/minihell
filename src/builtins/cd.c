/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:11:27 by azghibat          #+#    #+#             */
/*   Updated: 2025/09/29 12:00:32 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void	cd_error_handler(t_cmd *cmd, int *error, char *old_dir)
{
	ft_putstr_fd("minishell: cd: ", 2);
	if (cmd->args[1])
		ft_putstr_fd(cmd->args[1], 2);
	ft_putstr_fd(": ", 2);
	perror("");
	*error = 1;
	if (old_dir)
		free(old_dir);
}

static void	cd_success_handler(t_env **env, char *old_dir)
{
	char	*new_dir;

	new_dir = getcwd(NULL, 0);
	if (old_dir)
		setvalue(*env, "OLDPWD", old_dir);
	if (new_dir)
		setvalue(*env, "PWD", new_dir);
}

static char	*get_target_path(t_cmd *cmd, t_env *env)
{
	char	*oldpwd;

	if (!cmd->args[1])
		return (getvalue(env, "HOME"));
	if (ft_strcmp(cmd->args[1], "~") == 0)
		return (getvalue(env, "HOME"));
	if (ft_strcmp(cmd->args[1], "-") == 0)
	{
		oldpwd = getvalue(env, "OLDPWD");
		if (!oldpwd)
		{
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
			return (NULL);
		}
		return (oldpwd);
	}
	return (cmd->args[1]);
}

void	run_cd(t_cmd *cmd, t_env **env, int *error)
{
	char	*path;
	char	*old_dir;

	*error = 0;
	old_dir = getcwd(NULL, 0);
	path = get_target_path(cmd, *env);
	if (!path)
	{
		*error = 1;
		return ;
	}
	if (chdir(path) == -1)
		cd_error_handler(cmd, error, old_dir);
	else
		cd_success_handler(env, old_dir);
}
