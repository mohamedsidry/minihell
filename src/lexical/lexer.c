/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:20:54 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 14:37:13 by msidry           ###   ########.fr       */
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
    free2d(&tokens);
    cmd_iter(cmds, cmd_trim); // remove extra space in front of cmd .
    cmd_iter(cmds, cmd_builtin); // set is built in ;
    cmd_iter2(cmds, error, cmd_expandstatus); // find $1 and replace it with exit code of prev or '\0' if multi commands !
    cmd_iter2(cmds, *env, cmd_expandprev); // find $_ and replace it with prev program .
    cmd_iter2(cmds, *env, cmd_expandargs); // expand args !
    cmd_iter2(cmds, *env, cmd_expandredirection); // expand redirection ! 
    cmd_iter2(cmds, error, cmd_removequotes); //remove quotes;
    cmd_iter2(cmds, error, cmd_exandsplit); // spilt exported args like $a ="ls -la" become [ls , -la] 
    cmd_iter2(cmds, *env, cmd_findpaths);  // reserve the path cat became /bin/cat and so on !
}
