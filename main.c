/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:59:37 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/05 21:59:41 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/main.h"

int	g_signal_receiv = 0;

void	sg_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		g_signal_receiv = SIGINT;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	main(int argc, char *argv[], char *env[])
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
		executor(&commands, &new_env, &error);
		cmd_clear(&commands);
		nullstr(&input);
	}
	return (0);
}
