/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:23:01 by azghibat          #+#    #+#             */
/*   Updated: 2025/09/28 18:32:22 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/main.h"

static int	is_valid_unset(char *key)
{
	size_t	i;

	if (!key || !key[0])
		return (0);
	if ((key[0] >= '0' && key[0] <= '9')
		|| !((key[0] >= 'A' && key[0] <= 'Z')
			|| (key[0] >= 'a' && key[0] <= 'z')
			|| key[0] == '_'))
		return (0);
	i = 1;
	while (key[i])
	{
		if ((key[i] >= 0 && key[i] <= 31) || key[i] == 127)
			return (0);
		if (!((key[i] >= 'A' && key[i] <= 'Z')
				|| (key[i] >= 'a' && key[i] <= 'z')
				|| (key[i] >= '0' && key[i] <= '9')
				|| key[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

void	run_unset(t_cmd *cmd, t_env **env, int *error)
{
	int	i;
	int	has_error;

	*error = 0;
	if (!cmd || !env)
		return ;
	i = 1;
	has_error = 0;
	while (cmd->args[i])
	{
		if (is_valid_unset(cmd->args[i]))
			env_unset(env, cmd->args[i]);
		else
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(cmd->args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			has_error = 1;
		}
		i++;
	}
	*error = has_error;
}
