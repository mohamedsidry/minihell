/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:04:15 by msidry            #+#    #+#             */
/*   Updated: 2024/10/28 00:48:57 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t bytes)
{
	unsigned char	*byte;
	size_t			i;

	i = 0;
	byte = (unsigned char *)s;
	if (bytes != 0)
	{
		while (i < bytes)
		{
			byte[i++] = 0;
		}
	}
}
