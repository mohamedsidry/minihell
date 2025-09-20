/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:08:26 by msidry            #+#    #+#             */
/*   Updated: 2024/10/29 22:53:51 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1ptr;
	unsigned char	*str2ptr;
	size_t			index;

	str1ptr = (unsigned char *)s1;
	str2ptr = (unsigned char *)s2;
	if (n == 0)
		return (0);
	index = 0;
	while (index < n && (str1ptr[index] == str2ptr[index]))
	{
		index++;
	}
	if (index == n)
		return (0);
	return ((unsigned char)str1ptr[index] - (unsigned char)str2ptr[index]);
}
