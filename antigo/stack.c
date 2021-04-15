#include "stack.h"
 

STACK *criar_stack(STACK *s) {
    s->n_elem = 0;
    return 0; // NÂO DEVIA SER RETURN S?
}

void push (STACK *s, TYPE t,...) {
	int tnovo = s->n_elem +1;
	s->stack = realloc (s->stack, tnovo*sizeof((*s)->stack));

	va_list x;
    va_start (x, t);
    s->stack[s->n_elem].type = t;
    switch (t) {
       case LONG:
            s->stack[s->n_elem].val.LONG = va_arg(x, long); break;
       case DOUBLE:
            s->stack[s->n_elem].val.DOUBLE = va_arg(x, double); break;
       case STRING:
            s->stack[s->n_elem].val.STRING = va_arg(x, char*); break;
       case CHAR:
            s->stack[s->n_elem].val.CHAR = (char) va_arg(x, int); break;
       default: break;                 
    }
    s->n_elem++;
    va_end(x);
}



Valor pop(STACK *s) {
    assert (s->stack != 0); //verificar se a stack não é vazia
    Valor top = s->stack[s->n_elem-1].val; //elemento que vamos remover
    int tnovo = s->n_elem-1;
    s->n_elem = realloc(s->stack, tnovo*sizeof(*s->stack)); 
    s->n_elem--;
    return top;
}

/**
 * \brief   Função que devolve o tipo do elemento do topo da Stack.
 * @param s Stack
 * @returns Tipo do elemento do topo
 */
TYPE peek (STACK *s) {
    return s->stack[s->n_elem-1].TYPE;
}


//Valor peekind (struct Stack *s, int n) {
//    return s->stack[s->n_elem-n-1].TYPE;
//}

/**
 * \brief Função que imprime a Stack.
 * @param s Stack
 */
void print_stack(STACK *s) {
    for (int i =0; i < s->n_elem; i++)
      switch (s->stack[i].TYPE) {
          case LONG:
                printf("%lu", s->stack[i].val.LONG); break;
          case DOUBLE:
                printf("%g", s->stack[i].val.DOUBLE); break;
          case STRING:
                printf("%s", s->stack[i].val.STRING); break;
          case CHAR:
                printf("%c", s->stack[i].val.CHAR); break;
          default: break;
      }
    printf("\n");
}
