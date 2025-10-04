/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 09:59:40 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 22:33:04 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

size_t	cmd_length(t_cmd *cmds)
{
	size_t	length;

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
