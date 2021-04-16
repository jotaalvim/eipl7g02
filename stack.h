/**
 @file  stack.h
 @brief Ficheiro com funções relativas à implementação da Stack.
 */


#ifndef ___STACK_H___
#define ___STACK_H___

#include <assert.h>


/**
 * \brief Define os diferentes tipos que um elemento da Stack poderá assumir.
 */
typedef enum {LONG = 1, DOUBLE = 2, CHAR = 4, STRING = 8} TYPE;

#define INTEGER  (LONG | CHAR)
#define NUMBER   (INTEGER | DOUBLE)

/**
 * \brief Define os datatypes em que um certo valor será guardado.
 */
typedef struct data {
  TYPE   type;
  union {
  long   LONG;
  double DOUBLE;
  char   CHAR;
  char*  STRING;
  } elems;
} DATA;

 /**
 * \brief Define a constituição de uma Stack.
 */
typedef struct stack {
  DATA *stack;
  int size;
  int n_elems;
} STACK;


#define make_datas(var, TYPE, value)     \
        var.elems.TYPE =value;           \
        var.type       =TYPE;                      


int has_type(DATA elem, int mask);

 /**
 * \brief Função que atribui um número ao type de um dado DATA.
 * @param d DATA 
 * @return r Inteiro utilizado para identificar o type da DATA.
 *
 */
int what_type (DATA d);


 /**
 * \brief Função que cria uma Stack com tamanho 100.
 * 
 * @return s Stack criada. 
 */
STACK *create_stack();


/**
 * \brief Função que adiciona um dado elemento a uma Stack. 
 * @param s Stack 
 * @param elem Elemento a adicionar
 */
void push(STACK *s, DATA elem);


 /**
 * \brief Função que retira o último elemento da Stack.
 * @param s Stack
 * @return Elemento retirado da Stack
 */
DATA pop(STACK *s);


/**
 * \brief Função que devolve o elemento no topo da Stack.
 * @param s Stack 
 * @return Elemento no topo da Stack.
 */
DATA top(STACK *s);

 /**
 * \brief Função que verifica que uma Stack está vazia.
 * @param s Stack
 * @return Devolve um valor boleano dependendo da Stack estar ou não vazia.
 */
int is_empty(STACK *s);


/**
 * \brief Função utilizada para imprimir uma Stack.
 */
void print_stack(STACK *s);

#endif