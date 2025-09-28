/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:54:39 by msidry            #+#    #+#             */
/*   Updated: 2025/09/28 02:43:17 by anasszgh         ###   ########.fr       */
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
    int pip[2];
    int pipeline_fd[2];
    char *exitcode;
    char *prevcmd;
    struct s_cmd *next;
} t_cmd;

typedef enum e_pipends
{
    r_end = 1,
    w_end = 2,
    rw_end = 3,
} t_pipends;

#endif //TYPDEF_H