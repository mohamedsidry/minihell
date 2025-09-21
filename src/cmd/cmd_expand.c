/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:27:19 by msidry            #+#    #+#             */
/*   Updated: 2025/09/21 11:42:20 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void expand_args(t_cmd *cmd);
static void expand_rediections(t_cmd *cmd);

t_cmd   *cmd_expand(t_cmd *cmd)
{
    //TODO: expand args and files;
    return (cmd);
}


static void expand_args(t_cmd *cmd)
{
    (void)cmd;
   //TODO: expend args ; 
}

static void expand_rediections(t_cmd *cmd)
{
    (void)cmd;
    //TODO: expend files;
}
