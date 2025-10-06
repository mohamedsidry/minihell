/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 09:08:56 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 22:38:52 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	free2d(char ***arrptr)
{
	char	**arr;
	int		idx;

	idx = 0;
	if (!arrptr || !(*arrptr))
		return ;
	arr = *arrptr;
	while (arr[idx])
	{
		free(arr[idx]);
		idx++;
	}
	free(arr);
	*arrptr = NULL;
}
