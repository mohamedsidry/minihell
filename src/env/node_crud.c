/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_crud.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 20:52:41 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 22:36:24 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_env	*node_create(char *payload)
{
	t_env	*node;

	node = ft_calloc(sizeof(t_env), 1);
	if (!node)
		return (NULL);
	node->key = getprefix(payload, '=');
	node->value = getsuffix(payload, '=');
	return (node);
}

void	node_delete(t_env *node)
{
	if (!node)
		return ;
	free(node->key);
	free(node->value);
	free(node);
}

t_env	*node_update(t_env *node, char *key, char *value, int state)
{
	if (!node)
		return (NULL);
	free(node->key);
	free(node->value);
	node->key = key;
	node->value = value;
	node->ishidden = state;
	return (node);
}

void	node_read(t_env *node)
{
	if (!node)
	{
		printf("Empty node of env list !\n");
		return ;
	}
	printf("key    : %s\n", node->key);
	printf("value  : %s\n", node->value);
	if (node->ishidden)
		printf("hidden : %s\n", "true");
	else
		printf("hidden : %s\n", "false");
}
