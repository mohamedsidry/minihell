/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:20:54 by msidry            #+#    #+#             */
/*   Updated: 2025/10/05 16:18:34 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	lexer(t_cmd **cmds, char **input, t_env **env, int *error)
{
	char	**tokens;

	tokens = NULL;
	(void)env;
	if (!input || !(*input) || !cmds)
		return ;
	if (valid_syntax1(input, error))
		return ;
	tokenizer(&tokens, *input, error);
	if (valid_syntax3(tokens, error))
		return (free2d(&tokens));
	formater(cmds, tokens, error);
	free2d(&tokens);
	cmd_iter(cmds, cmd_trim);
	cmd_iter(cmds, cmd_builtin);
	cmd_iter2(cmds, error, cmd_expandstatus);
	cmd_iter2(cmds, *env, cmd_expandprev);
	cmd_iter2(cmds, *env, cmd_expandargs);
	cmd_iter2(cmds, error, cmd_expandwildcard);
	cmd_iter2(cmds, error, cmd_exandsplit);
	cmd_iter2(cmds, *env, cmd_expandredirection);
	cmd_iter2(cmds, error, cmd_removequotes);
	cmd_iter2(cmds, *env, cmd_findpaths);
}
