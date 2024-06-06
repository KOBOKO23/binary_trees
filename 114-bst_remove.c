#include "binary_trees.h"
#include <stdio.h>


bst_t *minimum(bst_t *root);

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 * Return: a pointer to the new root node of the tree after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *val, *temp;

	if (root == NULL)
		return (root);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			if (root->parent != NULL)
			{
				if (root->parent->left == root)
					root->parent->left = temp;
				else
					root->parent->right = temp;
				if (temp != NULL)
					temp->parent = root->parent;
			}
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			if (root->parent != NULL)
			{
				if (root->parent->left == root)
					root->parent->left = temp;
				else
					root->parent->right = temp;
				if (temp != NULL)
					temp->parent = root->parent;
			}
			free(root);
			return (temp);
		}
		else
		{
			val = minimum(root->right);
			root->n = val->n;
			root->right = bst_remove(root->right, val->n);
		}
	}
	return (root);
}
/**
 * minimum - find minimum in a tree.
 * @root: the root of the tree
 * Return: pointer to a node that has the val value
 */
bst_t *mininum(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}
