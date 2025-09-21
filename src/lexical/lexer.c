/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:20:54 by msidry            #+#    #+#             */
/*   Updated: 2025/09/21 11:06:12 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"


void lexer(t_cmd **cmds, char **input, t_env **env, int *error)
{
    char **tokens;

    tokens = NULL;
    (void)env;
    if (!input || !(*input) || !cmds)
        return ;
    if (valid_syntax1(input, error)) // check or leading | or "&&", "||" .
        return ;
    tokenizer(&tokens, *input, error); // generate array of tokens + validate syntax2 .
    if (valid_syntax3(tokens, error)) // validate next to sep .
        return free2d(&tokens);
    formater(cmds, tokens, error); // create commands struct and fill it !
    cmd_iter(cmds, cmd_trim); // remove extra space in front of cmd .
    cmd_iter(cmds, cmd_builtin);
    free2d(&tokens);
}
