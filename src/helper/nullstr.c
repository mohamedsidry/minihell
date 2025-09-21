#include "../../include/main.h"

void nullstr(char **ptr)
{
    if (!ptr)
        return ;
    free(*ptr);
    *ptr = NULL;
}