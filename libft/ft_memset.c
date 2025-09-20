/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:39:36 by msidry            #+#    #+#             */
/*   Updated: 2024/10/28 00:50:29 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	bytes;
	char	*ptr;

	ptr = (char *)b;
	bytes = 0;
	while (bytes < len)
	{
		ptr[bytes++] = (unsigned char)c;
	}
	return (b);
}
