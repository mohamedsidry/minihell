/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:54:39 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 10:12:59 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPDEF_H
# define TYPDEF_H

typedef struct s_env
{
	char			*key;
	char			*value;
	int				ishidden;
	struct s_env	*next;
}	t_env;

typedef enum e_action
{
	DELETE = 1,
	CREATE = 2,
	SYNC = 4,
}	t_action;

typedef struct s_cmd
{
	char			*fullcmd;
	char			**args;
	char			**symbols;
	char			**files;
	int				isbuiltin;
	int				pip[2];
	int				pipeline_fd[2];
	char			*exitcode;
	char			*prevcmd;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

typedef struct s_data
{
	t_cmd	*head;
	t_cmd	*current;
	int		prev_read;
}	t_data;

typedef enum e_pipends
{
	r_end = 1,
	w_end = 2,
	rw_end = 3,
}	t_pipends;

#endif