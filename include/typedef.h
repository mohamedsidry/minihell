/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 22:00:00 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/09 09:57:45 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef struct s_env
{
	char			*key;
	char			*e_value;
	char			*x_value;
	int				ishidden;
	struct s_env	*next;
}					t_env;

typedef enum e_action
{
	DELETE = 1,
	CREATE = 2,
	SYNC = 4,
}					t_action;

typedef struct s_cmd
{
	char			*fullcmd;
	char			**args;
	char			**symbols;
	char			**files;
	int				isbuiltin;
	int				herdoc_pip[2];
	int				pipeline_fd[2];
	char			*exitcode;
	char			*prevcmd;
	pid_t			pid;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

typedef enum e_pipends
{
	r_end = 1,
	w_end = 2,
	rw_end = 3,
}					t_pipends;

#endif