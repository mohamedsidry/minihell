/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:56:15 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/09 18:40:39 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static int	check_n_flag(char *arg)
{
	int	j;

	if (!arg || ft_strncmp(arg, "-n", 2))
		return (0);
	j = 2;
	while (arg[j] && arg[j] == 'n')
		j++;
	if (!arg[j])
		return (1);
	return (0);
}

void	run_echo(t_cmd *cmd, int *error)
{
	int	i;
	int	new_line;

	*error = 0;
	if (!cmd->args || !cmd->args[1])
	{
		write(STDOUT_FILENO, "\n", 1);
		return ;
	}
	i = 1;
	new_line = 1;
	while (cmd->args[i] && check_n_flag(cmd->args[i]))
	{
   		new_line = 0;
    	i++;
	}
	while (cmd->args[i])
	{
		write(STDOUT_FILENO, cmd->args[i], ft_strlen(cmd->args[i]));
		if (cmd->args[i + 1])
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	if (new_line)
		write(STDOUT_FILENO, "\n", 1);
}
