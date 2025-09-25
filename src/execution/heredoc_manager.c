/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:46:11 by msidry            #+#    #+#             */
/*   Updated: 2025/09/25 11:24:28 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void handle_heredoc(t_cmd *cmd, t_env *env, size_t idx);
static int forkchild(pid_t *pidptr);
static void child_task(t_cmd *cmd, t_env *env, size_t idx);
static void parant_task(t_cmd *cmd, pid_t childpid);

void heredoc_manager(t_cmd *cmds, t_env *env)
{
    size_t idx;
    if (!cmds)
        return ;
    while (cmds)
    {
        idx = 0;
        while (cmds->symbols && cmds->symbols[idx])
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
    
    if (close_pipe(cmd->pip, rw_end))
        return ;
    if (open_pipe(cmd->pip))
        return ;
    if (forkchild(&pid))
    {
        if (close_pipe(cmd->pip, rw_end))
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
    char *tmp;

    data = NULL;
    tmp = NULL;
    close_pipe(cmd->pip, r_end);
    toexpand = (!ft_strchr(cmd->files[idx], '\'') && !ft_strchr(cmd->files[idx], '"'));
    limiter = remove_quotes(&cmd->files[idx], 0);
    while (1)
    {
        tmp = readline("> ");
        if (!tmp)
            break;
        if (toexpand && ft_strcmp(tmp, limiter))
            data = expand_handler(tmp, env, cmd);
        else
            data = ft_strdup(tmp);
        if (!ft_strcmp(data, limiter))
            break;
        ft_putendl_fd(data, cmd->pip[1]);
        nullstr(&tmp);
        nullstr(&data);
    }
    nullstr(&data);
    nullstr(&limiter);
    close_pipe(cmd->pip, w_end);
    exit (0);
}



static void parant_task(t_cmd *cmd, pid_t childpid)
{
    int status;

    close_pipe(cmd->pip, w_end);
    waitpid(childpid, &status, 0);
}