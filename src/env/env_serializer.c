/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_serializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 22:00:44 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/09 11:19:53 by msidry           ###   ########.fr       */
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
		if (!envlst->ishidden && envlst->e_value)
		{
			envarr[idx] = concat3(envlst->key, envlst->e_value, "=", 0);
			idx++;
		}
		envlst = envlst->next;
	}
	return (envarr);
}
