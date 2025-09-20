/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:28:39 by msidry            #+#    #+#             */
/*   Updated: 2025/09/19 11:33:45 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"


void *ft_realloc(void *ptr, size_t size)
{
    void *new;

    new = ft_calloc(size, 1);    
    if (!new)
        return (NULL);
    ft_memcpy(new, ptr, size);
    free(ptr);
    return (new);
}