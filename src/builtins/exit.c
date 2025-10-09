/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:10:47 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/08 22:28:58 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

long long	ft_atoll(const char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

static int	is_numeric(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	calculate_exit_code(char *str)
{
	long long	num;
	int			result;

	num = ft_atoll(str);
	result = num % 256;
	if (result < 0)
		result += 256;
	return (result);
}

void	close_theprogram(t_cmd *cmd, t_env **env, int *error)
{
	int		exit_code;
	t_cmd	*head;

	write(STDOUT_FILENO, "exit\n", 5);
	head = cmd_first(cmd);
	if (cmd->args[1] && cmd->args[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		*error = 1;
		return ;
	}
	if (!cmd->args[1])
		exit_code = *error;
	else if (!is_numeric(cmd->args[1]))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd->args[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit_code = 2;
	}
	else
		exit_code = calculate_exit_code(cmd->args[1]);
	env_handler(env, NULL, DELETE);
	cmd_clear(&head);
	exit(exit_code);
}
