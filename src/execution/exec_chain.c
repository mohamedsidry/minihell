/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_chain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:57:14 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/05 21:57:15 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void	wait_for_children(t_cmd *cmd, int *err);
static void	kill_all_children(t_cmd *cmd);

static int	fork_child(t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("minishell: fork");
		kill_all_children(cmd);
		return (-1);
	}
	return (pid);
}

static int	setup_pipes_commands(t_cmd *cmd, int *error)
{
	t_cmd	*current;

	current = cmd;
	while (current && current->next)
	{
		if (pipe(current->pipeline_fd) == -1)
		{
			perror("minishell: pipe");
			*error = 2;
			return (1);
		}
		current = current->next;
	}
	return (0);
}

void	exec_chain(t_cmd *cmd, t_env **env, int *error)
{
	int		prev_fd;
	t_cmd	*current;

	prev_fd = -1;
	current = cmd;
	if (setup_pipes_commands(cmd, error))
		return (close_all_pipes(cmd));
	while (current)
	{
		current->pid = fork_child(cmd);
		if (current->pid == -1)
		{
			*error = 1;
			return ;
		}
		if (current->pid == 0)
			execute_child(current, *env, error, prev_fd);
		else
			handle_parent_pipes(current, &prev_fd);
		current = current->next;
	}
	close_all_pipes(cmd);
	if (prev_fd != -1)
		close(prev_fd);
	wait_for_children(cmd, error);
}

static void	wait_for_children(t_cmd *cmd, int *err)
{
	int	status;

	while (cmd)
	{
		waitpid(cmd->pid, &status, 0);
		if (!cmd->next)
		{
			if (WIFEXITED(status))
				*err = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				*err = 128 + WTERMSIG(status);
			else
				*err = 0;
		}
		cmd = cmd->next;
	}
}

static void	kill_all_children(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->pid > 0)
			kill(cmd->pid, SIGKILL);
		cmd = cmd->next;
	}
}
