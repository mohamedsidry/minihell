/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiguous_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 22:37:59 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/04 22:38:05 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int	ambiguous_check(char *file)
{
	if (*file == '$' && (ft_isalnum(file[1]) || file[1] == '_'))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": ambiguous redirect\n", 2);
		return (1);
	}
	return (0);
}
