#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <math.h>

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


int     getTreeHeight(struct s_node *root)
{
    if (!root)
        return 0;
    int left_h = getTreeHeight(root->left);
    int right_h = getTreeHeight(root->right);
    if (left_h > right_h)
        return left_h + 1;
    return right_h + 1;
}

int     isBalanced(struct s_node *root)
{
return (
        !root ? 1 :
        (abs(getTreeHeight(root->left) - getTreeHeight(root->right)) < 2 &&
        isBalanced(root->left) && isBalanced(root->right)) ? 1 : 0
        );
}

//lor = to determine which side of the BT (left or right)
int     isBST(struct s_node *root, struct s_node *prev)
{
    if (root)
    {
        if (!isBST(root->left, prev))
            return (0);
        if (prev && prev->value >= root->value)
            return (0);
        prev = root;
        return (isBST(root->right, prev));
    }
    return (1);
}

struct s_info  getInfo(struct s_node *root)
{
    struct s_info *info;

    info = calloc(1, sizeof(struct s_info));
    info->isBalanced = isBalanced(root);
    info->isBST = isBST(root, 0); 
    info->height = getTreeHeight(root);
    info->elements = getTreeElemsInfo(root, &info->min, &info->max);
    return *info;
}