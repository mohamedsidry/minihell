/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 02:47:46 by anasszgh          #+#    #+#             */
/*   Updated: 2025/10/04 12:25:44 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static int	handle_error(char *file)
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
	char *error_message;
	t_cmd *head;

	error_message = NULL;
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
	if (!ft_strchr("./", cmd->args[0][0]))
		error_message = find_replace(CMDERR, "$CMD", cmd->args[0], 0);
	if (!ft_strchr("./", cmd->args[0][0]))
		ft_putstr_fd(error_message, 2);
	else
		handle_error(cmd->args[0]);
	cmd_clear(&head);
	env_handler(&env, NULL, DELETE);
	nullstr(&error_message);
	exit(127);
}

void	execute_child(t_cmd *cmd, t_env *env, int *err, int prev_fd)
{
	t_cmd *head;

	head = cmd_first(cmd);
	setup_child_pipes(cmd, prev_fd);
	close_all_pipes(head);
	if (setup_redirection(cmd, err))
	{
		cmd_clear(&head);
		env_handler(&env, NULL, DELETE);
		exit(1);
	}
	exec_command(cmd, env, err);
}

