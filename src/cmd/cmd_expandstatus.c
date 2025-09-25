/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expandstatus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 07:55:55 by msidry            #+#    #+#             */
/*   Updated: 2025/09/23 12:54:30 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"


t_cmd *cmd_expandstatus(t_cmd *cmd, void *reff)
{
    int *exitcode;
    t_cmd *tmp;

    exitcode = (int *)reff;
    if (!cmd || !reff)
        return (cmd);
    tmp = cmd;
    while (tmp)
    {
        tmp->exitcode = ft_itoa(*exitcode);
        tmp = tmp->next;
    }
    return (cmd);
}


