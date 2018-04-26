#include "header.h"
#include <stdio.h>
#include <unistd.h>

void    print(struct s_node *lst, int i)
{
    if (!lst)
        return ;
    print(lst->next, i + 1);
    printf("%s", lst->word);
    if (i != 0)
        printf(" ");
    else
        printf("\n");
}

void printReverse(struct s_node *lst)
{
    print(lst, 0);
}
