#include "binary_trees.h"

/**
 * binary_tree_node -  creates a new root node.
 *
 * @parent: - a pointer to the node to insert the left-child in.
 * @value: - the value to store in the new node.
 * Return: a pointer to the created node, or NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	/* Declaration of ptr to new_node */
	binary_tree_t *new_node;

	/* Memory allocation for new_node var*/
	new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	/* values assigment */
	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	/* return ptr to new_node */
	return (new_node);
}
