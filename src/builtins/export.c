/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:20:04 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/04 22:16:07 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static int	is_valid_export(char *key)
{
	size_t	i;

	if (!key || !key[0])
		return (0);
	if (key[0] >= '0' && key[0] <= '9')
		return (0);
	if (!((key[0] >= 'A' && key[0] <= 'Z') || (key[0] >= 'a' && key[0] <= 'z')
			|| key[0] == '_'))
		return (0);
	i = 1;
	while (key[i])
	{
		if ((key[i] >= 0 && key[i] <= 31) || key[i] == 127)
			return (0);
		if (!((key[i] >= 'A' && key[i] <= 'Z') || (key[i] >= 'a'
					&& key[i] <= 'z') || (key[i] >= '0' && key[i] <= '9')
				|| key[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

static void	print_exported_vars(t_env *env)
{
	while (env)
	{
		if (!env->ishidden)
		{
			write(STDOUT_FILENO, "declare -x ", 11);
			write(STDOUT_FILENO, env->key, ft_strlen(env->key));
			if (env->value && ft_strlen(env->value) > 0)
			{
				write(STDOUT_FILENO, "=\"", 2);
				write(STDOUT_FILENO, env->value, ft_strlen(env->value));
				write(STDOUT_FILENO, "\"", 1);
			}
			write(STDOUT_FILENO, "\n", 1);
		}
		env = env->next;
	}
}

static int	handle_single_export(char *arg, t_env **env)
{
	char	*key;
	char	*value;

	if (ft_strchr(arg, '='))
	{
		key = getprefix(arg, '=');
		value = getsuffix(arg, '=');
	}
	else
	{
		key = ft_strdup(arg);
		value = NULL;
	}
	if (is_valid_export(key))
		env_export(env, key, value);
	else
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		if (value)
			free(value);
		return (free(key), 0);
	}
	return (free(key), 1);
}

void	run_export(t_cmd *cmd, t_env **env, int *error)
{
	int	i;
	int	has_error;

	*error = 0;
	if (!cmd || !env)
		return ;
	if (!cmd->args[1])
	{
		print_exported_vars(*env);
		return ;
	}
	i = 1;
	has_error = 0;
	while (cmd->args[i])
	{
		if (!handle_single_export(cmd->args[i], env))
			has_error = 1;
		i++;
	}
	*error = has_error;
}
