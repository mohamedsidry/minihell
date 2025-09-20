/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:53:54 by msidry            #+#    #+#             */
/*   Updated: 2025/09/20 20:32:17 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "typedef.h"

void    env_handler(t_env **myenv, char *env[], t_action action);
void    env_create(t_env **myenv, char *env[]);
void    env_delete(t_env **myenv);
t_env   *env_addback(t_env **myenv, t_env *node);
//t_env   *env_update(t_env *env, char *key, char *value, int state);
void    env_sync(t_env **env);
void    env_read(t_env *env);
t_env   *env_find(t_env *env, char *key);
size_t  env_size(t_env *env);
t_env   *env_last(t_env *env);
t_env   *node_create(char *payload);
void    node_delete(t_env *node);
t_env   *node_update(t_env *node, char *key, char *value, int state);
void    node_read(t_env *node);
char    *getprefix(char *str, int sep);
char    *getsuffix(char *str, int sep);
void    setvalue(t_env *env, char *key, char *value);
char    *getvalue(t_env *env, char *key);
char    **env_serializer(t_env *envlst);
t_env   *env_export(t_env **env, char *key, char *value);
void    env_unset(t_env **env, char *key);


// lexical tokenization

void    lexer(t_cmd **cmds, char **input, t_env **env, int *error);
int     valid_syntax(char **input, int *error);
void    tokenizer(char ***holderptr, char *input);
char    *handle_quotes(char *str);
char    *handle_in(char *str);
char    *handle_out(char *str);
char    *handle_amp(char *str);
char    *handle_txt(char *str);
char    *handle_pipe(char *str);
int     valid_syntax2(char **token, int *error);
int     valid_syntax3(char **tokens,int *error);
void    clean_tokens(char **tokens);
void    formater(t_cmd **cmds, char **tokens, int *error);
// command

t_cmd *cmd_addback(t_cmd **cmds, t_cmd *cmd);
void cmd_clear(t_cmd **cmds);
t_cmd *cmd_create(void);
void cmd_delete(t_cmd *command);
void cmd_read(t_cmd *command);
t_cmd *cmd_last(t_cmd **cmds);

// helpers 
void    proreadline(char **input, int *error);
char    *concat3(char *str1, char *str2, char *sep, int tofree);
char    *ltrim(char *str, char *set, int usefree);
int     is_space(int c);
int     ft_strcmp(char *str1, char *str2);
void    *ft_realloc(void *ptr, size_t size);
void    error_message(char *message);
int     syntax_error(char *token);
void    free2d(char ***arrptr);
int     is_redirection(char *token);
int     is_operator(char *token);
char    **serializer(t_list *list);
t_list  *dserializer(char **arr);
char    **append_array(char **arr, void *toadd);
#endif //UTILS_H