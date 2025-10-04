/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_iter2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:59:29 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 22:32:50 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	cmd_iter2(t_cmd **cmds, void *ref, t_cmd *(func)(t_cmd *cmd, void *rf))
{
	t_cmd	*head;
	t_cmd	*ret;

	if (!cmds || !(*cmds) || !func)
		return ;
	head = *cmds;
	while (head)
	{
		ret = func(head, ref);
		if (!ret)
			return (cmd_clear(cmds));
		head = head->next;
	}
}
