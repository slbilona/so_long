#include "so_long.h"

int ft_new_strchr(char *str, char c)
{
    int i;
    int compte;

    i = 0;
    compte = 0;
	while(str[i])
    {
        if(str[i++] == c)
            compte++;
    }
    return (compte);
}

int ft_new_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    return (i);
}