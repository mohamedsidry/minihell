/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:56:39 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/05 21:56:40 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	run_pwd(int *error)
{
	char	*tmp;

	*error = 0;
	tmp = getcwd(NULL, 0);
	if (!tmp)
	{
		perror("minishell: pwd");
		*error = 1;
		return ;
	}
	write(STDOUT_FILENO, tmp, ft_strlen(tmp));
	write(STDOUT_FILENO, "\n", 1);
	free(tmp);
}
