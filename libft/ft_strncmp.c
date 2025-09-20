/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:50:08 by msidry            #+#    #+#             */
/*   Updated: 2024/10/29 16:12:45 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char*str1, const char *str2, size_t n)
{
	size_t	bytes;

	bytes = 0;
	while (*str2 && (*str1 == *str2) && (bytes < n))
	{
		str1++;
		str2++;
		bytes++;
	}
	if (bytes == n)
		return (0);
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
