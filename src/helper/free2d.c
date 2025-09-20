/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 09:08:56 by msidry            #+#    #+#             */
/*   Updated: 2025/09/20 11:42:03 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void free2d(char ***arrptr)
{
    char **arr;
    int idx;

    idx = 0;
    if (!arrptr || !(*arrptr))
        return ;
    arr = *arrptr;
    while (arr[idx])
    {
        free(arr[idx]);
        idx++;
    }
    free(arr);
    *arrptr = NULL;
}