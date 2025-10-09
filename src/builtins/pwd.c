/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:56:39 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/09 22:06:06 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

long long	ft_atoll(const char *str)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

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
