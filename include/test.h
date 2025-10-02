#ifndef TEST_H

# define TEST_H

void    print_commands(t_cmd *cmds);
char    *find_replace(char *src, char *target, char *new, int usefree);
void    exec_chain2(t_cmd **cmds, t_env **env, int *err);

#endif // TEST_H