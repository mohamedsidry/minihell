/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:56:21 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/09 13:05:01 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	run_env(t_cmd *cmd, t_env **env, int *error)
{
	*error = 0;
	if (!cmd || !env)
		return ;
	if (cmd->args[1])
	{
		ft_putstr_fd("minishell: env: too many arguments\n", 2);
		*error = 1;
		return ;
	}
	env_read(*env);
}
