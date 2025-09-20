/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:35:06 by msidry            #+#    #+#             */
/*   Updated: 2024/11/03 19:31:17 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	char	chr;

	chr = (char)c;
	while (*str && *str != chr)
		str++;
	if (*str == chr)
		return ((char *)str);
	return (0);
}
