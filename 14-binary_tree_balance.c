#include "binary_trees.h"

/**
 * getHeight - gets the balance factor of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: the balance factor of a binary tree, If tree is NULL return 0.
 **/
int getHeight(const binary_tree_t *tree)
{
	int td, th;

	if (tree == NULL)
		return (0);

	td = getHeight(tree->left);
	th = getHeight(tree->right);

	return ((td > th) ? (td + 1) : (th + 1));
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: the balance factor of a binary tree, If tree is NULL return 0.
 **/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (getHeight(tree->left) - getHeight(tree->right));
}
