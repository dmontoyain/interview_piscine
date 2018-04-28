#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void    push(struct s_node *node, struct s_stack **stack)
{
    struct s_stack *tmp = *stack;
    struct s_stack *new_node = calloc(1, sizeof(struct s_stack));
    if (!node)
        return ;
    if (!*stack)
        *stack = new_node;
    else
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new_node;
    }
    new_node->node = node;
}

struct s_node *compare_stacks(struct s_stack *stack_1, struct s_stack *stack_2)
{
    struct s_stack *tmp2;

    tmp2 = stack_2;
    for (int i = 0; stack_1; i++)
    {
        stack_2 = tmp2;
        for (int j = 0; stack_2; j++)
        {
            if (stack_1->node == stack_2->node)
                return stack_1->node;
            stack_2 = stack_2->next;
        }
        stack_1 = stack_1->next;
    }
    return NULL;
}

int     findParent_(struct s_node *root, char *Species, struct s_stack **stack)
{
    if (!root || !root->children)
        return 0;
    if (!strcmp(root->name, Species))
        return 1; 
    for (int i = 0; root->children[i]; i++){
        if (findParent_(root->children[i], Species, stack))
        {
            push(root, stack);
            return 1;
        }
    }
    return 0;
}

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
    struct s_stack  *stack_1 = NULL;
    struct s_stack  *stack_2 = NULL;

    if (!root)
        return root;
    findParent_(root, firstSpecies, &stack_1);
    findParent_(root, secondSpecies, &stack_2);
    return compare_stacks(stack_1, stack_2);
}