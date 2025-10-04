/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:03:59 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 01:20:58 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void cmd_clear(t_cmd **cmds)
{
	t_cmd	*current;
	t_cmd	*tmp;

	if (!cmds || !(*cmds))
		return ;
	current = *cmds;
	while (current)
	{
		tmp = current->next;
		cmd_delete(current);
		current = tmp;
	}
	*cmds = NULL;
}