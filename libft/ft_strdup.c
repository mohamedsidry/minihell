/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 03:17:45 by msidry            #+#    #+#             */
/*   Updated: 2025/07/01 00:39:45 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	bytes;

	bytes = ft_strlen(str) + 1;
	ptr = malloc(sizeof(char) * bytes);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, str, ft_strlen(str) + 1);
	return (ptr);
}
