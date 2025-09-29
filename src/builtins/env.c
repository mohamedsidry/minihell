/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:22:08 by azghibat          #+#    #+#             */
/*   Updated: 2025/09/25 15:45:01 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	run_env(t_cmd *cmd, t_env **env)
{
	t_env	*current;

	if (!cmd)
		return ;
	current = *env;
	while (current)
	{
		if (!current->ishidden && current->value)
			printf("%s=%s\n", current->key, current->value);
		current = current->next;
	}
	cmd->exitcode = ft_strdup("0");
}
