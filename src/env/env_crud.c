/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_crud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:15:51 by msidry            #+#    #+#             */
/*   Updated: 2025/09/20 11:34:21 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"


void env_create(t_env **myenv, char *env[])
{
    t_env *node;
    int idx;

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

void env_delete(t_env **myenv)
{
    t_env *tmp;
    t_env *current;

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

t_env *env_addback(t_env **myenv, t_env *node)
{
    t_env *last;

    if (!myenv)
        return (NULL);
    if (!(*myenv))
        return (*myenv = node, node);
    last = env_last(*myenv);
    last->next = node;
    return (node); 
}

void env_sync(t_env **env)
{
    t_env *lvlnode;
    t_env *pathnode;
    char *cwd;

    if (!env)
        return ;
    lvlnode = env_find(*env, "SHLVL");
    if (!lvlnode)
        env_addback(env, node_create("SHLVL=1"));
    else
        setvalue(*env, "SHLVL", ft_itoa(ft_atoi(lvlnode->value) + 1));
    pathnode = env_find(*env, "PATH");
    cwd = getcwd(NULL, 0);
    if (!pathnode)
        env_addback(env, node_create(concat3("PATH", cwd, "=", 2)));
    else if (ft_strnstr(pathnode->value, cwd, ft_strlen(pathnode->value)))
        return  free(cwd);
    else
        setvalue(*env, "PATH", concat3(pathnode->value, cwd, ":", 2));
}
void env_read(t_env *env)
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

// t_env *env_update(t_env *env, char *key, char *value, int state)
// {
//     t_env *node;
//     t_env *target;
//     char *payload;
//     char *newvalue;
//     node = NULL;
//     if (!env || !key)
//         return (NULL);
//     target = env_find(env, key);
//     if (target)
//     {
//         newvalue = ft_strdup(value);
//         free(value);
//         node->value = newvalue;
//         node->ishidden = state;
//         return (node);
//     }
//     payload = concat3(key, value, "=", 0);
//     node = env_addback(&env, node_create(payload));
//     free(payload);
//     return (node);
// }