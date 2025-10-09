/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:57:05 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/09 18:55:44 by anasszgh         ###   ########.fr       */
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

static void	exec_builtin_child(t_cmd *cmd, t_env *env, int *error)
{
	t_cmd	*head;

	head = cmd_first(cmd);
	builtin_manager(cmd, &env, error);
	cmd_clear(&head);
	env_handler(&env, NULL, NULL, DELETE);
	exit(*error);
}

static void	exec_external(t_cmd *cmd, t_env *env)
{
	char	**env_array;
	char	*error_message;

	env_array = env_serializer(env);
	if (!env_array)
		env_array = ft_calloc(sizeof(char *), 1);
	execve(cmd->args[0], cmd->args, env_array);
	error_message = NULL;
	if (!ft_strchr(cmd->args[0], '/'))
		error_message = find_replace(CMDERR, "$CMD", cmd->args[0], 0);
	if (error_message)
		ft_putstr_fd(error_message, 2);
	else
		handle_error(cmd->args[0]);
	nullstr(&error_message);
}

static void	exec_command(t_cmd *cmd, t_env *env, int *error)
{
	t_cmd	*head;

	head = cmd_first(cmd);
	if (cmd->isbuiltin)
		exec_builtin_child(cmd, env, error);
	exec_external(cmd, env);
	cmd_clear(&head);
	env_handler(&env, NULL, NULL, DELETE);
	exit(127);
}

void	execute_child(t_cmd *cmd, t_env *env, int *err, int prev_fd)
{
	t_cmd	*head;

	head = cmd_first(cmd);
	setup_child_signals();
	setup_child_pipes(cmd, prev_fd);
	close_all_pipes(head);
	if (setup_redirection(cmd, err))
	{
		cmd_clear(&head);
		env_handler(&env, NULL, NULL, DELETE);
		exit(1);
	}
	if (!cmd->args)
	{
		cmd_clear(&head);
		env_handler(&env, NULL, NULL, DELETE);
		exit(0);
	}
	exec_command(cmd, env, err);
}
