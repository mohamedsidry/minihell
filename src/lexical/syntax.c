/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:48:59 by msidry            #+#    #+#             */
/*   Updated: 2025/09/21 08:49:24 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static int	bonus_syntax(char *input);

int	valid_syntax1(char **input, int *error)
{
	char	*tmp;

	if (!input || !(*input))
		return (0);
	tmp = *input;
	if (tmp[0] == '|')
	{
		free(*input);
		*input = NULL;
		*error = 258;
		return (syntax_error("|"));
	}
	if (bonus_syntax(tmp))
	{
		free(*input);
		*input = NULL;
		*error = 258;
		return (1);
	}
	return (0);
}

int	valid_syntax2(char **token, int *error)
{
	size_t	idx;

	idx = 0;
	if (!token || !(*token))
		return (1);
	while (token[idx])
	{
		if (!ft_strncmp(token[idx], ">>", 3) || !ft_strncmp(token[idx], "<<", 3)
			|| !ft_strncmp(token[idx], ">", 2))
		{
			if (!token[idx + 1])
				return (*error = 258, syntax_error("newline"));
			else if (is_redirection(token[idx + 1]) || !ft_strncmp(token[idx
					+ 1], "|&", 3))
				return (*error = 258, syntax_error(token[idx + 1]));
		}
		idx++;
	}
	return (0);
}

int	valid_syntax3(char **tokens, int *error)
{
	int	idx;

	if (!tokens || !(*tokens))
		return (1);
	idx = 0;
	while (tokens[idx])
	{
		if (is_operator(tokens[idx]))
		{
			if (!tokens[idx + 1])
				return (*error = 258, syntax_error("newline"));
			if (is_operator(tokens[idx + 1]))
				return (*error = 258, syntax_error(tokens[idx + 1]));
		}
		idx++;
	}
	return (0);
}

static int	bonus_syntax(char *input)
{
	int	squotes;
	int	dquotes;

	squotes = 0;
	dquotes = 0;
	if (!input)
		return (0);
	while (*input)
	{
		squotes += (*input == '\'' && !(dquotes & 1));
		dquotes += (*input == '"' && !(squotes & 1));
		if (!(squotes & 1) && !(dquotes & 1))
		{
			if (!ft_strncmp(input, "&&", 2))
				return (syntax_error("&&"));
			else if (!ft_strncmp(input, "||", 2))
				return (syntax_error("||"));
			else if (!ft_strncmp(input, ";;", 2))
				return (syntax_error(";;"));
			else if (!ft_strncmp(input, ";;", 1))
				return (syntax_error(";"));
		}
		input++;
	}
	return (0);
}
