#include "../../include/main.h"


void stripquotes(char **str)
{
    char target;
    char tmp;
    int sqoutes;
    int dquotes;

    sqoutes = 0;

    if (!str || !(*str))
        return ;
    if (!ft_strchr(*str, '\'') && !ft_strchr(*str, '"'))
        return ;
    tmp = *str;

    while(tmp)
    {
        sqoutes += (*tmp == '\'' & !(dquotes & 1));
        sqoutes += (*tmp == '\'' & !(dquotes & 1));
        if (sqoutes & 1 && *tmp == '\'')
            target = '\''
        tmp++;
    }
}