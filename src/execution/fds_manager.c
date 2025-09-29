/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 22:49:28 by anasszgh          #+#    #+#             */
/*   Updated: 2025/09/26 18:05:43 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int	save_fds(int *saved_fds)
{
	if (!saved_fds)
		return (-1);
	saved_fds[0] = dup(STDIN_FILENO);
	saved_fds[1] = dup(STDOUT_FILENO);
	if (saved_fds[0] == -1 || saved_fds[1] == -1)
	{
		if (saved_fds[0] != -1)
			close(saved_fds[0]);
		if (saved_fds[1] != -1)
			close(saved_fds[1]);
		return (-1);
	}
	return (0);
}

void	restore_fds(int *saved_fds)
{
	if (!saved_fds)
		return ;
	if (saved_fds[0] != -1)
	{
		dup2(saved_fds[0], STDIN_FILENO);
		close(saved_fds[0]);
	}
	if (saved_fds[1] != -1)
	{
		dup2(saved_fds[1], STDOUT_FILENO);
		close(saved_fds[1]);
	}
}
