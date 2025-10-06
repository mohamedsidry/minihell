/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getprefix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:05:27 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 22:36:00 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

char	*getprefix(char *str, int sep)
{
	char	*target;
	char	*key;

	if (!str)
		return (NULL);
	target = ft_strchr(str, sep);
	if (!target)
		return (NULL);
	key = ft_substr(str, 0, target - str);
	return (key);
}
