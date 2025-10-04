/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_findpaths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:05:26 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 22:32:11 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static char	*findpath(t_env *env, char *arg0, int usefree);

t_cmd	*cmd_findpaths(t_cmd *cmd, void *reff)
{
	t_env	*env;
	t_cmd	*tmp;

	env = (t_env *)reff;
	tmp = cmd;
	while (tmp)
	{
		if (tmp->args && !tmp->isbuiltin)
		{
			if (access(tmp->args[0], F_OK | X_OK))
				tmp->args[0] = findpath(env, tmp->args[0], 1);
		}
		tmp = tmp->next;
	}
	return (cmd);
}

static char	*findpath(t_env *env, char *arg0, int usefree)
{
	char	**paths;
	int		idx;
	char	*fullpath;
	char	*result;

	idx = -1;
	if (!arg0 || !arg0[0] || arg0[0] == '.')
		return (arg0);
	paths = ft_split(getvalue(env, "PATH"), ':');
	while (paths && paths[++idx])
	{
		fullpath = concat3(paths[idx], arg0, "/", 0);
		if (!access(fullpath, F_OK | X_OK))
		{
			if (usefree)
				nullstr(&arg0);
			return (free2d(&paths), fullpath);
		}
		nullstr(&fullpath);
	}
	result = ft_strdup(arg0);
	if (usefree)
		nullstr(&arg0);
	return (free2d(&paths), result);
}
