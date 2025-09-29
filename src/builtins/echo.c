/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:09:58 by azghibat          #+#    #+#             */
/*   Updated: 2025/09/25 13:45:32 by azghibat         ###   ########.fr       */
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
    while (cmd->args[i])
    {
        printf("%s", cmd->args[i]);
        if (cmd->args[i + 1])
            printf(" ");
        i++;
    }
}
