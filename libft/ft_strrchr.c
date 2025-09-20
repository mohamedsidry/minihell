/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:13:16 by msidry            #+#    #+#             */
/*   Updated: 2024/10/28 23:49:19 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t			len;
	unsigned char	chr;
	char			*ptr;

	len = ft_strlen(str);
	chr = (char)c;
	ptr = (char *)str;
	while (len > 0 && ptr[len] != chr)
		len--;
	if (ptr[len] == chr)
		return (&ptr[len]);
	return (0);
}
