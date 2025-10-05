/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:31:39 by msidry            #+#    #+#             */
/*   Updated: 2025/10/05 14:01:40 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static char	*getbranch(void);
static char	*get_file(char ***paths, char *git);
// static size_t get_terminal_width(void);

char	*prompt(t_env *env)
{
	char	*branch;
	char	*promptmessage;
	char	*cwd;

	promptmessage = find_replace(PROMPT, "$USER", getvalue(env, "USER"), 0);
	cwd = getcwd(NULL, 0);
	promptmessage = find_replace(promptmessage, "$CWD", cwd, 1);
	free(cwd);
	branch = getbranch();
	branch = find_replace(branch, "\n", "", 1);
	if (branch)
		promptmessage = find_replace(promptmessage, "$BRANCH", branch, 1);
	else
	{
		promptmessage = find_replace(promptmessage, "[$BRANCH]", "", 1);
		promptmessage = find_replace(promptmessage, ".git", "", 1);
	}
	free(branch);
	promptmessage = find_replace(promptmessage, getvalue(env, "HOME"), "~", 1);
	return (promptmessage);
}

static char	*getbranch(void)
{
	char	*cwd;
	char	**paths;
	char	*file;
	char	*buffer;
	int		fd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (NULL);
	paths = ft_split(cwd, '/');
	if (!paths || !*paths)
		return (free2d(&paths), free(cwd), NULL);
	file = get_file(&paths, "/.git/HEAD");
	if (!file)
		return (free(cwd), NULL);
	buffer = ft_calloc(256, 1);
	fd = open(file, O_RDONLY);
	if (fd != -1)
	{
		read(fd, buffer, 255);
		free(file);
		file = ft_strdup(ft_strrchr(buffer, '/') + 1);
		return (free(buffer), close(fd), free(cwd), file);
	}
	return (free(buffer), free(file), free(cwd), NULL);
}

static char	*get_file(char ***pathptr, char *git)
{
	char	**paths;
	int		idx;
	char	*res;
	char	*file;

	res = NULL;
	idx = 0;
	paths = *pathptr;
	while (paths[idx])
	{
		res = concat3(res, paths[idx], "/", 1);
		file = concat3(res, git, NULL, 0);
		if (access(file, F_OK | R_OK) == 0)
			return (free2d(pathptr), free(res), file);
		idx++;
		free(file);
	}
	free2d(pathptr);
	nullstr(&res);
	return (NULL);
}

// static size_t get_terminal_width(void) {
//     struct winsize w;
//     ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
//     return (w.ws_col);
// }