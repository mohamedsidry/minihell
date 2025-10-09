/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 08:02:20 by msidry            #+#    #+#             */
/*   Updated: 2025/10/08 22:15:33 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_env	*env_find(t_env *env, char *key)
{
	if (!env || !key)
		return (NULL);
	while (env)
	{
		if (!ft_strcmp(env->key, key))
			return (env);
		env = env->next;
	}
	return (NULL);
}

size_t	env_size(t_env *env)
{
	size_t	size;

	size = 0;
	while (env)
	{
		size++;
		env = env->next;
	}
	return (size);
}

t_env	*env_last(t_env *env)
{
	if (!env)
		return (NULL);
	while (env->next)
		env = env->next;
	return (env);
}

void	setvalue(t_env *env, char *key, char *value)
{
	t_env	*target;
	char	*payload;

	if (!env)
		return (free(key), free(value));
	target = env_find(env, key);
	if (!target)
	{
		if (value)
			payload = concat3(key, "=", value, 0);
		else
			payload = ft_strdup(key);
		target = node_create(payload);
		env_addback(&env, target);
		free(payload);
		free(key);
		free(value);
		return ;
	}
	free(key);
	if (target->value)
		free(target->value);
	target->value = value;
	target->ishidden = 0;
}

char	*getvalue(t_env *env, char *key)
{
	t_env	*target;

	target = env_find(env, key);
	if (!target || target->ishidden)
		return (NULL);
	return (target->value);
}
