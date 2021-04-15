#include <stdio.h>
#include <string.h>
#include "stack.h"
//#include "parser.c"
#include "parser.h"

#include <stdlib.h>
void imprime_tipo(STACK *s) {
    if(has_type(top(s), STRING)) putchar('S');
    if(has_type(top(s), INTEGER)) putchar('I');
    if(has_type(top(s), DOUBLE)) putchar('D');
    if(has_type(top(s), NUMBER)) putchar('N');
}

int main (void) {
    //STACK *s = create_stack();
    //DATA z;
    //make_datas(z,LONG,14);
    //push(s,z);
    ////imprime_tipo(s);
    //print_stack(s);
    //return 0;


    char line[10240];
    STACK *s;
    s = (STACK*)malloc(0*sizeof(DATA)); //alocar mem
    create_stack(s);
    assert(fgets(line, 10240, stdin) != NULL) ;
    assert(line[strlen(line) - 1] == '\n');
    parse(line, s);
    print_stack(s);
    return 0;

}
