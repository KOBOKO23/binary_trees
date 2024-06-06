#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: the height of a binary tree, If tree is NULL return 0.
 **/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	binary_tree_t *curr_parent;
	int depth = 0;

	if (tree == NULL || tree->parent == NULL)
		return (0);

	curr_parent = tree->parent;
	while (curr_parent)
	{
		curr_parent = curr_parent->parent;
		depth++;
	}

	return (depth);
}
