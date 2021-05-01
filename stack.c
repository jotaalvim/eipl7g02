/** @file  stack.c
 @brief Ficheiro com funções relativas à Stack.
 */

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"



int has_type(DATA elem, int mask) {
  return (elem.type & mask) != 0;
}


 /**
 * \brief Função que atribui um número ao type de um dado DATA.
 * @param d DATA 
 * @return r Inteiro utilizado para identificar o type da DATA.
 *
 */

int what_type (DATA d) {
    int r=0;
    if (d.type == LONG) r=1;
    if (d.type == DOUBLE) r=2;
    if (d.type == CHAR) r=4;
    if (d.type == STRING) r=8;
    return r;   
}


 /**
 * \brief Função que cria uma Stack com tamanho 100.
 * 
 * @return s Stack criada. 
 */

STACK *create_stack() {
  STACK *s = (STACK *) calloc(1, sizeof(STACK));
  s->size = 100;
  s->stack = (DATA *) calloc(s->size, sizeof(DATA));
  return s;
}

 
 /**
 * \brief Função que adiciona um dado elemento a uma Stack. 
 * @param s Stack 
 * @param elem Elemento a adicionar
 */

void push(STACK *s, DATA elem) {
  if(s->size == s->n_elems) {
    s->size += 100;
    s->stack = (DATA *) realloc(s->stack, s->size * sizeof(DATA));
  }
  s->stack[s->n_elems] = elem;
  s->n_elems++;
}

 /**
 * \brief Função que retira o último elemento da Stack.
 * @param s Stack
 * @return Elemento retirado da Stack
 */

DATA pop(STACK *s) {
  s->n_elems--;
  return s->stack[s->n_elems];
}


 /**
 * \brief Função que devolve o elemento no topo da Stack.
 * @param s Stack 
 * @return Elemento no topo da Stack.
 */

DATA top(STACK *s) {
  return s->stack[s->n_elems - 1];
}


 /**
 * \brief Função que verifica que uma Stack está vazia.
 * @param s Stack
 * @return Devolve um valor boleano dependendo da Stack estar ou não vazia.
 */

int is_empty(STACK *s) {
  return s->n_elems == 0;
}


 /**
 * \brief Função que dá print a uma Stack.
 * @param s Stack
 */

void print_stack(STACK *s) {
  for(int K = 0; K < s->n_elems; K++) {
    DATA elem = s->stack[K];
    TYPE type = elem.type;
    switch(type) {
      case LONG:   printf("%ld", elem.elems.LONG  ); break;
      case DOUBLE: printf("%g" , elem.elems.DOUBLE); break;
      case CHAR:   printf("%c" , elem.elems.CHAR  ); break;
      case STRING: printf("%s" , elem.elems.STRING); break;
    }
  }
  printf("\n");                               
}


