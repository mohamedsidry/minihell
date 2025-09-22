/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:49:42 by msidry            #+#    #+#             */
/*   Updated: 2025/09/22 14:54:00 by msidry           ###   ########.fr       */
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
            str += expand_it(str, env, &result);
        else
        {
            str += appand_it(str, &result);
            if (ft_strchr("'\"", *str))
            {
                squotes += (*str == '\'' && !(dquotes & 1));
                dquotes += (*str == '"' && !(squotes & 1));
                str++;
            }
        }
    }
    return (result);
}

static int expand_it(char *dollar, t_env *env, char **result)
{
    char *ref;

    if (!result)
        return (0);
    ref = extract_ref(dollar);
    *result = concat3(*result, getvalue(env, ref + 1), NULL, 1);
    free (ref);
    return (ft_strlen(ref));
}

static int appand_it(char *str, char **result)
{
    char *chunk;
    int idx;
    
    idx = 0;
    while (str[idx])
    {
        idx++;
        if (is_breaker(str[idx]))
            break;
    }
    chunk = ft_substr(str, 0, idx + 1);
    if (str[idx] == '$' || ft_strchr("\"'", str[idx]))
        idx--;
    *result = concat3(*result, chunk, NULL, 1 | 2);
    return (ft_strlen(chunk) - 1);
}

static char *extract_ref(char *str)
{
    int idx;

    idx = 0;
    while (str[idx])
    {
        idx++;
        if (is_breaker(str[idx]))
            break ;
    }
    return (ft_substr(str, 0, idx));
}

static int is_breaker(int c)
{
    if (is_space(c))
        return (1);
    if (c == '$')
        return (1);
    if (c == '\'' || c == '"')
        return (1);
    return (0);
}