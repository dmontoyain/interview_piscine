#include "header.h"
#include <unistd.h>
#include <stdio.h>

void swap(struct s_stone **skp_start, struct s_stone **skp_end, struct s_stone **stone)
{
    struct s_stone *tmp = (*stone)->next;
    (*stone)->next = *skp_start;
    (*skp_end)->next = tmp;
}

struct s_stone   *skip_dups(struct s_stone *stone)
{
    int tmp = stone->size;
    struct s_stone *fake_stone;

    fake_stone = stone;
    while (fake_stone->next && fake_stone->next->size == tmp)
        fake_stone = fake_stone->next;
    return (fake_stone);
}

void    bubbleSort(struct s_stone **stone)
{
    struct s_stone *tmp2, *tmp, *skip;
    int     swap_f = 0;

    tmp2 = *stone;
    for (int i = 0; tmp2; i++)
    {
        tmp = *stone;
        while (tmp->next)
        {
            skip = tmp;
            tmp = skip_dups(tmp);
            if (!tmp->next)
                break ;
            if (tmp->size > tmp->next->size)
            {
                swap_f = 1;
                swap(&skip, &tmp, &tmp->next);
            }
            tmp = tmp->next;
        }
        if (!swap_f)
            break ;
        else
            swap_f = 0;
        tmp2 = tmp2->next;
    }
}

void sortStones(struct s_stone **stone)
{
    if (!stone || !*stone)
        return ;
    bubbleSort(stone);
}