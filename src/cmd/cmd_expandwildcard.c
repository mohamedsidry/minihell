/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expandwildcard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:15:28 by msidry            #+#    #+#             */
/*   Updated: 2025/10/05 13:58:47 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/main.h"
static char *star_handler(void);

t_cmd	*cmd_expandwildcard(t_cmd *cmd, void *reff)
{
	int		idx;
	char	*result;
	t_env	*env;
    int     *error;

    error = (int *)reff;
	idx = 0;
	env = (t_env *)reff;
	if (!cmd)
		return (cmd);
	while (cmd->args && cmd->args[idx])
	{
        if (!ft_strcmp(cmd->args[idx], "*"))
        {
            result = star_handler();
            if (!result)
                return (*error = 1, cmd);
            free(cmd->args[idx]);
            cmd->args[idx] = result;  
        }
		idx++;
	}
	return (cmd);
}

static char *star_handler(void)
{
    char *result;
    DIR *opdir;
    struct dirent *file;
    
    char *cwd;
    result = NULL;
    cwd = getcwd(NULL, 0);
    if (!cwd)
        return (NULL);
    opdir =  opendir(cwd);
    if (!opdir)
        return (free(cwd), NULL);
    while ((file = readdir(opdir)))
    {
        if (file->d_name[0] != '.')
            result = concat3(result, file->d_name, " ", 1);
    }
    closedir(opdir);
    nullstr(&cwd);
    return (result);
}
