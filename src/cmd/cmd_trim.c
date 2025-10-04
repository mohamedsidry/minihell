/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_trim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:15:39 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 22:33:48 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_cmd	*cmd_trim(t_cmd *cmd)
{
	char	*trimed_cmd;

	trimed_cmd = ft_strtrim(cmd->fullcmd, "\n\t\v \b\r");
	if (!trimed_cmd)
		return (NULL);
	free(cmd->fullcmd);
	cmd->fullcmd = trimed_cmd;
	return (cmd);
}
