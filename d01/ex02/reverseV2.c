#include "header.h"
#include <stdio.h>
#include <stdlib.h>

struct s_stack *stackInit(void)
{
    return calloc(1, sizeof(struct s_stack));
}

void *pop(struct s_stack *stack)
{
    struct s_item *item;

    if (!stack->item)
        return (NULL);
    item = stack->item;
    stack->item = stack->item->next;
    return (item);
}

void push(struct s_stack *stack, char *word)
{
    struct s_item *item = calloc(1, sizeof(struct s_item));
    item->next = stack->item;
    stack->item = item;
    item->word = word;
}

void printReverseV2(struct s_node *lst)
{
    struct s_stack *stack = stackInit();
    struct s_item   *item;

    while (lst)
    {
        push(stack, lst->word);
        lst = lst->next;
    }
    while ((item = pop(stack)))
    {
        if (stack->item)
            printf("%s ", item->word);
        else
            printf("%s\n", item->word);
    }
}