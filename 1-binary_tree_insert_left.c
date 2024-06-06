#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node.
 * @parent: a pointer to the node to insert the left-child.
 * @value: the value to store in the new node.
 * Return: pointer to the created node, NULL on failure or if parent is
 * NULL
 **/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;
	int temp;

	if (parent == NULL)
		return (NULL);

	if (!parent->left)
	{
		new_node = binary_tree_node(parent, value);
		parent->left = new_node;
		return (new_node);
	}

	new_node = binary_tree_node(parent->left, value);
	parent->left->left = new_node;

	temp = parent->left->left->n;
	parent->left->left->n = parent->left->n;
	parent->left->n = temp;

	return (new_node);
}
