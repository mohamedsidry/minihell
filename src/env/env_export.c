/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 09:53:14 by msidry            #+#    #+#             */
/*   Updated: 2025/09/19 10:25:25 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/main.h"


t_env *env_export(t_env **env, char *key, char *value)
{
    t_env *target;
    char *payload;

    if (!env)
        return (NULL);
    target = env_find(*env, key);
    if (target)
    {
        setvalue(*env, key, value);
        target->ishidden = 0;
        return (target);
    }
    
    payload = concat3(key, value, "=", 0);
    target = node_create(payload);
    env_addback(env, target);
    free(payload);
    return (target);
}