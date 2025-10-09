/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:56:28 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/09 22:06:11 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

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

static int	check_overflow(char *str)
{
	int		len;
	int		sign;
	char	*max;

	sign = 1;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		str++;
	}
	while (*str == '0')
		str++;
	len = ft_strlen(str);
	if (len > 19)
		return (1);
	if (len < 19)
		return (0);
	max = "9223372036854775807";
	if (sign == -1)
		max = "9223372036854775808";
	if (ft_strcmp(str, max) > 0)
		return (1);
	return (0);
}

static int	extract_exit_code(char *code)
{
	long long	num;
	int			error;

	if (!is_numeric(code))
		return (-1);
	if (check_overflow(code))
		return (255);
	num = ft_atoll(code);
	error = num % 256;
	if (error < 0)
		error += 256;
	return (error);
}

static void	exit_code_helper(t_cmd *cmd, int exit_code)
{
	if (exit_code == -1 || exit_code == 255)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd->args[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit_code = 255;
	}
}

void	close_theprogram(t_cmd *cmd, t_env **env, int *error)
{
	int		exit_code;
	t_cmd	*head;

	write(STDOUT_FILENO, "exit\n", 5);
	head = cmd_first(cmd);
	if (!is_numeric(cmd->args[1]) && is_numeric(cmd->args[2]))
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		exit_code = 255;
		exit(255);
	}
	else if (cmd->args[1] && cmd->args[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		*error = 1;
		return ;
	}
	exit_code = 0;
	if (cmd->args[1])
		exit_code = extract_exit_code(cmd->args[1]);
	exit_code_helper(cmd, exit_code);
	env_handler(env, NULL, NULL, DELETE);
	cmd_clear(&head);
	exit(exit_code);
}
