#ifndef ___STACK_H___
#define ___STACK_H___

#include <assert.h>

//typedef permite guardar vários valores dentro de um tipo
//de dados  
//enum é um tipo enumerado
typedef enum {
    LONG = 1, 
    DOUBLE = 2, 
    CHAR = 4, 
    STRING = 8
}TYPE;


// #define usa-se para declarar constantes(não podem ser
// alteradas)
#define INTEGER (LONG | CHAR )
#define NUMBER (INTEGER | DOUBLE )

typedef struct data {
    TYPE type;
    //Esta parte devia ser tranformada numa
    //union mais tarde
    long LONG;
    double DOUBLE;
    char CHAR;
    char *STRING;
} DATA;


typedef struct stack {
    DATA *stack;
    int size;
    int n_elems;
} STACK;


int has_type(DATA elem, int mask);
STACK *create_stack();
void push(STACK *s, DATA elem);
DATA pop(STACK *s);
DATA top(STACK *s);
int is_empty(STACK *s);
void print_stack(STACK *s);












