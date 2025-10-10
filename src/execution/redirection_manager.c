/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:58:03 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/09 19:50:39 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static int	redirection_in(char *file)
{
	int	fd;

	if (!file || ambiguous_check(file))
		return (1);
	if (ft_strchr(file, '*'))
		file = remove_quotes(&file, 0);
	else
		file = ft_strdup(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (handle_error(file), free(file), 1);
	dup2(fd, 0);
	close(fd);
	free(file);
	return (0);
}

static int	redirection_out(char *file, int append)
{
	int	fd;
	int	flags;

	if (!file || ambiguous_check(file))
		return (1);
	if (append)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	else
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	if (ft_strchr(file, '*'))
		file = remove_quotes(&file, 0);
	else
		file = ft_strdup(file);
	fd = open(file, flags, 0644);
	if (fd < 0)
		return (handle_error(file), free(file), 1);
	dup2(fd, 1);
	close(fd);
	return (free(file), 0);
}

static int	redirection_heredoc(t_cmd *cmd)
{
	if (cmd->herdoc_pip[0] == -1)
		return (1);
	dup2(cmd->herdoc_pip[0], 0);
	close(cmd->herdoc_pip[0]);
	cmd->herdoc_pip[0] = -1;
	return (0);
}

static int	find_last_heredoc(t_cmd *cmd)
{
	int	i;
	int	last;

	i = 0;
	last = -1;
	while (cmd->symbols[i])
	{
		if (ft_strcmp(cmd->symbols[i], "<<") == 0)
			last = i;
		i++;
	}
	return (last);
}

int	setup_redirection(t_cmd *cmd, int *error)
{
	int	i;
	int	result;
	int	last_heredoc;

	if (!cmd || !cmd->symbols || !cmd->files)
		return (0);
	last_heredoc = find_last_heredoc(cmd);
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
		else if (ft_strcmp(cmd->symbols[i], "<<") == 0 && i == last_heredoc)
			result = redirection_heredoc(cmd);
		i++;
	}
	if (result)
		*error = 1;
	return (result);
}
