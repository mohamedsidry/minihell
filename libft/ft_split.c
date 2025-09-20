/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:43:57 by msidry            #+#    #+#             */
/*   Updated: 2024/11/03 18:17:07 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	subpartscount(char const *str, char sep);
static size_t	nextpartend(char const *str, char sep);
static char		**freearray(char **arr, size_t currentindex);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		arr_index;
	size_t	partlen;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (subpartscount(s, c) + 1));
	if (!arr)
		return (NULL);
	arr_index = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			partlen = nextpartend(s, c);
			arr[arr_index] = ft_substr(s, 0, partlen);
			if (!arr[arr_index++])
				return (freearray(arr, arr_index));
			s += partlen;
		}
	}
	arr[arr_index] = NULL;
	return (arr);
}

static size_t	subpartscount(char const *str, char sep)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == sep)
			str++;
		else
		{
			count++;
			while (*str && *str != sep)
				str++;
		}
	}
	return (count);
}

static size_t	nextpartend(char const *str, char sep)
{
	size_t	bytes;

	bytes = 0;
	while (*str && *str != sep)
	{
		str++;
		bytes++;
	}
	return (bytes);
}

static char	**freearray(char **arr, size_t currentindex)
{
	size_t	i;

	i = 0;
	while (i < currentindex)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}
