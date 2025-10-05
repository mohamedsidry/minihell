/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:07:08 by msidry            #+#    #+#             */
/*   Updated: 2025/10/05 13:56:56 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int	close_pipe(int pipefds[2], t_pipends ends)
{
	if (!pipefds)
		return (0);
	if (pipefds[0] != -1 && (ends & r_end))
	{
		if (close(pipefds[0]) == -1)
			return (perror("minishell"), 1);
		pipefds[0] = -1;
	}
	if (pipefds[1] != -1 && (ends & w_end))
	{
		if (close(pipefds[1]) == -1)
			return (perror("minishell"), 1);
		pipefds[1] = -1;
	}
	return (0);
}

int	open_pipe(int pipefds[2])
{
	if (!pipefds)
		return (1);
	if (pipe(pipefds))
		return (perror("minishell"), 1);
	return (0);
}