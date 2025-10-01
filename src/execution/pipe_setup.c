/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 02:47:00 by anasszgh          #+#    #+#             */
/*   Updated: 2025/10/01 03:39:58 by anasszgh         ###   ########.fr       */
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
