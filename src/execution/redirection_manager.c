/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 22:34:47 by anasszgh          #+#    #+#             */
/*   Updated: 2025/09/27 13:23:57 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static int handle_error(char *file)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	perror("");
	return (1);
}

static int ambiguous_redirect_error(void)
{
	ft_putstr_fd("minishell: ambiguous redirect\n", 2);
	return (1);
}

static int	redirection_in(char *file)
{
	int	fd;

	if (!file || (*file == '$' && ft_isalnum(file[1])))
		return (ambiguous_redirect_error());
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (handle_error(file));
	dup2(fd, 0);
	close(fd);
	return (0);
}

static int	redirection_out(char *file, int append)
{
	int	fd;
	int	flags;

	if (!file || (*file == '$' && ft_isalnum(file[1])))
		return (ambiguous_redirect_error());
	if (append)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	else
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	fd = open(file, flags, 0644);
	if (fd < 0)
		return (handle_error(file));
	dup2(fd, 1);
	close(fd);
	return (0);
}

static int	redirection_heredoc(t_cmd *cmd)
{
	if (cmd->pip[0] == -1)
		return (1);
	dup2(cmd->pip[0], 0);
	close(cmd->pip[0]);
	cmd->pip[0] = -1;
	return (0);
}

int	setup_redirection(t_cmd *cmd, int *error)
{
	int	i;
	int	result;

	if (!cmd || !cmd->symbols || !cmd->files)
		return (0);
	i = 0;
	result = 0;
	while (cmd->symbols[i] && !result)
	{
		if (ft_strcmp(cmd->symbols[i], ">") == 0)
			result = redirection_out(cmd->files[i], 0);
		else if (ft_strcmp(cmd->symbols[i], ">>") == 0)
			result = redirection_out(cmd->files[i], 1);
		else if (ft_strcmp(cmd->symbols[i], "<") == 0)
			result = redirection_in(cmd->files[i]);
		else if (ft_strcmp(cmd->symbols[i], "<<") == 0)
			result = redirection_heredoc(cmd);
		i++;
	}
	if (result && error)
		*error = 1;
	return (result);
}