/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_serializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 09:44:15 by msidry            #+#    #+#             */
/*   Updated: 2025/09/28 18:43:40 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

char	**env_serializer(t_env *envlst)
{
	size_t	size;
	size_t	idx;
	char	**envarr;

	if (!envlst)
		return (NULL);
	size = env_size(envlst);
	idx = 0;
	envarr = ft_calloc(sizeof(char *), size + 1);
	if (!envarr)
		return (NULL);
	while (envlst)
	{
		if (!envlst->ishidden && envlst->value)
		{
			envarr[idx] = concat3(envlst->key, envlst->value, "=", 0);
			idx++;
		}
		envlst = envlst->next;
	}
	return (envarr);
}
