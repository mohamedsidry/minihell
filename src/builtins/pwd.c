/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:19:08 by azghibat          #+#    #+#             */
/*   Updated: 2025/09/25 13:32:31 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void    run_pwd()
{
	char    *tmp;
	
	tmp = getcwd(NULL, 0);
	if (tmp)
		printf("%s\n", tmp);
	else
		perror("Minishell: pwd");
	if (tmp)
		free(tmp);
}
