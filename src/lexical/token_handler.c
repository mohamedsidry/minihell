/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:52:12 by msidry            #+#    #+#             */
/*   Updated: 2025/09/20 19:13:32 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

char *handle_quotes(char *str)
{
    int squotes;
    int dquotes;
    size_t idx;

    squotes = 0;
    dquotes = 0;
    idx = 0;
    while (str[idx])
    {
        squotes += (str[idx] == '\'' && !(dquotes & 1));
        dquotes += (str[idx] == '"' && !(squotes & 1));
        if (!(squotes & 1) && !(dquotes & 1) && str[idx] != '\'' && str[idx] != '"')
        {
            if (ft_strchr("&><;|", str[idx]) || is_space(str[idx]))
                return (ft_substr(str, 0, idx));
        }
        idx++;
    }
    return (ft_substr(str, 0, idx));
}

char *handle_in(char *str)
{
    if (*str == *(str + 1))
        return (ft_strdup("<<"));
    else if (*(str + 1) == '&')
        return (ft_strdup("<&"));
    else
        return (ft_strdup("<"));
}

char *handle_out(char *str)
{
    if (ft_strchr("&|>", *(str + 1)))
        return (ft_substr(str, 0, 2));
    else
        return (ft_strdup(">"));
}

char *handle_amp(char *str)
{
    if (ft_strchr(">", *(str + 1)))
        return (ft_substr(str, 0, 2));
    else
        return (ft_strdup("&"));
}

char *handle_txt(char *str)
{
    size_t idx;
    int squotes;
    int dquotes;

    squotes = 0;
    dquotes = 0;

    idx = 0;
    while (str[idx])
    {
        squotes += (str[idx] == '\'' && !(dquotes & 1));
        dquotes += (str[idx] == '"' && !(squotes & 1));
        if (!(dquotes & 1) && !(squotes & 1))
        {
            if (ft_strchr("<>|;&", str[idx]) || is_space(str[idx]))
                return (ft_substr(str, 0, idx));
        }
        idx++;
    }
    return (ft_substr(str, 0, idx ));
}

char *handle_pipe(char *str)
{
    if (*(str + 1) == '&')
        return (ft_substr(str, 0, 2));
    return (ft_substr(str, 0, 1));
}