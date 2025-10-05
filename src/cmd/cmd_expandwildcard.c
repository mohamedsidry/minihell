/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expandwildcard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:15:28 by msidry            #+#    #+#             */
/*   Updated: 2025/10/05 16:13:15 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static char	*star_handler(void);

t_cmd	*cmd_expandwildcard(t_cmd *cmd, void *reff)
{
	int		idx;
	char	*result;
	int		*error;

	error = (int *)reff;
	idx = 0;
	if (!cmd)
		return (cmd);
	while (cmd->args && cmd->args[idx])
	{
		if (!ft_strcmp(cmd->args[idx], "*"))
		{
			result = star_handler();
			if (!result)
				return (*error = 1, cmd);
			free(cmd->args[idx]);
			cmd->args[idx] = result;
		}
		idx++;
	}
	return (cmd);
}

static char	*star_handler(void)
{
	char			*result;
	DIR				*opdir;
	struct dirent	*file;
	char			*cwd;

	result = NULL;
	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (NULL);
	opdir = opendir(cwd);
	if (!opdir)
		return (free(cwd), NULL);
	while ((file = readdir(opdir)))
	{
		if (file->d_name[0] != '.')
			result = concat3(result, file->d_name, " ", 1);
	}
	closedir(opdir);
	nullstr(&cwd);
	return (result);
}
