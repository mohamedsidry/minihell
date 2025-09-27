/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:49:42 by msidry            #+#    #+#             */
/*   Updated: 2025/09/26 18:54:31 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static int expand_it(char *dollar, t_env *env, t_cmd *cmd, char **result);
static int appand_it(char *str, char **result);
static char *extract_ref(char *str);
static int is_breaker(int c);
static int is_special(int c);

char *expand_handler(char *str, t_env *env, t_cmd *cmd)
{
    char *result;
    int squotes;
    int dquotes;
    
    squotes = 0;
    dquotes = 0;
    result = NULL;
    if (!str || !env)
        return (NULL);
    while (*str)
    {
        squotes += (*str == '\'' && !(dquotes & 1));
        dquotes += (*str == '"' && !(squotes & 1));
        if ((*str == '$') && !(squotes & 1))
            str += expand_it(str, env, cmd, &result);
        else
            str += appand_it(str, &result);
        
    }
    return (result);
}

static int expand_it(char *dollar, t_env *env,  t_cmd *cmd, char **result)
{
    char *ref;
    size_t len;

    if (!result)
        return (0);
    ref = extract_ref(dollar);
    if (!ft_strcmp(ref, "$0"))
        *result = concat3(*result, getvalue(env, "_"), NULL, 1);
    else if (!ft_strcmp(ref, "$?"))
        *result = concat3(*result, cmd->exitcode, NULL, 1);
    else if (!ft_strcmp(ref, "$$"))
        *result = concat3(*result, "1337", NULL, 1);
    else if (!ft_strcmp(ref, "$_"))
        *result = concat3(*result, cmd->prevcmd, NULL, 1);
    else
        *result = concat3(*result, getvalue(env, ref + 1), NULL, 1);
    len = ft_strlen(ref);
    free (ref);
    return (len);
}

static int appand_it(char *str, char **result)
{
    char *tmp;

    tmp = NULL;
    tmp = ft_substr(str, 0, 1);
    *result = concat3(*result, tmp, NULL, 1 | 2);
    return (1);
}

static char *extract_ref(char *str)
{
    int idx;

    idx = 0;
    while (str[idx])
    {
        idx++;
        if (is_special(str[idx]) && idx++)
            break;
        if (is_breaker(str[idx]))
            break ;
    }
    return (ft_substr(str, 0, idx));
}

static int is_breaker(int c)
{
    return (!ft_isdigit(c) && !ft_isalpha(c) && c != '_');
}

static int is_special(int c)
{
    char *ret;

    ret = ft_strchr("$~?!-+^&:#", c);
    if (ret)
        return (1);
    return (0);
}