#include "../../include/main.h"

char *ltrim(char *str, char *set, int usefree)
{
    char *result;
    size_t idx;

    idx = 0;
    if (!str || !set)
        return (str);
    while (str[idx])
    {
        if (!ft_strchr(set, str[idx]))
            break;
        idx++;
    }
    result = ft_strdup(&str[idx]);
    if (usefree)
        free(str);
    return (result);
}