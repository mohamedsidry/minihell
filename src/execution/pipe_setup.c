/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:57:50 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/05 21:57:51 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	setup_child_pipes(t_cmd *cmd, int prev_read)
{
	setup_input_pipe(prev_read);
	setup_output_pipe(cmd);
}

void	handle_parent_pipes(t_cmd *cmd, int *prev_read)
{
	if (*prev_read != -1)
		close(*prev_read);
	if (cmd->next)
	{
		close(cmd->pipeline_fd[1]);
		*prev_read = cmd->pipeline_fd[0];
	}
	else
		*prev_read = -1;
}
