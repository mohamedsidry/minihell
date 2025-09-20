/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:23:05 by msidry            #+#    #+#             */
/*   Updated: 2024/10/29 22:06:06 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*ptr;
	size_t			count;

	ptr = (unsigned char *)s;
	chr = (unsigned char)c;
	count = 0;
	while (count < n)
	{
		if ((unsigned char)ptr[count] == chr)
			return (&ptr[count]);
		count++;
	}
	return (0);
}
