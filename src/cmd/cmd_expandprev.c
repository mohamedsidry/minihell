/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expandprev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:04:23 by msidry            #+#    #+#             */
/*   Updated: 2025/09/23 13:00:51 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_cmd *cmd_expandprev(t_cmd *cmd, void *reff)
{
    t_cmd *tmp;

    if (!cmd || !reff)
        return (cmd);
    tmp = cmd;
    tmp->prevcmd = ft_strdup(getvalue(((t_env *)reff), "_"));
    tmp = tmp->next;
    while (tmp)
    {
        tmp->prevcmd = ft_strdup("");
        tmp = tmp->next;
    }
    return (cmd);
}