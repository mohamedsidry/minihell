/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:09:36 by anasszgh          #+#    #+#             */
/*   Updated: 2025/10/08 22:19:38 by anasszgh         ###   ########.fr       */
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
		{
			free(tmp);
			break ;
		}
		if (toexpand)
			data = expand_handler(tmp, env, cmd);
		else
			data = ft_strdup(tmp);
		ft_putendl_fd(data, cmd->herdoc_pip[1]);
		free(tmp);
		free(data);
	}
}

void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
