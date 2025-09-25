/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 09:59:40 by msidry            #+#    #+#             */
/*   Updated: 2025/09/21 10:20:31 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

size_t cmd_length(t_cmd *cmds)
{
    size_t length;

    length = 0;
    if (!cmds)
        return (0);
    while (cmds)
    {
        length++;
        cmds = cmds->next;
    }
    return (length);
}