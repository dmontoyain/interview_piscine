#include "header.h"
#include "stdlib.h"
#include "string.h"

struct s_stack *initStack(void)
{
    return calloc(1, sizeof(struct s_stack));
}

void    build_newStackArray(struct s_tank *tank)
{
    struct s_stack **new_stacks_arrray;
    int     array_elems;
    int     i;

    array_elems = ++tank->n;
    new_stacks_arrray = calloc(tank->n, sizeof(struct s_stack *));
    if (array_elems > 1)
    {
        for (i = 0; i < (array_elems - 1); i++)
            new_stacks_arrray[i] = tank->stacks[i];
        new_stacks_arrray[i] = initStack();
        free(tank->stacks);
    }
    tank->stacks = new_stacks_arrray;
}

struct s_tank *initTank(void)
{
    struct s_tank *tank = calloc(1, sizeof(struct s_tank));
    struct s_stack *stack = initStack();
    build_newStackArray(tank);
    tank->stacks[0] = stack;
    return tank;
}

void tankPush(struct s_tank *tank, int energy)
{
    struct s_elem *elem = calloc(1, sizeof(struct s_elem));

    if (tank->stacks[tank->n - 1]->sum + energy > 1000)
    {
        if (!tank->stacks[tank->n])
            build_newStackArray(tank);
        else
            tank->n++;
    }
    struct s_stack *working_stack = tank->stacks[tank->n - 1];
    elem->next = working_stack->elem;
    elem->energy = energy;
    working_stack->elem = elem;
    working_stack->sum += energy;
}

int tankPop(struct s_tank *tank)
{
    int     energy;
    struct s_stack *working_stack = tank->stacks[tank->n - 1];

    if (!working_stack->elem)
        return (0);
    energy = working_stack->elem->energy;
    free(working_stack->elem);
    working_stack->elem = working_stack->elem->next;
    working_stack->sum -= energy;
    if (!working_stack->sum && tank->n > 1)
        tank->n--;
    return (energy);
}
