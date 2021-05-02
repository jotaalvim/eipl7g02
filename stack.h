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
typedef enum {
  LONG = 1, /**< Define o tipo LONG */
  DOUBLE = 2, /**< Define o tipo DOUBLE */
  CHAR = 4, /**< Define o tipo CHAR */
  STRING = 8 /**< Define o tipo STRING */
} TYPE;


/**
 * \brief É uma macro dos tipos LONG e CHAR.
 */
#define INTEGER  (LONG | CHAR)

/**
 * \brief É uma macro dos tipos INTEGER e DOUBLE.
 */
#define NUMBER   (INTEGER | DOUBLE)

/**
 * \brief Define os datatypes em que um certo valor será guardado.
 */
typedef struct data {
    TYPE   type; /**< Define o tipo da struct data */
/// @brief Contém as varáveis em que um certo valor será guardado.
    union {
    long   LONG; /**< Contém a variável do tipo long */
    double DOUBLE; /**< Contém a variável do tipo double */
    char   CHAR; /**< Contém a variável do tipo char */
    char*  STRING; /**< Contém a variável do tipo string */
  } elems; /**< Define o tipo dos elementos que contêm a STACK*/
} DATA;
/** 
*\brief Define a constituição de uma Stack.  
*/ 
typedef struct stack {
  DATA *stack; /**< Define a STACK*/
  int size; /**< Define o tamanho da STACK */
  int n_elems; /**< Define o número de elementos da STACK */
} STACK;


/**
 * \brief É uma macro.
 */
#define make_datas(var,TYPE,value)  { var.elems.TYPE =value;   var.type=TYPE; } 

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
