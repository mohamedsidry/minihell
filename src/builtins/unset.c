/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:23:01 by azghibat          #+#    #+#             */
/*   Updated: 2025/09/25 17:35:03 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/main.h"

void	run_unset(t_cmd *cmd, t_env **env)
{
	int	i;

	if (!cmd || !env)
		return ;
	if (!cmd->args[1])
	{
		printf("%s: : invalid parameter name\n", cmd->args[0]);
		cmd->exitcode = ft_strdup("1");
		return ;
	}
	i = 1;
	while (cmd->args[i])
	{
		env_unset(env, cmd->args[i]);
		i++;
	}
	cmd->exitcode = ft_strdup("0");
}
