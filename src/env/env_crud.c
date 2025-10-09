/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_crud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:15:51 by msidry            #+#    #+#             */
/*   Updated: 2025/10/08 22:30:49 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	env_create(t_env **myenv, char *env[])
{
	t_env	*node;
	int		idx;

	idx = 0;
	while (env[idx])
	{
		node = node_create(env[idx]);
		if (!node)
		{
			env_delete(myenv);
			return ;
		}
		env_addback(myenv, node);
		idx++;
	}
}

void	env_delete(t_env **myenv)
{
	t_env	*tmp;
	t_env	*current;

	if (!myenv)
		return ;
	current = *myenv;
	while (current)
	{
		tmp = current->next;
		node_delete(current);
		current = tmp;
	}
	*myenv = NULL;
}

t_env	*env_addback(t_env **myenv, t_env *node)
{
	t_env	*last;

	if (!myenv)
		return (NULL);
	if (!(*myenv))
		return (*myenv = node, node);
	last = env_last(*myenv);
	last->next = node;
	return (node);
}

void	env_sync(t_env **env)
{
	t_env	*lvlnode;
	char	*new_shlvl;

	if (!env)
		return ;
	lvlnode = env_find(*env, "SHLVL");
	if (!lvlnode)
		env_addback(env, node_create("SHLVL=1"));
	else
	{
		new_shlvl = ft_itoa(ft_atoi(lvlnode->value) + 1);
		setvalue(*env, ft_strdup("SHLVL"), new_shlvl);
	}
}

void	env_read(t_env *env)
{
	if (!env)
		return ;
	while (env)
	{
		if (!env->ishidden)
			node_read(env);
		env = env->next;
	}
}
