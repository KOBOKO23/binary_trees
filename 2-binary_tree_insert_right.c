#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in.
 * @value: value to store in the new node.
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 *
 **/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;
	int temp;

	if (parent == NULL)
		return (NULL);

	if (!parent->right)
	{
		new_node = binary_tree_node(parent, value);
		parent->right = new_node;
		return (new_node);
	}

	new_node = binary_tree_node(parent->right, value);
	parent->right->right = new_node;

	temp = parent->right->right->n;
	parent->right->right->n = parent->right->n;
	parent->right->n = temp;

	return (new_node);
}
