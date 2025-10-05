/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:46:11 by msidry            #+#    #+#             */
/*   Updated: 2025/10/05 20:11:54 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void	handle_heredoc(t_cmd *cmd, t_env *env, size_t idx, int *tt);
static int	forkchild(pid_t *pidptr);
static void	child_task(t_cmd *cmd, t_env *env, size_t idx);
static void	parant_task(t_cmd *cmd, pid_t childpid, int *tt);

void	heredoc_manager(t_cmd *cmds, t_env *env, int *interrupted)
{
	size_t	idx;

	if (!cmds)
		return ;
	while (cmds && *interrupted == 0)
	{
		idx = 0;
		while (cmds->symbols && cmds->symbols[idx] && *interrupted == 0)
		{
			if (!ft_strcmp(cmds->symbols[idx], "<<"))
				handle_heredoc(cmds, env, idx, interrupted);
			idx++;
		}
		cmds = cmds->next;
	}
}

static void	handle_heredoc(t_cmd *cmd, t_env *env, size_t idx, int *interrupted)
{
	pid_t	pid;

	if (close_pipe(cmd->herdoc_pip, rw_end))
		return ;
	if (open_pipe(cmd->herdoc_pip))
		return ;
	if (forkchild(&pid))
	{
		if (close_pipe(cmd->herdoc_pip, rw_end))
			return ;
	}
	if (pid == 0)
		child_task(cmd, env, idx);
	else
		parant_task(cmd, pid, interrupted);
}

static int	forkchild(pid_t *pidptr)
{
	if (!pidptr)
		return (1);
	*pidptr = fork();
	if (*pidptr == -1)
	{
		perror("minishell");
		return (1);
	}
	return (0);
}

static void	child_task(t_cmd *cmd, t_env *env, size_t idx)
{
	char	*limiter;
	int		toexpand;
	char	*tmp;

	tmp = NULL;
	close_pipe(cmd->herdoc_pip, r_end);
	toexpand = (!ft_strchr(cmd->files[idx], '\'') && !ft_strchr(cmd->files[idx],
				'"'));
	limiter = remove_quotes(&cmd->files[idx], 0);
	herdoc_loop(cmd, env, limiter, toexpand);
	nullstr(&limiter);
	nullstr(&tmp);
	close_pipe(cmd->herdoc_pip, w_end);
	exit(0);
}

static void	parant_task(t_cmd *cmd, pid_t childpid, int *interrupted)
{
	int	status;

	close_pipe(cmd->herdoc_pip, w_end);
	waitpid(childpid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
		*interrupted = 130;
}
