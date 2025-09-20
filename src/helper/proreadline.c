/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proreadline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:53:24 by msidry            #+#    #+#             */
/*   Updated: 2025/09/20 19:29:37 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static int balanced_quotes(char *input);
static char *backup_readline(char *input);

void proreadline(char **input, int *error)
{

    *input = readline("minishell $> ");
    if (!(*input))
    {
        printf("\nExit\n");
        exit(0);
    }
    if (balanced_quotes(*input))
        *input = backup_readline(*input);
    else
    {
        *input = ltrim(*input, " \n", 1);
        add_history(*input);            
    }
    if (!(*input))
    {
        error_message(" minishell: syntax error: unexpected end of file\n");
        *error = 258;
    }
    if (*input && !(*input[0]))
    {
        free(*input);
        *input = NULL;
    }
}

static int balanced_quotes(char *input)
{
    int sqoutes;
    int dquotes;

    sqoutes = 0;
    dquotes = 0;
    
    while (*input)
    {
        sqoutes += (*input == '\'' && !(dquotes & 1));
        dquotes += (*input == '"' && !(sqoutes & 1));
        input++;
    }
    return ((sqoutes & 1) || (dquotes & 1));
}

static char *backup_readline(char *input)
{
    char *newread;

    while (balanced_quotes(input))
    {
        newread = readline("> ");
        if (!newread)
        {
            if (balanced_quotes(input))
                error_message(" minishell: unexpected EOF while looking for matching `''\n");
            free (input);
            add_history(input);
            return (NULL);
        }
        input = concat3(input, newread, "\n", 1 | 2);
    }
    newread = ltrim(input, "\t\n\v ", 1);
    add_history(newread);
    return (newread);
}



// static int pre_pipe(char *input)
// {
//     char *tmp;

//     tmp = ft_strrchr(input, '|');
//     while (tmp && tmp <= input)
//     {
//         tmp--;
//         if (*tmp == '>')
//             return (1);
//         else if (is_space(*tmp))
//             continue ;
//         else
//             return (1);
//     }
//     return (1);
// }