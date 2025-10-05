/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 19:30:06 by msidry            #+#    #+#             */
/*   Updated: 2025/10/05 16:22:16 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static char	*extract_token(char *str);

void	tokenizer(char ***container, char *input, int *error)
{
	t_list	*lst_tokens;
	char	*token;
	int		idx;

	idx = 0;
	lst_tokens = NULL;
	while (input[idx])
	{
		while (is_space(input[idx]))
			idx++;
		token = extract_token(&input[idx]);
		if (!token || !(*token))
		{
			free(token);
			break ;
		}
		ft_lstadd_back(&lst_tokens, ft_lstnew(token));
		idx += ft_strlen(token);
	}
	*container = serializer(lst_tokens);
	ft_lstclear(&lst_tokens, free);
	if (valid_syntax2(*container, error))
		return (free2d(container));
	clean_tokens(*container);
}

static char	*extract_token(char *str)
{
	char	*token;

	token = NULL;
	if (*str == '\'' || *str == '"')
		token = handle_quotes(str);
	else if (*str == '<')
		token = handle_in(str);
	else if (*str == '>')
		token = handle_out(str);
	else if (*str == '&')
		token = handle_amp(str);
	else if (*str == '|')
		token = handle_pipe(str);
	else
		token = handle_txt(str);
	return (token);
}

void	clean_tokens(char **tokens)
{
	int	idx;

	idx = 0;
	if (!tokens)
		return ;
	while (tokens[idx])
	{
		if (!ft_strncmp(tokens[idx], ">|", 3) || !ft_strncmp(tokens[idx], "&>",
				3) || !ft_strncmp(tokens[idx], ">&", 3))
		{
			free(tokens[idx]);
			tokens[idx] = ft_strdup(">");
		}
		else if (!ft_strncmp(tokens[idx], "<&", 3))
		{
			free(tokens[idx]);
			tokens[idx] = ft_strdup("<");
		}
		else if (!ft_strncmp(tokens[idx], "|&", 3))
		{
			free(tokens[idx]);
			tokens[idx] = ft_strdup("|");
		}
		idx++;
	}
}

char	*handle_pipe(char *str)
{
	if (*(str + 1) == '&')
		return (ft_substr(str, 0, 2));
	return (ft_substr(str, 0, 1));
}
