#include "binary_trees.h"

/**
 * binary_tree_depth - finds the depth of the tree
 * @tree: a pointer to the node with max depth.
 * Return: the depth of the tree, NULL if no tree.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	binary_tree_t *immediate_parent;
	size_t depth = 0;

	if (tree == NULL || tree->parent == NULL)
		return (0);
	immediate_parent = tree->parent;
	while (immediate_parent)
	{
		depth++;
		immediate_parent = immediate_parent->parent;
	}

	return (depth);
}

/**
 * binary_trees_ancestor - lowest common ancestor of two nodes
 * @first: first node
 * @second: second node
 * Return: Lowest common ancestor or Null if not found
 */
binary_tree_t *
binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *min_node, *max_node, *temp;
	size_t first_depth, second_depth;

	if (first == NULL || second == NULL)
		return (NULL);

	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);

	if (first_depth >= second_depth)
	{
		max_node = (binary_tree_t *) first;
		min_node = (binary_tree_t *) second;
	} else
	{
		max_node = (binary_tree_t *) second;
		min_node = (binary_tree_t *) first;
	}
	temp = max_node;

	while (min_node && max_node)
	{
		if (min_node == max_node)
			return (min_node);
		if (max_node->parent == NULL)
		{
			min_node = min_node->parent;
			max_node = temp;
		} else
		{
			max_node = max_node->parent;
		}
	}

	return (NULL);
}
