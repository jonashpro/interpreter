#include "include/node.h"

Node *node_new_node(Node_Type type)
{
	Node *node = new(Node);
	node->type = type;

	return node;
}

Node *node_copy_node(Node *node)
{
	Node *new_node = node_new_node(node->type);
	new_node->left = node_copy_node(node->left);
	new_node->right = node_copy_node(node->right);
	new_node->op = node->op;
	new_node->int_value = node->int_value;

	return new_node;
}

