/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 20:40:48 by msidry            #+#    #+#             */
/*   Updated: 2025/10/08 22:39:43 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void	init_minimal_env(t_env **myenv)
{
	char	*cwd;
	char	*payload;

	cwd = getcwd(NULL, 0);
	env_addback(myenv, node_create("SHLVL=1"));
	env_addback(myenv, node_create("_=/usr/bin/env"));
	if (cwd)
	{
		payload = concat3("PWD=", cwd, "", 0);
		env_addback(myenv, node_create(payload));
		free(payload);
		free(cwd);
	}
	payload = concat3("PATH=", "/usr/bin:/bin:/usr/local/bin", "", 0);
	env_addback(myenv, node_create(payload));
	free(payload);
}

void	env_handler(t_env **myenv, char *env[], t_action action)
{
	if (action & CREATE)
	{
		if (!env || !env[0])
			init_minimal_env(myenv);
		else
			env_create(myenv, env);
	}
	if (action & SYNC)
		env_sync(myenv);
	if (action & DELETE)
		env_delete(myenv);
}
