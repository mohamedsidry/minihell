/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expandprev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:04:23 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 22:31:56 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_cmd	*cmd_expandprev(t_cmd *cmd, void *reff)
{
	t_cmd	*tmp;

	if (!cmd || !reff)
		return (cmd);
	tmp = cmd;
	tmp->prevcmd = ft_strdup(getvalue(((t_env *)reff), "_"));
	tmp = tmp->next;
	while (tmp)
	{
		tmp->prevcmd = NULL;
		tmp = tmp->next;
	}
	return (cmd);
}
