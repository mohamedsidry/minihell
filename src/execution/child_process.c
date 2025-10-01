/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 02:47:46 by anasszgh          #+#    #+#             */
/*   Updated: 2025/10/01 02:47:47 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void	exec_command(t_cmd *cmd, t_env *env, int *error)
{
	char	**env_array;

	if (cmd->isbuiltin)
	{
		builtin_manager(cmd, &env, error);
		exit(*error);
	}
	env_array = env_serializer(env);
	if (!env_array)
		exit(1);
	execve(cmd->args[0], cmd->args, env_array);
	perror("minishell");
	exit(127);
}

void	execute_child(t_cmd *cmd, t_env *env, int *err, t_data *data)
{
	setup_child_pipes(cmd, data->prev_read);
	close_all_pipes(data->head);
	if (setup_redirection(cmd, err))
		exit(1);
	exec_command(cmd, env, err);
}
