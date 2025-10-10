/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 22:00:05 by azghibat          #+#    #+#             */
/*   Updated: 2025/10/09 22:05:43 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "typedef.h"

void		env_handler(t_env **myenv, char *av[], char *ev[], t_action act);
void		env_create(t_env **myenv, char *env[]);
void		env_delete(t_env **myenv);
t_env		*env_addback(t_env **myenv, t_env *node);
void		env_sync(t_env **env, char *argv[]);
void		env_read(t_env *env);
t_env		*env_find(t_env *env, char *key);
size_t		env_size(t_env *env);
t_env		*env_last(t_env *env);
t_env		*env_update(t_env **myenv, char *payload);
t_env		*node_create(char *payload);
void		node_delete(t_env *node);
t_env		*node_update(t_env *node, char *key, char *eval, char *xval);
void		node_read(t_env *node);
char		*getprefix(char *str, int sep);
char		*getsuffix(char *str, int sep);
void		setvalue(t_env *env, char *key, char *value);
char		*getvalue(t_env *env, char *key);
char		**env_serializer(t_env *envlst);
t_env		*env_export(t_env **env, char *keyvalue);
void		env_unset(t_env **env, char *key);
void		lexer(t_cmd **cmds, char **input, t_env **env, int *error);
int			valid_syntax1(char **input, int *error);
int			valid_syntax2(char **token, int *error);
int			valid_syntax3(char **tokens, int *error);
void		tokenizer(char ***holderptr, char *input, int *error);
char		*handle_quotes(char *str);
char		*handle_in(char *str);
char		*handle_out(char *str);
char		*handle_amp(char *str);
char		*handle_txt(char *str);
char		*handle_pipe(char *str);
void		clean_tokens(char **tokens);
void		formater(t_cmd **cmds, char **tokens, int *error);

t_cmd		*cmd_addback(t_cmd **cmds, t_cmd *cmd);
void		cmd_clear(t_cmd **cmds);
t_cmd		*cmd_create(void);
void		cmd_delete(t_cmd *command);
t_cmd		*cmd_last(t_cmd **cmds);
t_cmd		*cmd_first(t_cmd *cmds);
size_t		cmd_length(t_cmd *cmds);
void		cmd_iter(t_cmd **cmds, t_cmd *(func)(t_cmd *cmd));
t_cmd		*cmd_trim(t_cmd *cmd);
t_cmd		*cmd_builtin(t_cmd *cmd);
void		cmd_iter2(t_cmd **cmds, void *ref, t_cmd *(func)(t_cmd *cmd,
					void *rf));
t_cmd		*cmd_expandargs(t_cmd *cmd, void *reff);
t_cmd		*cmd_expandstatus(t_cmd *cmd, void *reff);
t_cmd		*cmd_expandprev(t_cmd *cmd, void *reff);
t_cmd		*cmd_expandredirection(t_cmd *cmd, void *reff);
t_cmd		*cmd_removequotes(t_cmd *cmd, void *reff);
t_cmd		*cmd_exandsplit(t_cmd *cmd, void *reff);
t_cmd		*cmd_findpaths(t_cmd *cmd, void *reff);
t_cmd		*cmd_expandwildcard(t_cmd *cmd, void *reff);

void		proreadline(char **input, t_env **env, int *error);
char		*prompt(t_env *env);
char		*concat3(char *str1, char *str2, char *sep, int tofree);
char		*ltrim(char *str, char *set, int usefree);
int			is_space(int c);
int			ft_strcmp(char *str1, char *str2);
void		*ft_realloc(void *ptr, size_t size);
void		error_message(char *message);
int			syntax_error(char *token);
void		free2d(char ***arrptr);
int			is_redirection(char *token);
int			is_operator(char *token);
char		**serializer(t_list *list);
t_list		*dserializer(char **arr);
char		**append_array(char **arr, void *toadd);
int			is_builtin(char *cmd);
void		nullstr(char **ptr);
char		*remove_quotes(char **str, int usefree);
int			is_expandable(char *str);
int			close_pipe(int pipefds[2], t_pipends ends);
int			open_pipe(int pipefds[2]);
int			has_redirections(t_cmd *cmd);
int			ambiguous_check(char *file);
void		heredoc_manager(t_cmd *cmds, t_env *env, int *err);
void		herdoc_loop(t_cmd *cmd, t_env *env, char *limiter, int toexpand);
char		*expand_handler(char *str, t_env *env, t_cmd *cmd);
char		*find_replace(char *src, char *target, char *new, int usefree);
void		builtin_manager(t_cmd *cmd, t_env **env, int *error);
void		run_unset(t_cmd *cmd, t_env **env, int *error);
void		run_pwd(int *error);
void		run_export(t_cmd *cmd, t_env **env, int *error);
void		run_env(t_cmd *cmd, t_env **env, int *error);
void		run_echo(t_cmd *cmd, int *error);
void		run_cd(t_cmd *cmd, t_env **env, int *error);
void		close_theprogram(t_cmd *cmd, t_env **env, int *error);
int			ambiguous_error(char *pattern);
void		executor(t_cmd **cmds, t_env **env, int *error);
void		exec_builtin(t_cmd **cmds, t_env **env, int *error);
void		exec_chain(t_cmd *cmds, t_env **env, int *error);
void		close_pipe_fds(t_cmd *cmd);
void		close_all_pipes(t_cmd *cmds);
void		setup_input_pipe(int prev_pipe_read);
void		setup_output_pipe(t_cmd *cmd);
void		setup_child_pipes(t_cmd *cmd, int prev_read);
void		handle_parent_pipes(t_cmd *cmd, int *prev_read);
void		execute_child(t_cmd *cmd, t_env *env, int *err, int prev_fd);
int			setup_redirection(t_cmd *cmd, int *error);
int			save_fds(int *saved_fds);
void		restore_fds(int *saved_fds);
int			handle_error(char *file);

void		sg_handler(int sig_num);
void		sig_handler(int sig);
void		setup_child_signals(void);
void		setup_parent_exec_signals(void);
void		setup_interactive_signals(void);
long long	ft_atoll(const char *str);

#endif