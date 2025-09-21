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
static void backup_readline(char **input);

void proreadline(char **input, int *error)
{
    char *tmp;

    tmp = NULL;
    nullstr(input);
    *input = readline("minishell $> ");
    if (!(*input))
    {
        printf("\nExit\n");
        exit(0);
    }
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

static void backup_readline(char **input)
{
    char *tmp;
    tmp = NULL;
    while (balanced_quotes(*input))
    {
        tmp = readline("> ");
        if (!tmp)
        {
            if (balanced_quotes(*input))
                error_message(" minishell: unexpected EOF while looking for matching `''\n");
            add_history(*input);
            return ;
        }
        *input = concat3(*input, tmp, "\n", 1 | 2);
    }
    tmp = ltrim(*input, "\t\n\v ", 0);
    nullstr(input);
    *input = tmp;
    add_history(*input);
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