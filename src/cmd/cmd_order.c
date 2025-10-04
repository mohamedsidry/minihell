/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_order.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 07:47:57 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 22:33:14 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_cmd	*cmd_last(t_cmd **cmds)
{
	t_cmd	*head;

	if (!cmds || !(*cmds))
		return (NULL);
	head = *cmds;
	while (head->next)
		head = head->next;
	return (head);
}

t_cmd	*cmd_first(t_cmd *cmds)
{
	if (!cmds)
		return (NULL);
	while (cmds->prev)
		cmds = cmds->prev;
	return (cmds);
}
