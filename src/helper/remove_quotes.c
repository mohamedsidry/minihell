/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stripquotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:43:59 by msidry            #+#    #+#             */
/*   Updated: 2025/09/22 11:48:56 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void remove_quotes(char **str)
{
    char *tmp;
    char *result;
    int idx;
    char quote_char;

    
    if (!str || !(*str))
        return ;
    if (!ft_strchr(*str, '\'') && !ft_strchr(*str, '"'))
        return ;
    tmp = *str;
    result = ft_calloc(ft_strlen(*str) + 1, sizeof(char));
    idx = 0;
    while(*tmp)
    {
         if (ft_strchr("'\"", *tmp))
        {
            quote_char = *tmp;
            tmp++; 
            while (*tmp && *tmp != quote_char)
            {
                result[idx++] = *tmp;
                tmp++;
            }
            if (*tmp == quote_char)
                tmp++;
        }
        else
        {
            result[idx++] = *tmp;
            tmp++;
        }
    }
    nullstr(str);
    *str = result;
}
