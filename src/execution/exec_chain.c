/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_chain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 02:48:14 by anasszgh          #+#    #+#             */
/*   Updated: 2025/10/02 15:25:29 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void	init_pipeline_data(t_data *data, t_cmd *cmds)
{
	data->head = cmds;
	data->current = cmds;
	data->prev_read = -1;
}

static int	fork_child(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("minishell: fork");
		return (-1);
	}
	return (pid);
}

static void	setup_pipes_commands(t_cmd *cmd)
{
	t_cmd	*current;

	current = cmd;
	while (current && current->next)
	{
		if (pipe(current->pipeline_fd) == -1)
		{
			perror("minishell: pipe");
			return ;
		}
		current = current->next;
	}
}

void	exec_chain(t_cmd *cmds, t_env **env, int *error)
{
	t_data	data;
	pid_t	pid;

	if (!cmds)
		return ;
	setup_pipes_commands(cmds);
	init_pipeline_data(&data, cmds);
	while (data.current)
	{
		pid = fork_child();
		if (pid == -1)
		{
			*error = 1;
			return ;
		}
		if (pid == 0)
			execute_child(data.current, *env, error, &data);
		else
			handle_parent_pipes(data.current, &data.prev_read);
		data.current = data.current->next;
	}
	close_all_pipes(cmds);
	if (data.prev_read != -1)
		close(data.prev_read);
	wait_for_all(cmds, error);
}
