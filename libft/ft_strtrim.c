/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:47:54 by msidry            #+#    #+#             */
/*   Updated: 2024/11/06 12:13:47 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_contain(char const *set, char c);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (0);
	start = 0;
	while (s1[start] && ft_contain(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_contain(set, s1[end - 1]))
		end--;
	ptr = malloc(sizeof(char) * (end - start) + 1);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, &s1[start], end - start + 1);
	return (ptr);
}

static int	ft_contain(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
