/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 20:40:48 by msidry            #+#    #+#             */
/*   Updated: 2025/10/09 12:49:05 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	env_handler(t_env **myenv, char *argv[], char *env[], t_action action)
{
	if (action & CREATE)
		env_create(myenv, env);
	if (action & SYNC)
		env_sync(myenv, argv);
	if (action & DELETE)
		env_delete(myenv);
}
