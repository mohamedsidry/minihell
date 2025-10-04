/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_crud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:00:19 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 14:19:22 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_cmd	*cmd_create(void)
{
	t_cmd	*command;

	command = ft_calloc(1, sizeof(t_cmd));
	if (!command)
		return (NULL);
	command->herdoc_pip[0] = -1;
	command->herdoc_pip[1] = -1;
	command->pipeline_fd[0] = -1;
	command->pipeline_fd[1] = -1;
	return (command);
}

void	cmd_delete(t_cmd *command)
{
	if (!command)
		return ;
	free(command->fullcmd);
	free(command->exitcode);
	free(command->prevcmd);
	free2d(&command->args);
	free2d(&command->symbols);
	free2d(&command->files);
	close_pipe(command->herdoc_pip, rw_end);
	ft_bzero(command, sizeof(t_cmd));
	free(command);
}
