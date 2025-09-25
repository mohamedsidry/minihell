/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:10:47 by azghibat          #+#    #+#             */
/*   Updated: 2025/09/25 15:11:31 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void extracter_helper(char *code, int num);
static int extract_error_number(char *code);

static void extracter_helper(char *code, int num)
{
    while (code[num])
    {
        if (code[num] < '0' || code[num] > '9')
        {
            ft_putstr_fd("Minishell: exit: numeric argument required\n", 2);
            exit(255);
        }
        num++;
    }
}

static int extract_error_number(char *code)
{
    int         error;
    long long   num;

    if (!code)
        return (-1);
    num = 0;
    if (code[0] == '-' || code[0] == '+')
        num++;
    extracter_helper(code, num);
    error = 0;
    num = ft_atoi(code);
    if (num > 255)
        error = num % 256;
    else if (num < 0)
        error = 256 + (num % 256);
    else
        error = num;
    return (error);
}

void close_theprogram(t_cmd *cmd, t_env **env)
{
    int tmp;
    
    if (!cmd)
        exit(0);
    
    if (cmd->args[1] && cmd->args[2])
    {
        ft_putstr_fd("Minishell: exit: too many arguments\n", 2);
        cmd->exitcode = "1";
        return;
    }
    if (!cmd->args[1])
        tmp = 0;
    else
        tmp = extract_error_number(cmd->args[1]);
    if (tmp < 0)
    {
        if (cmd->exitcode)
            tmp = ft_atoi(cmd->exitcode);
        else
            tmp = 0;
    }
    node_delete(*env);
    cmd_delete(cmd);
    printf("exit\n");
    exit(tmp);
}