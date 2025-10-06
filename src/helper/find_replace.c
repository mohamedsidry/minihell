/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_replace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 09:36:57 by msidry            #+#    #+#             */
/*   Updated: 2025/09/23 11:25:30 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

char	*find_replace(char *src, char *target, char *new, int usefree)
{
	char	*ptr;
	char	*result;
	char	*tmp;

	result = NULL;
	if (!src)
		return (NULL);
	tmp = src;
	ptr = ft_strnstr(tmp, target, ft_strlen(tmp));
	if (!target || !*target || !new || !ptr)
		result = ft_strdup(tmp);
	else
	{
		while (ptr)
		{
			result = concat3(result, ft_substr(tmp, 0, ptr - tmp), NULL, 1 | 2);
			result = concat3(result, new, NULL, 1);
			tmp = ptr + ft_strlen(target);
			ptr = ft_strnstr(tmp, target, ft_strlen(tmp));
		}
		result = concat3(result, tmp, NULL, 1);
	}
	if (usefree & 1)
		free(src);
	return (result);
}
