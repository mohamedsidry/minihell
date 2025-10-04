/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:47:37 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 01:57:00 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/main.h"

void sg_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
}

int main(int argc, char *argv[], char *env[])
{
	char	*input;
	int		error;
	t_env	*new_env;
	t_cmd	*commands;

	input = NULL;
	new_env = NULL;
	commands = NULL;
	(void)argc;
	(void)argv;
	signal(SIGINT, sg_handler);
	signal(SIGQUIT, SIG_IGN);
	env_handler(&new_env, env, CREATE | SYNC);
	while (1)
	{
		proreadline(&input, &new_env, &error);
		lexer(&commands, &input, &new_env, &error);
		if (commands)
		{
			executor(&commands, &new_env, &error);
			cmd_clear(&commands);
		}
		if (input)
		{
			free(input);
			input = NULL;
		}
	}
	return (0);
}
