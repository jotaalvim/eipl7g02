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
 * \brief Função que soma os 2 elementos do topo da Stack.
 * @param s Stack
 */
void soma(struct Stack *s);

/**
 * \brief Função que subtrai o elemento do topo da Stack ao elemento seguinte.
 * @param s Stack
 */
void sub(struct Stack *s);

/**
 * \brief Função que multiplica os 2 primeiros elementos do topo da Stack.
 * @param s Stack
 */
void mult(struct Stack *s);

/**
 * \brief Função que divide o 2º elemento da Stack pelo elemento do topo da Stack.
 * @param s Stack
 */
void div(struct Stack *s);

/**
 * \brief Função que decrementa 1 valor ao elemento do topo da Stack.
 * @param s Stack
 */
void parentAb(struct Stack *s);

/**
 * \brief Função que incrementa 1 valor ao elemento do topo da Stack.
 * @param s Stack
 */
void parentFe(struct Stack *s);

/**
 * \brief Função que devolve o resto da divisão inteira do 2º elemento pelo 1º elemento do topo da Stack.
 * @param s Stack
 */
void mod(struct Stack *s);

/**
 * \brief Função que calcula a potência que tem como base o elemento do topo da Stack e como expoente o elemento seguinte.
 * @param s Stack
 */
void expo(struct Stack *s);

/**
 * \brief Operador bitwise em que cada bit é comparado e é retornado o valor 1 quando ambos os bits forem 1 e 0 caso contrário.
 * @param s Stack
 */
void conj(struct Stack *s);

