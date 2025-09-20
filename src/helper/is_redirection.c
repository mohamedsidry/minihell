/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 10:56:22 by msidry            #+#    #+#             */
/*   Updated: 2025/09/20 18:57:12 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int is_redirection(char *token)
{
    if (!token)
        return (0);
    if (!ft_strncmp(token,"<<",3) || !ft_strncmp(token,">>",3))
        return (1);
    if (!ft_strncmp(token,">|",3))
        return (1);
    if (!ft_strncmp(token,"&>",3) || !ft_strncmp(token,">&",3))
        return (1);
    if (!ft_strncmp(token, ">", 2))
        return (1);
    if (!ft_strncmp(token, "<", 2))
        return (1);
    return (0);
}