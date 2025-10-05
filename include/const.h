/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 10:27:25 by msidry            #+#    #+#             */
/*   Updated: 2025/10/05 20:35:18 by anasszgh         ###   ########.fr       */
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
