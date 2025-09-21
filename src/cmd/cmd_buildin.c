/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_buildin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:59:51 by msidry            #+#    #+#             */
/*   Updated: 2025/09/21 11:02:51 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_cmd *cmd_builtin(t_cmd *cmd)
{
    if (!cmd)
        return (NULL);
    if (!cmd->args)
        return (cmd);
    if (is_builtin(cmd->args[0]))
        cmd->isbuiltin = 1;
    return (cmd);
}