/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formater.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 12:02:51 by msidry            #+#    #+#             */
/*   Updated: 2025/09/20 18:58:09 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void smart_append(t_cmd *cmd, char **tokens, int *idx);
void formater(t_cmd **cmds, char **tokens, int *error)
{
    int idx;
    t_cmd *current;

    idx = 0;
    if (!tokens || !(*tokens))
        return ;
    while (tokens[idx])
    {
        current = cmd_create();
        while (tokens[idx] && ft_strcmp(tokens[idx], "|"))
        {
            current->fullcmd = concat3(current->fullcmd, tokens[idx], " ", 1);
            smart_append(current, tokens, &idx);
        }
        if (tokens[idx] && !ft_strcmp(tokens[idx], "|"))
        {
            current->separator = ft_strdup(tokens[idx]);
            idx++;
        }
        cmd_addback(cmds, current);
    }
    (void)error;  
}


static void smart_append(t_cmd *cmd, char **tokens, int *idx)
{
    if (tokens[*idx] && is_redirection(tokens[*idx]))
    {
        cmd->symbols = append_array(cmd->symbols, ft_strdup(tokens[*idx]));
        cmd->files = append_array(cmd->files, ft_strdup(tokens[1 + (*idx)]));
        (*idx) += 2;
    }
    else
    {
        cmd->args = append_array(cmd->args, tokens[*idx]);
        (*idx)++;
    }
}