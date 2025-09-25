/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:20:04 by azghibat          #+#    #+#             */
/*   Updated: 2025/09/25 17:27:57 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void	print_exported_vars(t_env *env);
static void	handle_single_export(t_cmd *cmd, char *arg, t_env **env);

void	run_export(t_cmd *cmd, t_env **env)
{
	int	i;

	if (!cmd || !env)
		return ;
	if (!cmd->args[1])
	{
		print_exported_vars(*env);
		cmd->exitcode = ft_strdup("0");
		return ;
	}
	i = 1;
	while (cmd->args[i])
	{
		handle_single_export(cmd, cmd->args[i], env);
		i++;
	}
	cmd->exitcode = ft_strdup("0");
}

static void	print_exported_vars(t_env *env)
{
	while (env)
	{
		if (!env->ishidden)
		{
			printf("declare -x %s", env->key);
			if (env->value && ft_strlen(env->value) > 0)
				printf("=\"%s\"", env->value);
			printf("\n");
		}
		env = env->next;
	}
}

static void	handle_single_export(t_cmd *cmd ,char *arg, t_env **env)
{
	char	*key;
	char	*value;

	key = getprefix(arg, '=');
	value = getsuffix(arg, '=');
	if (is_valid(key))
	{
		if (key && value)
			env_export(env, key, value);
		else if (key)
			env_export(env, key, "");
	}
	else
	{
		printf("export: %s: not a valid identifier\n", arg);
		cmd->exitcode = ft_strdup("1");
	}
	// check case export ""
}
