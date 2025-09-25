/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:20:04 by azghibat          #+#    #+#             */
/*   Updated: 2025/09/25 18:43:20 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void	print_exported_vars(t_env *env);
static void	handle_single_export(char *arg, t_env **env);
static int	is_valid_export(char *key);

static int	is_valid_export(char *key)
{
	size_t	i;

	if (!key || !key[0])
		return (0);
	if (key[0] >= '0' && key[0] <= '9')
		return (0);
	if (!((key[0] >= 'A' && key[0] <= 'Z')
			|| (key[0] >= 'a' && key[0] <= 'z')
			|| key[0] == '_'))
		return (0);
	i = 1;
	while (key[i])
	{
		if ((key[i] >= 0 && key[i] <= 31) || key[i] == 127)
			return (0);
		if (!((key[i] >= 'A' && key[i] <= 'Z')
				|| (key[i] >= 'a' && key[i] <= 'z')
				|| (key[i] >= '0' && key[i] <= '9')
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
			printf("declare -x %s", env->key);
			if (env->value && ft_strlen(env->value) > 0)
				printf("=\"%s\"", env->value);
			printf("\n");
		}
		env = env->next;
	}
}

static void	handle_single_export(char *arg, t_env **env)
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
		key = arg;
		value = NULL;
	}
	if (is_valid_export(key))
	{
		if (value)
			env_export(env, key, value);
		else
			env_export(env, key, "");
	}
	else
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
	}
}

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
		handle_single_export(cmd->args[i], env);
		i++;
	}
	cmd->exitcode = ft_strdup("0");
}
