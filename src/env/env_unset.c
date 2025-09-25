/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 10:02:08 by msidry            #+#    #+#             */
/*   Updated: 2025/09/25 18:18:29 by anasszgh         ###   ########.fr       */
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