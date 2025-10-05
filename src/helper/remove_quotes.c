/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:59:17 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/05 21:59:18 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void	remove_quotes_helper(char *buffer, char *str);

char	*remove_quotes(char **str, int usefree)
{
	char	*result;

	if (!str || !(*str))
		return (NULL);
	result = ft_calloc(ft_strlen(*str) + 1, sizeof(char));
	if (!result)
	{
		if (usefree)
			nullstr(str);
		return (NULL);
	}
	remove_quotes_helper(result, *str);
	if (usefree)
		nullstr(str);
	return (result);
}

static void	remove_quotes_helper(char *buffer, char *str)
{
	int		idx;
	char	quote_char;

	idx = 0;
	while (*str)
	{
		if (ft_strchr("'\"", *str) && ft_strchr(str + 1, *str))
		{
			quote_char = *str;
			str++;
			while (*str && *str != quote_char)
			{
				buffer[idx++] = *str;
				str++;
			}
			if (*str == quote_char)
				str++;
		}
		else
		{
			buffer[idx++] = *str;
			str++;
		}
	}
	buffer[idx] = '\0';
}
