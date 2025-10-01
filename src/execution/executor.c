/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 02:48:41 by anasszgh          #+#    #+#             */
/*   Updated: 2025/10/01 03:38:59 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

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
		*error = 1;
		return ;
	}
	if ((cmd_length(*cmds) == 1) && cmd_builtin(*cmds)->isbuiltin)
		exec_builtin(cmds, env, error);
	else
		exec_chain(*cmds, env, error);
}

void	exec_builtin(t_cmd **cmds, t_env **env, int *error)
{
	int	std_io[2];

	if (save_fds(std_io) == -1)
	{
		*error = 1;
		return ;
	}
	if (close_pipe((*cmds)->pip, rw_end))
		return ;
	if (setup_redirection(*cmds, error))
	{
		restore_fds(std_io);
		return ;
	}
	builtin_manager(*cmds, env, error);
	restore_fds(std_io);
}
