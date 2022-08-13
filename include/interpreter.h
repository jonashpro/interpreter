#ifndef _INTERPRETER_H
#define _INTERPRETER_H 1

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include "parser.h"
#include "token.h"
#include "node.h"
#include "utils.h"

void interpreter_run(Parser *parser);
int interpreter_evaluate_node(Node *node);

#endif

