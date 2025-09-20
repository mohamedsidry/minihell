/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 11:07:16 by msidry            #+#    #+#             */
/*   Updated: 2025/09/20 11:18:38 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int is_operator(char *token)
{
    if (!token)
        return (0);
    if (!ft_strncmp(token,"<<",3) || !ft_strncmp(token,">>",3))
        return (1);
    if (!ft_strncmp(token,">",2))
        return (1);
    if (!ft_strncmp(token, "<", 2))
        return (1);
    if (!ft_strncmp(token, "|", 2))
        return (1);
    if (!ft_strncmp(token, "&", 2))
        return (1);
    return (0);
}