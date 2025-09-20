/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 02:48:18 by msidry            #+#    #+#             */
/*   Updated: 2024/10/30 03:17:04 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*cptr;
	size_t	bytes;
	size_t	i;

	bytes = count * size;
	ptr = malloc(bytes);
	if (!ptr)
		return (0);
	i = 0;
	cptr = (char *)ptr;
	while (i < bytes)
	{
		cptr[i] = 0;
		i++;
	}
	return (ptr);
}
