/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiguous_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 22:37:59 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/05 15:39:07 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"
static int wild_in_quotes(char *arg);

int	ambiguous_check(char *file)
{
	char *tmp;

	tmp = NULL;
	if (*file == '$' && (ft_isalnum(file[1]) || file[1] == '_'))
		return (ambiguous_error(tmp));
	else if (!ft_strcmp(file, "*"))
		return (ambiguous_error(tmp));
	else if (ft_strchr(file, '*') && !wild_in_quotes(file))
	{
		tmp = remove_quotes(&file, 0);
		if (!ft_strcmp(tmp, "*"))
		{
			ambiguous_error(file);
			free(tmp);
			return ( 1);	
		}
		free(tmp);
	}
	return (0);
}
static int wild_in_quotes(char *arg)
{
	int squotes;
	int dquotes;
	int quoted;

	squotes = 0;
	dquotes = 0;
	quoted = 0;
	if (!arg)
		return (0);
	while (*arg)
	{
		squotes += (*arg == '\'' && !(dquotes & 1));
		dquotes += (*arg == '"' && !(squotes & 1));
		quoted += (*arg == '*' && ((squotes & 1) || (dquotes & 1)));
		arg++;
	}
	return (quoted);
}