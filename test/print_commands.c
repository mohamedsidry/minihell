/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:41:14 by msidry            #+#    #+#             */
/*   Updated: 2025/10/05 16:15:25 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static void	cmd_read(t_cmd *command);

void	print_commands(t_cmd *cmd)
{
	while (cmd)
	{
		cmd_read(cmd);
		cmd = cmd->next;
	}
}

static void	cmd_read(t_cmd *command)
{
	int	idx;

	idx = -1;
	if (!command)
	{
		printf("No command !\n");
		return ;
	}
	printf("FULLCOMMAND : `%s`\n", command->fullcmd);
	if (!command->args || !command->args[0])
		printf("ARGS  : [null]\n");
	else
	{
		printf("ARGS : [");
		while (command->args[++idx])
		{
			printf("%s", command->args[idx]);
			if (command->args[idx + 1])
				printf(", ");
		}
		idx = -1;
		printf("]\n");
	}
	if (!command->symbols || !command->symbols[0])
		printf("SYMBOLS  : [null]\n");
	else
	{
		printf("SYMBOLS : [");
		while (command->symbols[++idx])
		{
			printf("%s", command->symbols[idx]);
			if (command->symbols[idx + 1])
				printf(", ");
		}
		idx = -1;
		printf("]\n");
	}
	if (!command->files || !command->files[0])
		printf("FILES  : [null]\n");
	else
	{
		printf("FILES : [");
		while (command->files[++idx])
		{
			printf("%s", command->files[idx]);
			if (command->files[idx + 1])
				printf(", ");
		}
		idx = -1;
		printf("]\n");
	}
	printf("IS BUILTIN : ");
	if (command->isbuiltin)
		printf("true\n");
	else
		printf("false\n");
}
