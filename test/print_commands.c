#include "../include/main.h"

void print_commands(t_cmd *cmd)
{
    while (cmd)
    {
        cmd_read(cmd);
        cmd = cmd->next;
    }
}