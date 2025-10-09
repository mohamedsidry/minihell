/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 02:47:46 by anasszgh          #+#    #+#             */
/*   Updated: 2025/10/08 22:32:18 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int	handle_error(char *file)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	perror("");
	return (1);
}

static void	exec_command(t_cmd *cmd, t_env *env, int *error)
{
	char	**env_array;
	char	*error_message;
	t_cmd	*head;

	head = cmd_first(cmd);
	if (cmd->isbuiltin)
	{
		builtin_manager(cmd, &env, error);
		cmd_clear(&head);
		env_handler(&env, NULL, DELETE);
		exit(*error);
	}
	env_array = env_serializer(env);
	execve(cmd->args[0], cmd->args, env_array);
	error_message = NULL;
	if (!ft_strchr("./", cmd->args[0][0]))
		error_message = find_replace(CMDERR, "$CMD", cmd->args[0], 0);
	if (error_message)
		ft_putstr_fd(error_message, 2);
	else
		handle_error(cmd->args[0]);
	free_array(env_array);
	nullstr(&error_message);
	cmd_clear(&head);
	env_handler(&env, NULL, DELETE);
	exit(127);
}

static int	handle_child_redirection(t_cmd *cmd, int *err, t_cmd **head, t_env **env)
{
	if (setup_redirection(cmd, err))
	{
		cmd_clear(head);
		env_handler(env, NULL, DELETE);
		return (1);
	}
	return (0);
}

void	execute_child(t_cmd *cmd, t_env *env, int *err, int prev_fd)
{
	t_cmd	*head;

	head = cmd_first(cmd);
	setup_child_signals();
	setup_child_pipes(cmd, prev_fd);
	close_all_pipes(head);
	if (handle_child_redirection(cmd, err, &head, &env))
		exit(1);
	if (!cmd->args)
	{
		cmd_clear(&head);
		env_handler(&env, NULL, DELETE);
		exit(0);
	}
	exec_command(cmd, env, err);
}
