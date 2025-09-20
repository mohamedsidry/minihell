/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:28:03 by msidry            #+#    #+#             */
/*   Updated: 2024/11/06 20:26:50 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dptr;
	unsigned char	*sptr;

	sptr = (unsigned char *)src;
	dptr = (unsigned char *)dest;
	if (!dest && !src)
		return (dest);
	if (dptr > sptr)
	{
		while (len)
		{
			len--;
			dptr[len] = sptr[len];
		}
	}
	else
	{
		ft_memcpy(dest, src, len);
	}
	return (dest);
}
