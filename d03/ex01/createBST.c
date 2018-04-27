#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct s_node *createBST_(int *arr, int l, int r)
{
	struct s_node	*root;
	if (l > r)
		return 0;
	root = calloc(1, sizeof(struct s_node));
	int m = (l + r) / 2;
	root->value = arr[m];
	root->left = createBST_(arr, l, m - 1);
	root->right = createBST_(arr, m + 1, r);
	return root;
}


struct s_node *createBST(int *arr, int n)
{
	return createBST_(arr, 0, n - 1);
}