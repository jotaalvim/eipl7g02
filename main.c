#include <stdio.h>
#include <string.h>
#include "stack.h"

void imprime_tipo(STACK *s) {
    if(has_type(top(s), STRING)) putchar('S');
    if(has_type(top(s), INTEGER)) putchar('I');
    if(has_type(top(s), DOUBLE)) putchar('D');
    if(has_type(top(s), NUMBER)) putchar('N');
}

int main (void) {
	STACK *s = create_stack();

	DATA z;
	make_datas(z,LONG,14);
	push(s,z);

	//imprime_tipo(s);
	print_stack(s);

    return 0;
}
