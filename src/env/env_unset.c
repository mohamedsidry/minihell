/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 10:02:08 by msidry            #+#    #+#             */
/*   Updated: 2025/09/19 10:05:00 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"



void env_unset(t_env **env, char *key)
{
    t_env *target;
    
    if (!env || !(*env))
        return ;
    target = env_find(*env, key);
    if (target)
        target->ishidden = 1;
}