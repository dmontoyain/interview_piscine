#include "header.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

struct s_stack *initStack(void)
{
    return calloc(1, sizeof(struct s_stack));
}

void    push(struct s_stack *stack, int idx)
{
    struct s_item *item = calloc(1, sizeof(struct s_item));
    item->next = stack->item;
    stack->item = item;
    item->idx = idx;
}

int     pop(struct s_stack *stack)
{
    struct s_item *item;
    int     idx;

    if (!stack->item)
        return (0);
    item = stack->item;
    stack->item = stack->item->next;
    idx = item->idx;
    free(item);
    return (idx);
}

char    *console(void)
{
    char    *msg;
    char    *input;
    size_t  size;
    struct s_stack *stack;
    int     del_i;

    stack = initStack();
    size = 256;
    msg = (char *)calloc(size, size);
    input = (char *)calloc(size, size);
    while (1)
    {
        printf("?: ");
        getline(&input, &size, stdin);
        if (!strcmp(input, "UNDO\n"))
        {
            if (!msg[0])
                printf("Message is empty. Nothing to undo.\n");
            else
            {
                del_i = pop(stack);
                memset(&msg[del_i], 0, 256 - del_i);
                bzero(input, 256);
            }
        }
        else if (!strcmp(input, "SEND\n"))
        {
            if (!msg[0])
                printf("Message is empty. Nothing to send.");
            else
            {
                while (stack->item)
                    pop(stack);
                free(stack);
                break ;
            }
        }
        else
        {
            if (strlen(msg) + strlen(input) > 255)
            {
                printf("Error: message too long (maximum of 255 characters)");
                exit(0);
            }
            *strstr(input, "\n") = '\0';
            push(stack, strlen(msg));
            strcat(msg, input);
            memset(input, 0, 256);
        }
        printf("%s\n\n", msg);
    }
    return (msg);
}