/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exandsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 07:26:02 by msidry            #+#    #+#             */
/*   Updated: 2025/09/25 09:18:04 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"
static size_t	subpartscount(char const *str, char *set);
static size_t	nextpartend(char const *str, char *set);
char            **args_split(char **args, int userfree);
static  char	**set_split(char const *str, char *set);

t_cmd   *cmd_exandsplit(t_cmd *cmd, void *reff)
{
    int *err;
    t_cmd *tmp;
    
    if (!cmd || !cmd->args)
        return (cmd);
    err = (void *)reff;
    tmp = cmd;
    while (tmp)
    {
        if (tmp->args)
            tmp->args = args_split(tmp->args, 1);    
        tmp = tmp->next;
    }
    return (cmd);
}


char **args_split(char **args, int usefree)
{
    char **result;
    int idx;
    int jdx;
    t_list *list;

    result = NULL;
    idx = 0;
    list = NULL;
    while (args[idx])
    {
        result = set_split(args[idx], "\t\v \n");
        jdx = -1;
        while (result && result[++jdx])
            ft_lstadd_back(&list, ft_lstnew(ft_strdup(result[jdx])));
        free2d(&result);
        idx++;
    }
    result = serializer(list);
    ft_lstclear(&list, free);
    if (usefree)
        free2d(&args);
    return (result);
}




static char	**set_split(char const *str, char *set)
{
	char	**arr;
	int		arr_index;
	size_t	partlen;

	if (!str)
		return (NULL);
	arr = malloc(sizeof(char *) * (subpartscount(str, set) + 1));
	if (!arr)
		return (NULL);
	arr_index = 0;
	while (*str)
	{
		if (ft_strchr(set, *str))
			str++;
		else
		{
			partlen = nextpartend(str, set);
			arr[arr_index] = ft_substr(str, 0, partlen);
			if (!arr[arr_index++])
				return (free2d(&arr), NULL);
			str += partlen;
		}
	}
	arr[arr_index] = NULL;
	return (arr);
}

static size_t	subpartscount(char const *str, char *set)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (ft_strchr(set, *str))
			str++;
		else
		{
			count++;
			while (*str && !ft_strchr(set, *str))
				str++;
		}
	}
	return (count);
}

static size_t	nextpartend(char const *str, char *set)
{
	size_t	bytes;

	bytes = 0;
	while (*str && !ft_strchr(set, *str))
	{
		str++;
		bytes++;
	}
	return (bytes);
}
