#include "header.h"
#include <unistd.h>
#include <stdio.h>

void    swapIt(t_ns *ns)
{
    int size;
    t_s *tmp;
    // Swapping sizes
    size = ns->size;
    ns->size = ns->next->size;
    ns->next->size = size;
    // Swapping the startStone pointers
    tmp = ns->startStone;
    ns->startStone = ns->next->startStone;
    ns->next->startStone = tmp;
    // Swapping the lastStone pointers
    tmp = ns->lastStone;
    ns->lastStone = ns->next->lastStone;
    ns->next->lastStone = tmp;
}

t_ns    *buildNewStone(struct s_stone *stone, int *numOfNewStones)
{
    t_ns    *new, *ns = NULL;
    int     lastSize = 0;
    while (stone)
    {
        if (lastSize != stone->size)
        {
            if (!(new = malloc(sizeof(t_ns))))
                return (NULL);
            new->next = ns ? ns : NULL;
            ns = new;
            ns->size = stone->size;
            ns->startStone = stone;
            lastSize = stone->size;
            *numOfNewStones += 1;
        }
        ns->lastStone = stone;
        stone = stone->next;
    }
    return (ns);
}
void    sortStones(struct s_stone **stone)
{
    t_ns    *ns, *head;
    int     numOfNewStones = 0;
    int     i, j, swapped;
    if (!stone)
        return ;
    head = buildNewStone(*stone, &numOfNewStones);
    for (i = 0; i < numOfNewStones - 1; i++)
    {
        ns = head;
        swapped = 0;
        for (j = 0 ; j < numOfNewStones - i - 1 ; j++)
        {
            if (ns->size > ns->next->size && (swapped = 1))
                swapIt(ns);
            ns = ns->next;
        }
        if (swapped == 0)
            break;
    }
    ns = head;
    while (ns->next)
    {
        ns->lastStone->next = ns->next->startStone;
        ns = ns->next;
    }
    ns->lastStone->next = NULL;
    *stone = head->startStone;
}