/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_serializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 09:44:15 by msidry            #+#    #+#             */
/*   Updated: 2025/09/19 09:52:01 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"


char **env_serializer(t_env *envlst)
{
    size_t size;
    size_t idx;
    char **envarr;
    
    if (!envlst)
        return (NULL);
    size = env_size(envlst);
    idx = 0;
    envarr = ft_calloc(sizeof(char *), size + 1);
    while (envlst)
    {
        if (!envlst->ishidden)
            envarr[idx] = concat3(envlst->key, envlst->value, "=", 0);
        envlst = envlst->next;
    }
    return (envarr);
}