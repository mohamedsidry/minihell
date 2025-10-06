/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getsuffix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:13:10 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 22:36:15 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

char	*getsuffix(char *str, int sep)
{
	char	*target;
	char	*key;

	if (!str)
		return (NULL);
	target = ft_strchr(str, sep);
	if (!target)
		return (NULL);
	key = ft_substr(target + 1, 0, ft_strlen(target));
	return (key);
}
