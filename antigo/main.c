/** * @file Ficheiro no qual se encontra o programa principal.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "parser.h"

/**
 * \brief Função principal do programa.
 *
 *
 *
 * @returns 0 valor 0
 */

int main() {
    char line[10240];
    STACK *s;
    s = (STACK*)malloc(0*sizeof(DATA)); //alocar mem
    criar_stack(s);
    assert(fgets(line, 10240, stdin) != NULL) ;
    assert(line[strlen(line) - 1] == '\n');
    parse(line, s);
    print_stack(s);
    return 0;
}