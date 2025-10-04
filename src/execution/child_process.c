/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 02:47:46 by anasszgh          #+#    #+#             */
/*   Updated: 2025/10/04 10:35:31 by msidry           ###   ########.fr       */
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
	{
		cmd_clear(&data->head);
		env_handler(&env, NULL, DELETE);
		exit(1);
	}
	exec_command(cmd, env, err);
}
