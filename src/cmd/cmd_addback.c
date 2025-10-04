/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_addback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 07:46:24 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 22:30:41 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_cmd	*cmd_addback(t_cmd **cmds, t_cmd *cmd)
{
	t_cmd	*tail;

	if (!cmds || !cmd)
		return (NULL);
	tail = cmd_last(cmds);
	if (!tail)
	{
		*cmds = cmd;
		cmd->prev = NULL;
	}
	else
	{
		tail->next = cmd;
		cmd->next = NULL;
		cmd->prev = tail;
	}
	return (cmd);
}
