/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:54:39 by msidry            #+#    #+#             */
/*   Updated: 2025/09/20 12:50:36 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPDEF_H
# define TYPDEF_H


typedef struct s_env
{
    char *key;
    char *value;
    int ishidden;
    struct s_env *next;
} t_env;

typedef enum e_action
{
    DELETE = 1,
    CREATE = 2,
    SYNC = 4,
} t_action;


typedef struct s_cmd
{
    char *fullcmd;
    char **args;
    char *separator;
    char **files;
    char **symbols;
    int isbuiltin;
    char *heredoc_data;
    int exitcode;
    struct s_cmd *next;
} t_cmd;


#endif //TYPDEF_H