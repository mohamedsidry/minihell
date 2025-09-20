/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getprefix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:05:27 by msidry            #+#    #+#             */
/*   Updated: 2025/09/18 20:59:11 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"



char *getprefix(char *str, int sep)
{
    char *target;
    char *key;

    if (!str)
        return (NULL);
    target = ft_strchr(str, sep);
    if (!target)
        return (NULL);
    key = ft_substr(str, 0, target - str);
    return (key);
}