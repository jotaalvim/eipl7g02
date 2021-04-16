 /**
 @file  parser.h
 @brief Ficheiro com as funções relativas ao parser.
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
void soma(STACK *s);

/**
 * \brief   Função que subtrai o elemento do topo da Stack ao elemento a seguir.
 * @param s Stack
 */
void sub(STACK *s);

/**
 * \brief   Função que permite multiplicar os 2 primeiros elementos do topo da Stack.
 * @param s Stack
 */
void mult(STACK *s);

/**
 * \brief   Função que divide o 2º elemento do topo da Stack pelo elemento do topo da Stack.
 * @param s Stack
 */
void divi(STACK *s);

/**
 * \brief   Função que decrementa 1 valor ao elemento do topo da Stack.
 * @param s Stack
 */

void parA(STACK *s);

/**
 * \brief   Função que incrementa 1 valor ao elemento do topo da Stack.
 * @param s Stack
 */
void parF(STACK *s);

/**
 * \brief   Função do resto da divisão inteira do 2º elemento pelo 1º elemento do topo da Stack.
 * @param s Stack
 */
void mod(STACK *s);

/**
 * \brief   Função que calcula a potência que tem como base o elemento do topo da Stack e como expoente o elemento a seguir.
 * @param s Stack
 */
void expo (STACK *s);

/**
 * \brief   Operador bitwise onde cada bit é comparado e é retornado o valor 1 quando ambos os bits forem 1 e 0 caso contrário.
 *

 * @param s Stack
 */
void con(STACK *s);

/**
 * \brief   Operador bitwise onde cada bit é comparado e é retornado o valor 1 quando um dos bits for 1 e 0 caso contrário.
 *

 * @param s Stack
 */ 
void dis(STACK *s);

/**
 * \brief   Operador bitwise onde cada bit é comparado e é retornado o valor 1 quando os bits comparados forem diferentes e 0 caso contrário.
 * @param s Stack
 */
void xor(STACK *s);

/**
 * \brief   Operador bitwise onde cada bit é comparado que retorna o valor representado em Complemento2.
 * @param s Stack
 */
void not (STACK *s);

/**
 * \brief      Esta função divide a string dada no input usando delimitadores, separando os números dos operadores.
               É comparado o token com todos os possiveis operadores aritméticos, sendo chamada a função correspondente ao operador dado.
 * @param line A linha que foi lida e à qual se irá aplicar o parse
 * @param s    Stack
 */

void trsc (STACK*s);

void arr(STACK *s);

void stop(STACK *s);

void und(STACK *s);

void lei (STACK*s);

void trsc (STACK*s);

void trsi (STACK*s);

void trsd (STACK*s);

void parse(char *line, STACK *s);

	//void pushaux (STACK *s, elemtype x, elemvalor y);

#endif
