/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proreadline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:59:08 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/10 10:54:48 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static int	balanced_quotes(char *input);
static void	backup_readline(char **input);
static char	*promptreadline(t_env **env);

void	proreadline(char **input, t_env **env, int *error)
{
	char	*tmp;

	tmp = NULL;
	nullstr(input);
	*input = promptreadline(env);
	if (balanced_quotes(*input))
		backup_readline(input);
	else
	{
		tmp = *input;
		*input = ltrim(*input, " \n", 0);
		free(tmp);
		add_history(*input);
	}
	if (!(*input))
	{
		error_message("minishell: syntax error: unexpected end of file\n");
		*error = 258;
	}
	if (*input && !(*input[0]))
		nullstr(input);
}

static char	*promptreadline(t_env **env)
{
	char		*promptmessage;
	char		*input;
	int			signal_recei;

	promptmessage = prompt(*env);
	signal_recei = 0;
	input = readline(promptmessage);
	free(promptmessage);
	if (!input && signal_recei == SIGINT)
	{
		signal_recei = 0;
		return (ft_strdup(""));
	}
	if (!input)
	{
		printf("Exit");
		env_handler(env, NULL, NULL, DELETE);
		exit(0);
	}
	return (input);
}

static int	balanced_quotes(char *input)
{
	int	squotes;
	int	dquotes;

	squotes = 0;
	dquotes = 0;
	while (*input)
	{
		squotes += (*input == '\'' && !(dquotes & 1));
		dquotes += (*input == '"' && !(squotes & 1));
		input++;
	}
	return ((squotes & 1) || (dquotes & 1));
}

static void	backup_readline(char **input)
{
	char		*tmp;

	tmp = NULL;
	while (balanced_quotes(*input))
	{
		tmp = readline("> ");
		if (!tmp)
			return (nullstr(input));
		if (!tmp)
		{
			if (balanced_quotes(*input))
				error_message(QERROR);
			add_history(*input);
			return ;
		}
		*input = concat3(*input, tmp, "\n", 1 | 2);
	}
	tmp = ltrim(*input, "\t\n\v ", 1);
	*input = tmp;
	add_history(*input);
}
