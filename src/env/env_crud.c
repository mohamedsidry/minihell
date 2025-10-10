/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_crud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:15:51 by msidry            #+#    #+#             */
/*   Updated: 2025/10/09 13:07:10 by msidry           ###   ########.fr       */
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
			return (env_delete(myenv));
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

void	env_read(t_env *env)
{
	if (!env)
		return ;
	while (env)
	{
		if (!env->ishidden && env->e_value)
			node_read(env);
		env = env->next;
	}
}

t_env	*env_update(t_env **myenv, char *payload)
{
	char	*key;
	char	*e_value;
	char	*x_value;
	t_env	*target;

	if (!myenv || !payload)
		return (NULL);
	key = getprefix(payload, '=');
	if (!key)
		key = ft_strdup(payload);
	target = env_find(*myenv, key);
	if (!target)
		return (free(key), env_addback(myenv, node_create(payload)));
	e_value = getsuffix(payload, '=');
	if (e_value && !e_value[0])
		nullstr(&e_value);
	x_value = ft_strdup(e_value);
	target = node_update(target, key, e_value, x_value);
	return (target);
}
