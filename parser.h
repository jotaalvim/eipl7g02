#ifndef parser_h_
#define parser_h_

#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "stack.h"


void soma(STACK *s);

/**
 * \brief      Esta função divide a string dada no input usando delimitadores, separando os números dos operadores.
               É comparado o token com todos os possiveis operadores aritméticos, sendo chamada a função correspondente ao operador dado.
 * @param line A linha que foi lida e à qual se irá aplicar o parse
 * @param s    Stack
 */
void parse(char *line, STACK *s);

//void pushaux (struct Stack *s, elemtype x, elemvalor y);

#endif