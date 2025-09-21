/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:46:11 by msidry            #+#    #+#             */
/*   Updated: 2025/09/21 13:58:25 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void handle_heredoc(t_cmd *cmd, t_env *env, size_t idx);
static void child_task(t_cmd *cmd, t_env *env, size_t idx);

void heredoc_manager(t_cmd *cmds, t_env *env)
{
    size_t idx;

    while (cmds)
    {
        idx = 0;
        while (cmds->symbols[idx])
        {
            if (!ft_strcmp(cmds->symbols[idx], "<<"))
                handle_heredoc(cmds, env, idx);
            idx++;
        }
        cmds = cmds->next;
    }
}

static void handle_heredoc(t_cmd *cmd, t_env *env, size_t idx)
{
    pid_t pid;
    char *limiter;
    
    if (pipe_close(cmd->pip, rw_end))
        return ;
    if (pipe(cmd->pip))
        return perror("minishell");
    if (forkchild(&pid))
    {
        if (pipe_close(cmd->pip, rw_end))
        return ;
    }
    if (pid == 0)
        child_task(cmd, env, idx);
    else
        parant_task(cmd, pid);
}

static int forkchild(pid_t *pidptr)
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


static void child_task(t_cmd *cmd, t_env *env, size_t idx)
{
    char *limiter;
    char *data;
    int toexpand;

    data = NULL;
    pipe_close(cmd->pip, r_end);
    limiter = expand_handler(cmd->files[idx], env);
    toexpand = (is_expandable(cmd->files[idx]) && !ft_strchr(cmd->files[idx], '\''));
    stripquotes(&limiter);
    //TODO: child tasks !
}



static void parant_task(t_cmd *cmd, pid_t childpid)
{
    pipe_close(cmd->pip, w_end);
    wait();
    //TODO: parent task;
}