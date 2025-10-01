/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:00:00 by anasszgh          #+#    #+#             */
/*   Updated: 2025/10/01 03:27:24 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static int	count_commands(t_cmd *cmd)
{
	t_cmd	*current;
	int		count;

	count = 0;
	current = cmd;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	wait_for_all(t_cmd *cmd)
{
	int	status;
	int	count;

	count = count_commands(cmd);
	while (count > 0)
	{
		wait(&status);
		count--;
	}
}