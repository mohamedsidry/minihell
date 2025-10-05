/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:59:52 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/05 21:59:53 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H

# define CONST_H

# define PROMPT \
	"\033[1;33m$USER@host:\033[0m\033[0;34m$CWD\033[0m \
\033[0;35m.git\033[0;31m[$BRANCH]\033[0m $ "
# define CMDERR "minishell : $CMD: command not found\n"
# define QERROR " minishell: unexpected EOF while looking for matching `''\n"
#endif // CONST_H
