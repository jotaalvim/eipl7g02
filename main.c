 /**
 @file main.c 
 @brief Ficheiro no qual se encontram as funções principais do programa.
 */

#include <stdio.h>
#include <string.h>
#include "stack.h"

#include "parser.h"

#include <stdlib.h>

/**

 * \brief Função main do programa.
 * @returns 0  
 */
int main (void) {
    DATA ll[26];
    initVetor(ll);

    STACK *s;
    s = create_stack();
    char line[10240];
    assert(fgets(line, 10240, stdin) != NULL);
    assert(line[strlen(line) - 1] == '\n');
    s = parse(line, s, ll);
    print_stack(s);
    printf("\n");
    return 0;
}
