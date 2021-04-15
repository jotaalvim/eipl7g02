#ifndef STACK_H_
#define STACK_H_

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
//typedef permite guardar vários valores dentro de um tipo
//de dados  
//enum é um tipo enumerado
typedef enum { 
	LONG, 
	DOUBLE, 
	CHAR, 
	STRING 
} TYPE;


// #define usa-se para declarar constantes(não podem ser
// alteradas)
#define INTEGER (LONG | CHAR )
#define NUMBER (INTEGER | DOUBLE )

typedef union Data {
    long LONG;
    double DOUBLE;
    char CHAR;
    char *STRING;
} Valor;

typedef struct data {
    Valor val;
    TYPE type;
} DATA;
 


typedef struct stack {
    DATA *stack;
    int n_elem;
} STACK;


STACK *criar_stack(STACK *s);


void push(STACK *s,TYPE t,...);

Valor pop(STACK *s);

TYPE peek (STACK *s);

// peekind

void print_stack(STACK *s);


#endif
