/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:56:21 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/05 21:56:23 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	run_env(t_cmd *cmd, t_env **env, int *error)
{
	t_env	*current;

	*error = 0;
	if (!cmd || !env)
		return ;
	if (cmd->args[1])
	{
		ft_putstr_fd("minishell: env: too many arguments\n", 2);
		*error = 1;
		return ;
	}
	current = *env;
	while (current)
	{
		if (!current->ishidden)
		{
			write(STDOUT_FILENO, current->key, ft_strlen(current->key));
			write(STDOUT_FILENO, "=", 1);
			write(STDOUT_FILENO, current->value, ft_strlen(current->value));
			write(STDOUT_FILENO, "\n", 1);
		}
		current = current->next;
	}
}
