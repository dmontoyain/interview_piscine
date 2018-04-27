#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

int    getTreeElemsInfo(struct s_node *root, int *min, int *max)
{
    if (!root)
        return 0;
    int elems_l = getTreeElemsInfo(root->left, min, max);
    int elems_r = getTreeElemsInfo(root->right, min, max);
    if (!*min || root->value < *min)
        *min = root->value;
    if (!*max || root->value > *max)
        *max = root->value;
    return elems_l + elems_r + 1;
}

int     getTreeHeight(struct s_node *root, int *isBalanced)
{
    if (!root)
        return 0;
    int left_h = getTreeHeight(root->left, isBalanced);
    int right_h = getTreeHeight(root->right, isBalanced);
    if (left_h == right_h)
        *isBalanced = 1;
    else
        *isBalanced = 0;
    if (left_h > right_h)
        return left_h + 1;
    return right_h + 1;
}

//lor = to determine which side of the BT (left or right)
int     isBST(struct s_node *root, int rootVal)
{
    if (!root)
        return 1;
    if (root->left && root->left->value > root->value)
        return 0;
    if (root->right && root->right->value < root->value) 
        return 0;
    if (!isBST(root->left, rootVal))
        return 0;
    if (!isBST(root->right, rootVal))
        return 0;
    return 1;
}

struct s_info  getInfo(struct s_node *root)
{
    struct s_info *info;

    info = calloc(1, sizeof(struct s_info));
    info->isBalanced = 1;
    info->isBST = isBST(root, root->value); //?missing compare rootVal vs further childs
    info->height = getTreeHeight(root, &info->isBalanced);
    info->elements = getTreeElemsInfo(root, &info->min, &info->max);
    return *info;
}