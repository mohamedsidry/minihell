/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_crud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:00:19 by msidry            #+#    #+#             */
/*   Updated: 2025/09/20 19:07:16 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"


t_cmd *cmd_create(void)
{
    t_cmd *command;
    command = ft_calloc(1, sizeof(t_cmd));
    if (!command)
        return (NULL);
    return (command);
}

void cmd_delete(t_cmd *command)
{
    if (!command)
        return ;
    //TODO: more data to be freed args, files ...
    free(command->fullcmd);
    free(command->separator);
    free2d(&command->args);
    free2d(&command->symbols);
    free2d(&command->files);
    free(command->heredoc_data);
    ft_bzero(command, sizeof(command));
    free(command);
}

void cmd_read(t_cmd *command)
{
    int idx;
    
    idx = -1;
    if (!command)
    {
        printf("No command !\n");
        return ;
    }
    printf("FULLCOMMAND : %s\n", command->fullcmd);
    
    if (!command->args || !command->args[0])
        printf("ARGS  : [null]\n");
    else
    {
        printf("ARGS : [");
        while (command->args[++idx])
        {
            printf(" %s", command->args[idx]);
            if (command->args[idx + 1])
                printf(",");
        }
        idx = -1;
        printf("]\n");
    }
    if (!command->symbols || !command->symbols[0])
        printf("SYMBOLS  : [null]\n");
    else
    {
        printf("SYMBOLS : [");
        while (command->symbols[++idx])
        {
            printf(" '%s'", command->symbols[idx]);
            if (command->symbols[idx + 1])
                printf(",");
        }
        idx = -1;
        printf("]\n");
    }
    if (!command->files|| !command->files[0])
        printf("SYMBOLS  : [null]\n");
    else
    {
        printf("FILES : [");
        while (command->files[++idx])
        {
            printf(" %s", command->files[idx]);
            if (command->files[idx + 1])
                printf(",");
        }
        idx = -1;
        printf("]\n");
    }
    printf("SEPARATOR : '%s'\n", command->separator);
}
