/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 09:58:25 by msidry            #+#    #+#             */
/*   Updated: 2025/10/05 16:15:35 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	print_tokens(char **tokens)
{
	int	idx;

	idx = 0;
	if (!tokens)
	{
		printf("No Tokens !\n");
		return ;
	}
	if (!(*tokens))
	{
		printf("Empty Tokens !\n");
		return ;
	}
	while (tokens[idx])
	{
		printf("TOKEN : %s\n", tokens[idx]);
		idx++;
	}
}
