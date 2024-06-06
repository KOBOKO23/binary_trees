#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: the height of a binary tree, If tree is NULL return 0.
 **/
size_t binary_tree_height(const binary_tree_t *tree)
{
	int td = 0, th = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		td = binary_tree_height(tree->left) + 1;
	if (tree->right)
		th = binary_tree_height(tree->right) + 1;

	return (td > th ? td : th);
}
