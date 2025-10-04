/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_removequotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 07:55:55 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 22:33:37 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void	removecmdquotes(t_cmd *cmd);

t_cmd	*cmd_removequotes(t_cmd *cmd, void *reff)
{
	t_cmd	*tmp;

	if (!cmd || !reff)
		return (cmd);
	tmp = cmd;
	while (tmp)
	{
		removecmdquotes(tmp);
		tmp = tmp->next;
	}
	(void)reff;
	return (cmd);
}

static void	removecmdquotes(t_cmd *cmd)
{
	int	idx;

	if (!cmd)
		return ;
	idx = 0;
	while (cmd->args && cmd->args[idx])
	{
		cmd->args[idx] = remove_quotes(&cmd->args[idx], 1);
		idx++;
	}
	idx = 0;
	while (cmd->files && cmd->files[idx])
	{
		if (ft_strcmp(cmd->symbols[idx], "<<"))
			cmd->files[idx] = remove_quotes(&cmd->files[idx], 1);
		idx++;
	}
}
