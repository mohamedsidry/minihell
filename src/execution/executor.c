/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 09:58:20 by msidry            #+#    #+#             */
/*   Updated: 2025/09/28 03:51:13 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void executor(t_cmd **cmds, t_env **env, int *error)
{
    if (!cmds || !*cmds || !env || !*env)
        return ;    
    heredoc_manager(*cmds, *env);
    if ((cmd_length(*cmds) == 1) && cmd_builtin(*cmds)->isbuiltin)
       exec_builtin(cmds, env, error);
    else
       exec_chain(*cmds, env, error);
}

void exec_builtin(t_cmd **cmds, t_env **env, int *error)
{
    int std_io[2];
    
    if (save_fds(std_io) == -1)
    {
        *error = 1;
        return;
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

void	exec_chain(t_cmd *cmds, t_env **env, int *error)
{
	t_cmd	*current;
	pid_t	pid;
	int		prev_pipe_read;

	if (!cmds)
		return ;
	setup_pipes_commands(cmds);
	current = cmds;
	prev_pipe_read = -1;
	while (current)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("minishell: fork");
			*error = 1;
			return ;
		}
		if (pid == 0)
			execute_pipeline_command(current, *env, error, prev_pipe_read);
		else
			handle_parent_process(current, &prev_pipe_read);
		current = current->next;
	}
	if (prev_pipe_read != -1)
		close(prev_pipe_read);
	wait_for_all(cmds);
}
