 /**
 @file main.c 
 @brief Ficheiro no qual se encontram as funções principais do programa.
 */

#include <stdio.h>
#include <string.h>
#include "stack.h"
//#include "parser.c"
#include "parser.h"

#include <stdlib.h>

/**

 * \brief Função main do programa.
 * @returns 0  
 */
int main (void) {
    char line[10240];
    STACK *s;
    s = create_stack();
    assert(fgets(line, 10240, stdin) != NULL) ;
    assert(line[strlen(line) - 1] == '\n');
    parse(line, s);
    print_stack(s);
    return 0;

}
