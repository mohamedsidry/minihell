/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:47:37 by msidry            #+#    #+#             */
/*   Updated: 2025/10/05 17:38:50 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/main.h"

int	signal_receiv = 0;

void	sg_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		signal_receiv = SIGINT;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static void	shell_loop(t_env *new_env)
{
	char	*input;
	int		error;
	t_cmd	*commands;

	input = NULL;
	commands = NULL;
	error = 0;
	while (1)
	{
		proreadline(&input, &new_env, &error);
		if (signal_receiv == SIGINT)
		{
			error = 130;
			signal_receiv = 0;
		}
		lexer(&commands, &input, &new_env, &error);
		executor(&commands, &new_env, &error);
		cmd_clear(&commands);
		nullstr(&input);
	}
}

int	main(int argc, char *argv[], char *env[])
{
	t_env	*new_env;

	(void)argc;
	(void)argv;
	new_env = NULL;
	signal(SIGINT, sg_handler);
	signal(SIGQUIT, SIG_IGN);
	env_handler(&new_env, env, CREATE | SYNC);
	shell_loop(new_env);
	return (0);
}
