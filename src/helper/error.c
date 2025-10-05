/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 19:09:48 by msidry            #+#    #+#             */
/*   Updated: 2025/10/05 16:29:26 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	error_message(char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
}

int	syntax_error(char *token)
{
	error_message("minishell: syntax error near unexpected token");
	error_message("`");
	error_message(token);
	error_message("'\n");
	return (1);
}

int	ambiguous_error(char *pattern)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(pattern, 2);
	ft_putstr_fd(": ambiguous redirect\n", 2);
	return (1);
}
