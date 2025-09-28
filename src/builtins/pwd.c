/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:19:08 by azghibat          #+#    #+#             */
/*   Updated: 2025/09/28 18:29:53 by anasszgh         ###   ########.fr       */
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
