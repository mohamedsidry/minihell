/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:57:57 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/05 21:57:58 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	close_pipe_fds(t_cmd *cmd)
{
	if (cmd->pipeline_fd[0] > 2)
		close(cmd->pipeline_fd[0]);
	if (cmd->pipeline_fd[1] > 2)
		close(cmd->pipeline_fd[1]);
}

void	close_all_pipes(t_cmd *cmds)
{
	t_cmd	*tmp;

	tmp = cmds;
	while (tmp)
	{
		close_pipe_fds(tmp);
		tmp = tmp->next;
	}
}

void	setup_input_pipe(int prev_pipe_read)
{
	if (prev_pipe_read != -1)
	{
		dup2(prev_pipe_read, STDIN_FILENO);
		close(prev_pipe_read);
	}
}

void	setup_output_pipe(t_cmd *cmd)
{
	if (cmd->next)
	{
		dup2(cmd->pipeline_fd[1], STDOUT_FILENO);
		close(cmd->pipeline_fd[1]);
		close(cmd->pipeline_fd[0]);
	}
}
