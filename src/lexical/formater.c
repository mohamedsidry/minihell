/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formater.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 12:02:51 by msidry            #+#    #+#             */
/*   Updated: 2025/10/01 16:42:55 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void smart_append(t_cmd *cmd, char **tokens, int *idx);
void formater(t_cmd **cmds, char **tokens, int *error)
{
    int idx;
    t_cmd *current;
    int i;
    
    idx = -1;
    i = 0;
    if (!tokens || !(*tokens))
        return ;
    while (tokens[i])
    {
        current = cmd_create();
        current->idx = ++idx;
        while (tokens[i] && ft_strcmp(tokens[i], "|"))
            smart_append(current, tokens, &i);
        if (tokens[i] && !ft_strcmp(tokens[i], "|"))
        {
            current->separator = ft_strdup(tokens[i]);
            i++;
        }
        cmd_addback(cmds, current);
    }
    (void)error;  
}


static void smart_append(t_cmd *cmd, char **tokens, int *idx)
{
    if (!cmd || !tokens)
        return ;
    if (tokens[*idx] && is_redirection(tokens[*idx]))
    {
        cmd->fullcmd = concat3(cmd->fullcmd, tokens[*idx], " ", 1);
        cmd->symbols = append_array(cmd->symbols, tokens[*idx]);
        cmd->files = append_array(cmd->files, tokens[1 + (*idx)]);
        cmd->fullcmd = concat3(cmd->fullcmd, tokens[1 +(*idx)], " ", 1);
        (*idx) += 2;
    }
    else
    {
        cmd->fullcmd = concat3(cmd->fullcmd, tokens[*idx], " ", 1);
        cmd->args = append_array(cmd->args, tokens[*idx]);
        (*idx)++;
    }
}