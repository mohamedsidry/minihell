/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_expandable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:10:22 by msidry            #+#    #+#             */
/*   Updated: 2025/09/21 13:20:06 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int is_expandable(char *str)
{
    int squotes;
    int dquotes;

    squotes = 0;
    dquotes = 0;
    if (!str)
        return (0);
    while (*str)
    {
        squotes += (*str == '\'' && !(dquotes & 1));
        dquotes += (*str == '"' && !(squotes & 1));
        if (!(squotes & 1))
        {
            if (*str == '$')
                return (1);
        }
        str++;
    }
    return (0);
}
