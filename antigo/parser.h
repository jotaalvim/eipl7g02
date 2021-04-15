/**
 @file  parser.h
 @brief Ficheiro com as funções relativas às operações aritméticas e ao parser
 */

 
#ifndef parser_h_
#define parser_h_

#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "stack.h"

/**
 * \brief   Função que soma os 2 elementos do topo da Stack.
 * @param s Stack
 */
//void soma(struct Stack *s);


void parse(char *line,STACK *s);

//void pushaux (struct Stack *s, elemtype x, elemvalor y);

#endif