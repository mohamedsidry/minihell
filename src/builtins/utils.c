/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:25:43 by azghibat          #+#    #+#             */
/*   Updated: 2025/09/25 18:37:17 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/main.h"

int	is_valid_export(char *key)
{
	size_t	i;

	if (!key || !key[0])
		return (0);
	if (key[0] >= '0' && key[0] <= '9')
		return (0);
	if (!((key[0] >= 'A' && key[0] <= 'Z')
			|| (key[0] >= 'a' && key[0] <= 'z')
			|| key[0] == '_'))
		return (0);
	i = 1;
	while (key[i])
	{
		if ((key[i] >= 0 && key[i] <= 31) || key[i] == 127)
			return (0);
		if (!((key[i] >= 'A' && key[i] <= 'Z')
				|| (key[i] >= 'a' && key[i] <= 'z')
				|| (key[i] >= '0' && key[i] <= '9')
				|| key[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

