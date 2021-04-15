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
    assert( fgets(line, 10240, stdin) != NULL );
    assert( line[strlen(line) - 1] == '\n'    );
    parse(line);
    return 0;
}


