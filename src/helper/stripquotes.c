/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stripquotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:43:59 by msidry            #+#    #+#             */
/*   Updated: 2025/09/21 21:44:03 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static size_t count_set(char *str, char *set);
static void strrmove(char **strptr, char *set);

void stripquotes(char **str)
{
    char target;
    char *tmp;
    int sqoutes;
    int dquotes;

    sqoutes = 0;
    if (!str || !(*str))
        return ;
    if (!ft_strchr(*str, '\'') && !ft_strchr(*str, '"'))
        return ;
    tmp = *str - 1;
    while(tmp++)
    {
        sqoutes += (*tmp == '\'' & !(dquotes & 1));
        sqoutes += (*tmp == '\'' & !(dquotes & 1));
        if (sqoutes & 1 && *tmp == '\'')
            target = '\'';
        else if (dquotes & 1 && *tmp == '"')
            target = '"';
        if (*tmp == target)
            *tmp = '$';
    }
    strremove(str, "$");
}
static void strrmove(char **strptr, char *set)
{
    char *result;
    size_t counter;
    char *tmp;
    int idx;

    if(!strptr || !set)
        return ;
    tmp = *strptr;
    counter = count_set(*strptr, set);
    result = ft_calloc(ft_strlen(*strptr) - counter + 1, sizeof(char));
    idx = 0;
    while (*tmp)
    {
        if (!ft_strchr(set, *tmp))
        {
            result[idx] = *tmp;
            idx++;
        }
        tmp++;
    }
    nullstr(strptr);
    *strptr = result;
}


static size_t count_set(char *str, char *set)
{
    size_t count;

    count = 0;
    if (!str || !set)
        return (0);
    while (*str)
    {
        if (ft_strchr(set, *str))
            count++;
        str++;
    }
    return (count);
}