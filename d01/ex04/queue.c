#include "header.h"
#include <stdlib.h>
#include <stdio.h>

int isEmpty(struct s_queue *queue)
{
    return !queue->first; 
}

struct s_queue *queueInit(void)
{
    return calloc(1, sizeof(struct s_queue));     
}

char *dequeue(struct s_queue *queue)
{
    char *data;
    struct s_node *node;

    if (isEmpty(queue))
        return 0;
    data = queue->first->message;
    node = queue->first;
    queue->first = queue->first->next;
    free(node);
    return data;

}
void enqueue(struct s_queue *queue, char *message)
{
    struct s_node *new_node = calloc(1, sizeof(struct s_node));
    if (queue->last)
    {
        queue->last->next = new_node;
        queue->last = new_node;
    }
    else
    {
        queue->first = new_node;
        queue->last = new_node;
    }
    new_node->message = message;
}

char *peek(struct s_queue *queue)
{
    if (isEmpty(queue))
        return 0;
    return queue->first->message;
}

