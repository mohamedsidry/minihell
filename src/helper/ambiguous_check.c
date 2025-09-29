/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiguous_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:52:03 by msidry            #+#    #+#             */
/*   Updated: 2025/09/28 13:08:07 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int ambiguous_check(char *file)
{
    if (*file == '$' && (ft_isalnum(file[1]) || file[1] == '_'))
    {
       ft_putstr_fd("minishell: ", 2);
        ft_putstr_fd(file, 2);
        ft_putstr_fd(": ambiguous redirect\n", 2); 
        return (1);
    }
    return (0);
}