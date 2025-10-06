/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:28:39 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 22:40:19 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	new = ft_calloc(size, 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, ptr, size);
	free(ptr);
	return (new);
}
