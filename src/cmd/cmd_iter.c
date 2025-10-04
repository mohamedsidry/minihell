/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:04:21 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 22:32:36 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	cmd_iter(t_cmd **cmds, t_cmd *(func)(t_cmd *cmd))
{
	t_cmd	*head;
	t_cmd	*ret;

	if (!cmds || !(*cmds) || !func)
		return ;
	head = *cmds;
	while (head)
	{
		ret = func(head);
		if (!ret)
			return (cmd_clear(cmds));
		head = head->next;
	}
}
