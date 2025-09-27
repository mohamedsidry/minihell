/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut_chain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 09:58:20 by msidry            #+#    #+#             */
/*   Updated: 2025/09/27 19:39:10 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	execute_pipeline_command(t_cmd *cmd, t_env *env, int *error, int prev_pipe_read)
{
	char	**env_array;

	setup_pipes_fds(cmd, cmd->next, prev_pipe_read);
	if (setup_redirection(cmd, error))
		exit(1);
	if (cmd->isbuiltin)
	{
		builtin_manager(cmd, &env, error);
		exit(*error);
	}
	else
	{
		env_array = env_serializer(env);
		if (!env_array)
			exit(1);
		execve(cmd->args[0], cmd->args, env_array);
		perror("minishell");
		exit(127);
	}
}

void	handle_parent_process(t_cmd *cmd, int *prev_pipe_read)
{
	if (*prev_pipe_read != -1)
		close(*prev_pipe_read);
	if (cmd->next)
	{
		close(cmd->pip[1]);
		*prev_pipe_read = cmd->pip[0];
	}
	else
		*prev_pipe_read = -1;
}

void	setup_pipes_fds(t_cmd *cmd, t_cmd *next_cmd, int prev_pipe_read)
{
	if (prev_pipe_read != -1)
	{
		dup2(prev_pipe_read, STDIN_FILENO);
		close(prev_pipe_read);
	}
	if (next_cmd)
	{
		dup2(cmd->pip[1], STDOUT_FILENO);
		close(cmd->pip[1]);
		close(cmd->pip[0]);
	}
}

void	setup_pipes_commands(t_cmd *cmd)
{
	t_cmd *current;
	
	current = cmd;
	while (current && current->next)
	{
		if (pipe(current->pip) == -1)
		{
			perror("minishell: pipe");
			return ;
		}
		current = current->next;
	}
}

void	wait_for_all(t_cmd *cmd)
{
	t_cmd	*current;
	int		status;
	int		cmd_count;

	cmd_count = 0; // counting how many child is there
	current = cmd;
	while (current)
	{
		cmd_count++;
		current = current->next;
	}
	while (cmd_count > 0)
	{
		wait(&status);
		cmd_count--;
	}
}
