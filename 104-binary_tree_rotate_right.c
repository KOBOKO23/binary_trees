#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree.
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *parent;

	if (!tree || !tree->left)
		return (tree);
	parent = tree->left;
	tree->left = parent->right;
	if (tree->left != NULL)
	{
		tree->left->parent = tree;
	}
	parent->right = tree;
	parent->parent = tree->parent;
	tree->parent = parent;

	return (parent);
}
