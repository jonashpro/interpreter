#include "include/interpreter.h"

void interpreter_run(Parser *parser)
{
	Node *node;

	while ((node = parser_get_next_node(parser))->type != NT_EOF)
	{
		printf("%d\n", interpreter_evaluate_node(node));
	}
}

int interpreter_evaluate_node(Node *node)
{
	switch (node->type)
	{
		case NT_INT:
		{
			return node->int_value;
		}

		case NT_BINARY_OP:
		{
			int left = interpreter_evaluate_node(node->left);
			int right = interpreter_evaluate_node(node->right);

			switch (node->op)
			{
				case TT_PLUS:
					return left + right;

				case TT_MINUS:
					return left - right;

				case TT_ASTERISK:
					return left * right;

				case TT_SLASH:
					return left / right;

				case TT_EOF:
				case TT_ID:
				case TT_INT:
				case TT_LPAREN:
				case TT_RPAREN:
				default:
					assert(0 && "unreachable statement");
			}

			break;
		}

		case NT_UNARY_OP:
		{
			break;
		}

		case NT_EOF:
		default:
			assert(0 && "unreachable statement");
	}

	return 0;
}

