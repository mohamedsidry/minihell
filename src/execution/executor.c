/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:57:21 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/09 12:43:30 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void prev_app(t_env **env, t_cmd *cmd);

void	executor(t_cmd **cmds, t_env **env, int *error)
{
	int	interrupted;

	interrupted = 0;
	if (!cmds || !*cmds || !env || !*env)
		return ;
	heredoc_manager(*cmds, *env, &interrupted);
	if (interrupted)
	{
		cmd_clear(cmds);
		*error = 130;
		setup_interactive_signals();
		return ;
	}
	if ((cmd_length(*cmds) == 1) && cmd_builtin(*cmds)->isbuiltin)
		exec_builtin(cmds, env, error);
	else
	{
		setup_parent_exec_signals();
		exec_chain(*cmds, env, error);
		setup_interactive_signals();
		prev_app(env, *cmds);
	}
}

void	exec_builtin(t_cmd **cmds, t_env **env, int *error)
{
	int	std_io[2];

	if (save_fds(std_io) == -1)
	{
		*error = 1;
		return ;
	}
	if (close_pipe((*cmds)->herdoc_pip, rw_end))
		return ;
	if (setup_redirection(*cmds, error))
	{
		restore_fds(std_io);
		return ;
	}
	prev_app(env, *cmds);
	builtin_manager(*cmds, env, error);
	restore_fds(std_io);
}


static void prev_app(t_env **env, t_cmd *cmd)
{
	t_cmd *head;
	char *payload;

	if (!cmd)
		return ;
	head = cmd_first(cmd);
	if (cmd_length(head) == 1 && head->args)
		payload = concat3("_", cmd->args[0], "=", 0);
	else
		payload = concat3("_", "", "=", 0);
	env_update(env, payload);
	nullstr(&payload);
}