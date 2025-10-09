/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_sync.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 09:40:47 by msidry            #+#    #+#             */
/*   Updated: 2025/10/09 13:09:03 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void sync_pwd(t_env **env);
static void sync_shlvl(t_env **env);
static void sync_name(t_env **env, char *name);

void    env_sync(t_env **env, char *argv[])
{
	if (!env)
        return ;
    sync_pwd(env);
	sync_shlvl(env);
    sync_name(env, argv[0]);
}
static void sync_pwd(t_env **env)
{
    char    *payload;
    char    *cwd;

    cwd = getcwd(NULL, 0);
    payload = concat3("PWD", cwd, "=", 0);
    env_update(env, payload);
    nullstr(&cwd);
    nullstr(&payload);
}

static void sync_shlvl(t_env **env)
{
    t_env *target;
    char *newval;
    char *payload;

    target = env_find(*env, "SHLVL");
    if (!target)
    {
        env_update(env, "SHLVL=1");
        return ;
    }
    newval = ft_itoa(ft_atoi(target->e_value) + 1);
    payload = concat3("SHLVL", newval, "=", 0);
    env_update(env, payload);
    nullstr(&newval);
    nullstr(&payload);
}
static void sync_name(t_env **env, char *name)
{
    char *payload;

    if (!name || !ft_strchr(name, '/'))
        return ;
    payload = concat3("_", ft_strchr(name, '/') + 1 , "=", 0);
    if (!payload)
        return ;
    env_update(env, payload);
    nullstr(&payload);
}

// static void sync_path(t_env **env)
// {
//     char *cwd;
//     t_env *target;
//     char *val;
//     char *payload;
//     cwd = getcwd(NULL, 0);
//     target = env_find(*env, "PATH");
//     if (!target)
//         val = ft_strdup(cwd);
//     else
//         val = concat3(target->e_value, cwd, ':', 0);
//     payload = concat3("PATH", val, "=", 0);
//     target = env_update(env, payload);
//     nullstr(&cwd);
//     nullstr(&val);
//     nullstr(&payload);
// }
