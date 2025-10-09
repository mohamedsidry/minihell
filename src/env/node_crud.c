/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_crud.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 20:52:41 by msidry            #+#    #+#             */
/*   Updated: 2025/10/09 12:57:17 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_env	*node_create(char *payload)
{
	t_env	*node;

	node = ft_calloc(sizeof(t_env), 1);
	if (!node)
		return (NULL);
	if (ft_strchr(payload, '='))
	{
		node->key = getprefix(payload, '=');
		node->e_value = getsuffix(payload, '=');
		node->x_value = ft_strdup(node->e_value);
	}
	else
	{
		node->key = ft_strdup(payload);
		node->e_value = NULL;
		node->x_value = NULL;
	}
	
	return (node);
}

void	node_delete(t_env *node)
{
	if (!node)
		return ;
	free(node->key);
	free(node->e_value);
	free(node->x_value);
	node->ishidden = 0;
	free(node);
}

t_env	*node_update(t_env *node, char *key, char *evalue, char *xvalue)
{
	if (!node)
		return (NULL);
	free(node->key);
	free(node->e_value);
	free(node->x_value);
	node->key = key;
	node->e_value = evalue;
	node->x_value = xvalue;
	node->ishidden = 0;
	return (node);
}

void	node_read(t_env *node)
{
	write(STDOUT_FILENO, node->key, ft_strlen(node->key));
	write(STDOUT_FILENO, "=", 1);
	write(STDOUT_FILENO, node->e_value, ft_strlen(node->e_value));
	write(STDOUT_FILENO, "\n", 1);
}
