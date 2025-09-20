/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:20:54 by msidry            #+#    #+#             */
/*   Updated: 2025/09/20 20:31:47 by msidry           ###   ########.fr       */
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
    if (valid_syntax(input, error)) // check or leading | or "&&", "||" .
        return ;
    tokenizer(&tokens, *input); // generate array of tokens .
    if (valid_syntax2(tokens, error)) // check after
        return free2d(&tokens);
    clean_tokens(tokens); // ">|", "&>", ">&" become ">" .
    if (valid_syntax3(tokens, error)) // validate next to sep .
        return free2d(&tokens);
    formater(cmds, tokens, error); // create commands struct and fill it !
    print_commands(*cmds);
    free2d(&tokens);
}
