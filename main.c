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
    //char linha[] = "123 abc bananas";
    //printf("%s\n",linha);

    //char **rest;

    //*rest = linha;

    //char *token;
    //for ( token = get_token2(linha, rest); token != NULL; token = get_token2(linha,rest)) {
    //    printf("token : %s\n",token);
    //    printf("resto : %s\n",*rest);
    //    strcpy(linha,*rest);
    //}
    //char *token;
    //for ( token = get_token(rest); token != NULL; token = get_token(rest)) {
    //    printf("token : %s\n",token); //    printf("resto : %s\n",*rest);
    //}

    //x = get_token2(linha, &rest);
    //printf("token : %s\n",x);
    //printf("resto : %s\n",rest);
    //x = get_token2(rest, &rest);
    //printf("token : %s\n",x);
    //printf("resto : %s\n",rest);


    //x = get_token(&rest);
    //printf("token : %s\n",x);
    //printf("resto : %s\n",rest);
    //x = get_token(&rest);
    //printf("token : %s\n",x);
    //printf("resto : %s\n",rest);
    
    STACK *s;
    s = create_stack();
    char line[10240];
    assert(fgets(line, 10240, stdin) != NULL);
    assert(line[strlen(line) - 1] == '\n');
    parse(line, s);
    print_stack(s);
    return 0;

}
