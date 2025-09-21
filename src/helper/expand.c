/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:49:42 by msidry            #+#    #+#             */
/*   Updated: 2025/09/21 13:58:11 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static int expand_it(char *dollar, t_env *env, char **result);
static int appand_it(char *str, char **result);
static char *extract_ref(char *str);
static int is_breaker(int c);
char *expand_handler(char *str, t_env *env)
{
    char *result;
    int squotes;
    int dquotes;
    int idx;
    
    squotes = 0;
    dquotes = 0;
    result = NULL;
    idx = 0;
    if (is_expandable(str))
    {
        while (*str)
        {
            squotes += (*str == '\'' && !(dquotes & 1));
            dquotes += (*str == '"' && !(squotes & 1));
            if (*str == '$' && !(squotes & 1))
                str += expand_it(str, env, &result);
            else
                str += append_it(str, &result);
        }  
    }
    else
    return (ft_strdup(str));
}

static int expand_it(char *dollar, t_env *env, char **result)
{
    char *ref;
    char *idx;

    if (!result)
        return (0);
    ref = extract_ref(dollar);
    idx = ft_strlen(ref) + 1;
    *result = concat3(*result, getvalue(env, ref), NULL, 1);
    free (ref);
    return (idx);
}

static int appand_it(char *str, char **result)
{
    char *chunk;
    int idx;
    
    idx = 0;
    while (str[idx])
    {
        if (is_breaker(str[idx]))
            break;
        idx++;
    }
    chunk = ft_substr(str, 0, idx - 1);
    *result = concat3(*result, chunk, NULL, 1 | 2);
    return (idx);
}

static char *extract_ref(char *str)
{
    int idx;

    idx = 0;
    while (str[idx])
    {
        if (is_breaker(str[idx]))
            break ;
        idx++;
    }
    return (ft_substr(str, 1, idx));
}

static int is_breaker(int c)
{
    if (is_space(c))
        return (1);
    if (c == '$')
        return (1);
    if (c == '\'' || c == '"')
        return (1);
}