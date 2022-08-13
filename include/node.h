#ifndef _NODE_H
#define _NODE_H 1

#include <ctype.h>
#include "utils.h"
#include "token.h"

typedef enum
{
	NT_INT,
	NT_BINARY_OP,
	NT_UNARY_OP,
	NT_EOF
} Node_Type;

typedef struct node
{
	Node_Type type;

	/* binary and unary operations */
	Token_Type op;
	struct node *left;
	struct node *right;
	
	/* int nodes */
	int int_value;
} Node;

Node *node_new_node(Node_Type type);
Node *node_copy_node(Node *node);

#endif

