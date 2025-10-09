/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 09:53:14 by msidry            #+#    #+#             */
/*   Updated: 2025/10/09 12:26:04 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_env	*env_export(t_env **env, char *keyvalue)
{
	t_env	*target;

	if (!env)
		return (NULL);
	target = env_update(env, keyvalue);
	return (target);
}
