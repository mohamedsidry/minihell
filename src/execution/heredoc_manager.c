/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:46:11 by msidry            #+#    #+#             */
/*   Updated: 2025/09/23 12:12:08 by msidry           ###   ########.fr       */
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
    char *tmp;

    data = NULL;
    tmp = NULL;
    pipe_close(cmd->pip, r_end);
    toexpand = (!ft_strchr(cmd->files[idx], '\'') && !ft_strchr(cmd->files[idx], '"'));
    limiter = ft_strdup(cmd->files[idx]);
    remove_quotes(&limiter);
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
    pipe_close(cmd->pip, w_end);
    exit (0);
}



static void parant_task(t_cmd *cmd, pid_t childpid)
{
    int status;
    char *buffer;

    buffer = ft_calloc(1024, 1);
    pipe_close(cmd->pip, w_end);
    waitpid(childpid, &status, 0);
    read(cmd->pip[0], buffer, 1023);
    printf("pipe data : %s\n", buffer);
}