/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 09:58:25 by msidry            #+#    #+#             */
/*   Updated: 2025/09/21 20:40:49 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void print_tokens(char **tokens)
{
    int idx;

    idx = 0;
    if (!tokens)
    {
        printf("No Tokens !\n");
        return ;
    }
    if (!(*tokens))
    {
        printf("Empty Tokens !\n");
        return ;
    }
    while (tokens[idx])
    {
        printf("TOKEN : %s\n", tokens[idx]);
        idx++;   /* code */
    }
}