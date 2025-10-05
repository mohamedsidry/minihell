/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:57:37 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/05 21:57:38 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	herdoc_loop(t_cmd *cmd, t_env *env, char *limiter, int toexpand)
{
	char	*data;
	char	*tmp;

	data = NULL;
	tmp = NULL;
	signal(SIGINT, sig_handler);
	while (1)
	{
		tmp = readline("> ");
		if (!tmp || !ft_strcmp(tmp, limiter))
			break ;
		if (toexpand)
			data = expand_handler(tmp, env, cmd);
		else
			data = ft_strdup(tmp);
		ft_putendl_fd(data, cmd->herdoc_pip[1]);
		nullstr(&tmp);
		nullstr(&data);
	}
}
