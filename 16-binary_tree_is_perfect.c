#include "binary_trees.h"

/**
 * binary_tree_height - gives the height of a binary tree
 * @tree: pointer to tree node
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lheight, rheight;

	if (!tree)
		return (0);

	lheight = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	rheight = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (lheight > rheight ? lheight : rheight);
}

/**
 * get_size - gets the size of the tree
 * @tree: the root of the tree
 * @num: number of nodes of the tree
 * Return: size of the tree
 */

size_t get_size(binary_tree_t *tree, size_t *num)
{
	if (!tree)
		return (0);
	(*num)++;
	get_size(tree->left, num);
	get_size(tree->right, num);
	return (*num);
}

/**
 * binary_tree_size - the size of the tree
 * @tree: the root of the tree
 * Return: size of the tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t lsize = 0, rsize = 0;

	if (tree == NULL)
		return (0);
	lsize = get_size(tree->left, &lsize);
	rsize = get_size(tree->right, &rsize);

	return (1 + rsize + lsize);
}


/**
 * binary_tree_is_perfect - checks if a binary tree is full
 * @tree: root node
 * Return: 1 is_perfect otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t tree_height, tree_size, i, two_pow_h = 1;

	if (tree == NULL)
		return (0);

	tree_height = binary_tree_height(tree);
	tree_size = binary_tree_size(tree);

	for (i = 0; i <= tree_height; i++)
		two_pow_h *= 2;

	return (tree_size == two_pow_h - 1);
}
