/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 09:53:14 by msidry            #+#    #+#             */
/*   Updated: 2025/10/08 22:16:10 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_env	*env_export(t_env **env, char *key, char *value)
{
	t_env	*target;
	char	*payload;

	if (!env)
		return (free(key), free(value), NULL);
	target = env_find(*env, key);
	if (target)
	{
		if (value)
			setvalue(*env, ft_strdup(key), ft_strdup(value));
		target->ishidden = 0;
		free(key);
		free(value);
		return (target);
	}
	if (value)
		payload = concat3(key, "=", value, 0);
	else
		payload = ft_strdup(key);
	target = node_create(payload);
	env_addback(env, target);
	free(payload);
	free(key);
	free(value);
	return (target);
}
