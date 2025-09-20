/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:59:51 by msidry            #+#    #+#             */
/*   Updated: 2024/11/06 14:57:26 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	requiredbytes(long n);

char	*ft_itoa(int n)
{
	long	ln;
	size_t	bytes;
	char	*ptr;

	ln = n;
	bytes = requiredbytes(ln);
	ptr = malloc((bytes + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[bytes] = '\0';
	if (n < 0)
	{
		ptr[0] = '-';
		ln *= -1;
	}
	if (ln == 0)
		ptr[0] = '0';
	while (ln > 0)
	{
		ptr[--bytes] = ln % 10 + '0';
		ln /= 10;
	}
	return (ptr);
}

static size_t	requiredbytes(long ln)
{
	size_t	bytes;

	bytes = 0;
	if (ln <= 0)
	{
		ln *= -1;
		bytes++;
	}
	while (ln > 0)
	{
		bytes++;
		ln /= 10;
	}
	return (bytes);
}
