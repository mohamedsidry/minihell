/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:09:58 by azghibat          #+#    #+#             */
/*   Updated: 2025/09/26 18:11:33 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void	echo_helper(t_cmd *cmd, int i);

void    run_echo(t_cmd *cmd)
{
	int	i;
	int	new_line;
	int j;
	
	if (!cmd->args || !cmd->args[1])
	{
		printf("\n");
		return ;
	}
	i = 1;
	new_line = 1;
	if (cmd->args[1] && !ft_strncmp(cmd->args[1], "-n", 2))
	{
		j = 1;
		while (cmd->args[1][j] && cmd->args[1][j] == 'n')
			j++;
		if (!cmd->args[1][j])
		{
			new_line = 0;
			i++;
		}
	}
	echo_helper(cmd, i);
	if (new_line)
		printf("\n");
}

static void	echo_helper(t_cmd *cmd, int i)
{
	int	len;

	while (cmd->args[i])
	{
		len = 0;
		while (cmd->args[i][len])
			len++;
		write(STDOUT_FILENO, cmd->args[i], len);
		if (cmd->args[i + 1])
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
}

