/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:47:37 by msidry            #+#    #+#             */
/*   Updated: 2025/09/21 10:33:07 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/main.h"

void ll(void);


void sg_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		//rl_replace_line("", 0);
		rl_redisplay();
	}
}
int main(int argc, char *argv[], char *env[])
{
    char *input;
    int   error;
    t_env   *new_env;
    t_cmd   *commands;

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
        proreadline(&input, &error);
        lexer(&commands, &input, &new_env, &error);
        executor(&commands, &new_env, &error);
        print_commands(commands);
        cmd_clear(&commands);
        nullstr(&input);
    }
    env_handler(&new_env, NULL, DELETE);
    cmd_clear(&commands);
    //atexit(ll);
    return (0);
}


void ll(void)
{
    system("leaks -q minishell");
}