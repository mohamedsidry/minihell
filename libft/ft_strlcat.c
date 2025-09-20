/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:44:43 by msidry            #+#    #+#             */
/*   Updated: 2024/10/28 21:10:25 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	int		index;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dest);
	index = 0;
	if (dstsize == 0)
		return (srclen);
	if (dstlen >= dstsize)
		return (srclen + dstsize);
	while (src[index] && dstlen + index < dstsize - 1)
	{
		dest[dstlen + index] = src[index];
		index++;
	}
	dest[dstlen + index] = '\0';
	return (dstlen + srclen);
}
