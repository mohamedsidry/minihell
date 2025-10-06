/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_buildin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:59:51 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 22:30:54 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_cmd	*cmd_builtin(t_cmd *cmd)
{
	if (!cmd)
		return (NULL);
	if (!cmd->args)
		return (cmd);
	if (is_builtin(cmd->args[0]))
		cmd->isbuiltin = 1;
	return (cmd);
}
