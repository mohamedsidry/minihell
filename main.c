/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:59:37 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/10 11:02:38 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/main.h"

int	g_signal_receiv = 0;

static void	ctr_c_handler(int *error);

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
	signal(SIGINT, sg_handler);
	signal(SIGQUIT, SIG_IGN);
	env_handler(&new_env, argv, env, CREATE | SYNC);
	while (1)
	{
		proreadline(&input, &new_env, &error);
		ctr_c_handler(&error);
		lexer(&commands, &input, &new_env, &error);
		executor(&commands, &new_env, &error);
		cmd_clear(&commands);
		nullstr(&input);
	}
	return (0);
}

static void	ctr_c_handler(int *error)
{
	if (g_signal_receiv == SIGINT)
		*error = 1;
	g_signal_receiv = 0;
}
