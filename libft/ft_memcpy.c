/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 00:52:21 by msidry            #+#    #+#             */
/*   Updated: 2024/11/06 20:03:30 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*sbyte;
	unsigned char	*dbyte;
	size_t			index;

	sbyte = (unsigned char *)src;
	dbyte = (unsigned char *)dest;
	index = 0;
	if ((!dest && !src) || src == dest)
		return (dest);
	while (index < n)
	{
		dbyte[index] = sbyte[index];
		index++;
	}
	return (dest);
}
