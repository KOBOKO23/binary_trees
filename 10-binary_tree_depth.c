#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @tree: a pointer to the node to measure the depth.
 * Return: the height of a binary tree, If tree is NULL return 0.
 **/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	binary_tree_t *new_parent;
	int depth = 0;

	if (tree == NULL || tree->parent == NULL)
		return (0);

	new_parent = tree->parent;
	while (new_parent)
	{
		new_parent = new_parent->parent;
		depth++;
	}

	return (depth);
}
