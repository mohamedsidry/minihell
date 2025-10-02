/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut_chain2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:22:03 by msidry            #+#    #+#             */
/*   Updated: 2025/10/02 14:23:29 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void close_pipes(t_pipes **pipes, size_t idx);
static t_pipes **init_pipes(t_cmd *cmds, int *err);
static void detroy_pipes(t_pipes **pipes);
static void child_parent(t_cmd **cmds, t_cmd *cmd, t_env **lst, int *err, t_pipes **pipes);
static void child_task(t_cmd **cmds, t_cmd *cmd, t_env **lst, t_pipes **pipes);
static int fds_handler2(t_cmd *cmd, int *err, t_pipes **pipes);
static int handle_outt(t_cmd *cmd, int idx);
static int handle_appendd(t_cmd *cmd, int idx);
static int handle_inn(t_cmd *cmd, int idx);
static int handle_herdocc(t_cmd *cmd);

void exec_chain2(t_cmd **cmds, t_env **env, int *err)
{
	t_pipes **pipes;
	int std_io[2];
	size_t idx;
    t_cmd *cmd;
    int stat;

	idx = 0;
	if (!cmds || !*cmds)
		return ;
    cmd = *cmds;
	pipes = init_pipes(cmd, err);
	if (!pipes)
		return ;
	if (save_fds(std_io, err) == -1)
        return detroy_pipes(pipes) ;
	while (cmd)
	{
		if (!fds_handler2(cmd, err, pipes))
			child_parent(cmds, cmd, env, err, pipes);
		cmd = cmd->next;
		idx++;
	}
	
	if (cmd->idx > 0)
        close_pipe(pipes[cmd->idx - 1]->fds, rw_end);
	cmd = *cmds;
    while (cmd)
    {
        if (cmd->pid != -1)
        {
            waitpid(cmd->pid, &stat, 0);
            if (WIFEXITED(stat))
			{
				if (!cmd->next)
					*err = WEXITSTATUS(stat);
			} 
        }
        cmd = cmd->next;
    }
    restore_fds(std_io);
	detroy_pipes(pipes);
}

void close_pipes(t_pipes **pipes, size_t idx)
{
    size_t i;

    if (!pipes)
        return ;
    i = 0;
    while (i < idx)
    {
		if (pipes[i])
			close_pipe(pipes[i]->fds, rw_end);
		i++;
    }
}

static t_pipes **init_pipes(t_cmd *cmds, int *err)
{
	t_pipes **pipes;
	size_t count;
	size_t idx;
    size_t j;

    idx = 0;
	count = cmd_length(cmds);
	pipes = ft_calloc(count + 1, sizeof(t_pipes *));
	if (!pipes)
		return (NULL);
	
	while (idx < count)
	{
		pipes[idx] = ft_calloc(1, sizeof(t_pipes));
		if (!pipes[idx] || pipe(pipes[idx]->fds) == -1)
		{
			perror("minishell :pipe");
            j = 0;
			while (j < idx)
			{
				close_pipe(pipes[j]->fds, rw_end);
				free(pipes[j]);
                if (j == idx)
                    free(pipes[j]);
                j++;
			}
			free(pipes);
			*err = 1;
			return (NULL);
		}
		idx++;
	}
	return (pipes);
}

static void detroy_pipes(t_pipes **pipes)
{
	int idx;

	idx = 0;
	if (!pipes)
		return ;

	while (pipes[idx])
	{
		close_pipe(pipes[idx]->fds, rw_end);
		free(pipes[idx]);
		pipes[idx] = 0;
		idx++;
	}
	free(pipes);
	*pipes = NULL;
	
}

static void child_parent(t_cmd **cmds, t_cmd *cmd, t_env **lst, int *err, t_pipes **pipes)
{
	
	dup2(cmd->in_fd, STDIN_FILENO);
	if (cmd->in_fd != STDIN_FILENO)
		close(cmd->in_fd);
	cmd->in_fd = STDIN_FILENO;
	dup2(cmd->out_fd, STDOUT_FILENO);
	if (cmd->out_fd != STDOUT_FILENO)
		close(cmd->out_fd);
	cmd->out_fd = STDOUT_FILENO;
    
	cmd->pid = fork();
	if (cmd->pid == -1)
    {
        perror("minishell");
        if (!cmd->next)
            *err = 1;
        close_pipe(pipes[cmd->idx - 1]->fds, rw_end);
        return ;
    }
	if (cmd->pid == 0)
		child_task(cmds, cmd, lst, pipes);
    if (cmd->idx > 0)
        close_pipe(pipes[cmd->idx - 1]->fds, rw_end);
}


static void child_task(t_cmd **cmds, t_cmd *cmd, t_env **lst, t_pipes **pipes)
{
    char **envp;
    int error;
	
	error = 0;
    if (cmd->idx > 0)
        close_pipe(pipes[cmd->idx - 1]->fds, rw_end);
    if (!cmd)
        return;
    if (cmd->args && is_builtin(cmd->args[0]))
    {
        builtin_manager(cmd, lst, &error);
		env_handler(lst, NULL, DELETE);
		cmd_clear(cmds);
        if (error)
            exit(130);
        else
            exit(0);
    }
    envp = env_serializer(*lst);
	if (execve(cmd->args[0], cmd->args, envp) == -1)
		perror("minishell");
	free2d(&envp);
	env_handler(lst, NULL, DELETE);
	cmd_clear(cmds);
	exit (130);
}

static int fds_handler2(t_cmd *cmd, int *err, t_pipes **pipes)
{
	int idx;
    int failed;

	idx = -1;
    failed = 0;
    if (cmd->idx == 0)
        cmd->in_fd = dup(STDIN_FILENO);
    else
        cmd->in_fd = dup(pipes[cmd->idx - 1]->fds[0]);
    if (cmd->next)
        cmd->out_fd = dup(pipes[cmd->idx]->fds[1]);
    else
        cmd->out_fd = dup(STDOUT_FILENO);
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
