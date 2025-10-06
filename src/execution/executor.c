/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:57:21 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/05 21:57:22 by azghibat         ###   ########.fr       */
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
		if (cmd_length(*cmds) == 1 && (*cmds)->args)
			setvalue(*env, "_", ft_strdup((*cmds)->args[0]));
		else
			setvalue(*env, "_", ft_strdup(""));
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
	setvalue(*env, "_", ft_strdup((*cmds)->args[0]));
	builtin_manager(*cmds, env, error);
	restore_fds(std_io);
}
