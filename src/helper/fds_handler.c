/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 09:18:33 by msidry            #+#    #+#             */
/*   Updated: 2025/10/01 14:18:29 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static int handle_outt(t_cmd *cmd, int idx);
static int handle_appendd(t_cmd *cmd, int idx);
static int handle_inn(t_cmd *cmd, int idx);
static int handle_herdocc(t_cmd *cmd);

int fds_handler(t_cmd *cmd, int *err)
{
	int idx;
    int failed;

	idx = -1;
    failed = 0;
	while (cmd->symbols && cmd->symbols[++idx] && !failed)
	{
        if (!ft_strcmp(cmd->symbols[idx], ">"))
            failed = handle_outt(cmd, idx);
        else if (!ft_strcmp(cmd->symbols[idx], ">>"))
            failed = handle_appendd(cmd, idx);
        else if (!ft_strcmp(cmd->symbols[idx], "<"))
            failed = handle_inn(cmd, idx);
        else if (!ft_strcmp(cmd->symbols[idx], "<<"))
            failed = handle_herdocc(cmd);
	}
    if (failed)
    {
        if (cmd->in_fd != -1)
            close(cmd->in_fd);
        if (cmd->out_fd != -1)
            close(cmd->out_fd);
        return (*err = 1, 1);
    }
    return (0);
}

static int handle_outt(t_cmd *cmd, int idx)
{
    char *file;
    int fd;

    file = cmd->files[idx];
    if (ambiguous_check(file))
        return (1);
    fd = open(file, O_WRONLY| O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        return (perror("minishell"), 1);
    if (dup2(fd, cmd->out_fd) == -1)
    {
        perror("minishell");
        close(fd);
        return (1);
    }
    if (close(fd))
    {
        perror("minishell");
        close(cmd->out_fd);
        return (1);
    }
    return (0);
}

static int handle_appendd(t_cmd *cmd, int idx)
{
    char *file;
    int fd;

    file = cmd->files[idx];
    if (ambiguous_check(file))
        return (1);
    fd = open(file, O_WRONLY| O_CREAT | O_APPEND, 0644);
    if (fd == -1)
        return (perror("minishell"), 1);
    if (dup2(fd, cmd->out_fd) == -1)
    {
        perror("minishell");
        close(fd);
        return (1);
    }
    if (close(fd))
    {
        perror("minishell");
        close(cmd->out_fd);
        return (1);
    }
    return (0);
}

static int handle_inn(t_cmd *cmd, int idx)
{
    char *file;
    int fd;

    file = cmd->files[idx];
    if (ambiguous_check(file))
        return (1);
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (perror("minishell"), 1);
    if (dup2(fd, cmd->in_fd) == -1)
    {
        perror("minishell");
        close(fd);
        return (1);
    }
    if (close(fd))
    {
        perror("minishell");
        close(cmd->in_fd);
        return (1);
    }
    return (0);
}

static int handle_herdocc(t_cmd *cmd)
{
    if (cmd->pip[0] != -1)
    {
        if (dup2(cmd->pip[0], cmd->in_fd) == -1)
        {
            perror("minishell");
            return (1);
        }
        close_pipe(cmd->pip, rw_end);   
    }
    return (0);
}
