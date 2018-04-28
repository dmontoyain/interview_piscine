#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void    swap_nodes(struct s_node **root, struct s_swap **data)
{
    struct s_node *r;
    struct s_node *l;
    struct s_node *ll;
    struct s_node *rr;
    if (!*root)
        return ;
    if ((*root)->right != NULL && (*root)->right->value > (*root)->left->value)
    {
        if ((*root)->value < (*root)->right->value)
        {
            (*data)->swap = 1;
            (*data)->address = (*root)->right;
            (*data)->right = 1;
            r = (*root)->right->right;
            l = (*root)->right->left; 
            ll = (*root)->left;
            (*root)->right->right = *root;
            (*root)->right->left = ll;
            (*root)->right = r;
            (*root)->left = l;  
        }
    }
    else if ((*root)->left != NULL)
    {
        if ((*root)->value < (*root)->left->value)
        {
            (*data)->left = 1;
            (*data)->swap = 1;
            (*data)->address = (*root)->left;
            r = (*root)->left->right;
            l = (*root)->left->left; 
            rr = (*root)->right;
            (*root)->left->left = *root;
            (*root)->left->right = rr;
            (*root)->right = r;
            (*root)->left = l;
        }
    }
}

void    restart(struct s_swap **data)
{
    (*data)->address = NULL;
    (*data)->left = 0;
    (*data)->right = 0;
}

void    saveTheSequoia_(struct s_node **root, struct s_swap **data)
{
    if (!*root)
        return ;
    saveTheSequoia_(&((*root)->left), data);
    if ((*data)->left || (*data)->right)
        (*root)->left = (*data)->address;
    restart(data);
    saveTheSequoia_(&((*root)->right), data);
    if ((*data)->left || (*data)->right)
        (*root)->right = (*data)->address;
    restart(data);
    swap_nodes(root, data);
}

void	saveTheSequoia(struct s_node **root)
{
    struct s_swap *data = calloc(1, sizeof(struct s_swap));

    data->swap = 0;
    saveTheSequoia_(&((*root)->left), &data);
    if (data->left || data->right)
        (*root)->left = data->address;
    restart(&data);
    saveTheSequoia_(&((*root)->right), &data);
    if (data->left || data->right)
        (*root)->right = data->address;
    restart(&data);
    swap_nodes(root, &data);
    if (data->left || data->right)
        *root = data->address;
    if (!data->swap)
        return ;
    saveTheSequoia(root);
}