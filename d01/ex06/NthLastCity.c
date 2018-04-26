#include "header.h"
#include <stdio.h>
#include <stdlib.h>

char *NthLastCity(struct s_city *city, int n)
{
    struct s_city   *p1;
    struct s_city   *p2;

    p1 = p2 = city;
    for (int i = 0; i < n + 1; i++){
        if (!p1)
            return ("Error");
        p1 = p1->next;
    }
    while (p1)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    if (!p2 || !p2->name)
        return (0);
    return p2->name;
}