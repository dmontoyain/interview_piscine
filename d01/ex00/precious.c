#include "header.h"
#include <stdlib.h>
#include <unistd.h>

struct s_node *create_doubly_list(char *s)
{
    struct s_node *list;
    struct s_node *start;
    struct s_node *tmp;

    list = NULL;
    start = NULL;
    while (*s)
    {
        tmp = list;
        list = malloc(sizeof(struct s_node));
        if (tmp)
            tmp->next = list;
        list->c = *s;
        list->next = NULL;
        list->prev = tmp;
        if (!start)
            start = list;
        s++;
    }
    list->next = start;
    start->prev = list;
    return (start);
}

char    decipher(struct s_node **cs, int n)
{
    if (n == 0)
        return (*cs)->c;
    else if (n < 0)
    {
        while (n++ < 0)
            *cs = (*cs)->prev;
        return (*cs)->c;
    }
    else
    {
        while (n-- > 0)
            *cs = (*cs)->next;
        return (*cs)->c;
    }
}

char    *precious(int *text, int size)
{
    int             *tmp;
    struct s_node   *cs;
    char            *enc_str;

    tmp = text;
    enc_str = (char *)calloc(size + 1, size + 1);
    cs = create_doubly_list(CS);
    for (int i = 0; i < size; i++)
        enc_str[i] = decipher(&cs, *tmp++);
    return enc_str;
}