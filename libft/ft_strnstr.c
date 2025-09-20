/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:54:52 by msidry            #+#    #+#             */
/*   Updated: 2024/10/29 23:47:09 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystak, const char *needle, size_t n)
{
	char	*hptr;
	char	*nptr;
	size_t	i;
	size_t	j;

	hptr = (char *)haystak;
	nptr = (char *)needle;
	i = 0;
	if (!ft_strlen(needle))
		return (hptr);
	while (hptr[i] && i < n)
	{
		j = 0;
		while (hptr[i + j] && hptr[i + j] == nptr[j] && j + i < n)
		{
			j++;
			if (!nptr[j])
				return (&hptr[i]);
		}
		i++;
	}
	return (0);
}
