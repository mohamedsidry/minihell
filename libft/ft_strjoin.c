/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:33:00 by msidry            #+#    #+#             */
/*   Updated: 2024/11/06 19:54:48 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1len;
	size_t	s2len;	

	if (s1 == NULL || s2 == NULL)
	{
		ptr = malloc(sizeof(char));
		if (!ptr)
			return (0);
		ptr[0] = '\0';
		return (ptr);
	}
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1, s1len + 1);
	ft_strlcpy(&ptr[s1len], s2, s2len + 1);
	return (ptr);
}
