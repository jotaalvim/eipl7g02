 /**
 @file  parser.h
 @brief Ficheiro com as funções relativas ao parser.
 */

 
#ifndef parser_h_
#define parser_h_

#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "stack.h"


/**
 * \brief Função que incrementa 1 valor ao elemento do topo da Stack. Caso seja um array/string o último elemento é colocado no topo da Stack.
 * @param s Stack
 */
void parA(STACK *s);

/**
 * \brief Função que incrementa 1 valor ao elemento do topo da Stack. Caso seja um array/string o último elemento é colocado no topo da Stack.
 * @param s Stack
 */
void parF(STACK *s);

/**
 * \brief Função bitwise que incrementa e troca o sinal do elemento no topo da stack. Caso seja um array/string todos os seus elementos são colocados na Stack.
 * @param s Stack
 */
void not (STACK *s);

/**
* \brief Função que troca os três elementos do topo da Stack entre si.
* @param s Stack
*/
void arr(STACK*s);

/**
 * \brief Função que troca os dois elementos do topo da Stack.
 * @param s Stack
 */
void stop(STACK*s);


/**
 * \brief Função que duplica o elemento do topo da Stack.
 * @param s Stack
 */
void und(STACK*s);


/**
* \brief Função que lê uma linha.
* @param s Stack
*/
void lei (STACK*s);


/**
 * \brief Função que copia o n-ésimo elemento (definido pelo elemento que se encontra no topo da stack) para o topo da Stack.
 * @param s Stack
 */
void tpi (STACK*s);


/**
 * \brief Função que copia o n-ésimo elemento (definido pelo elemento que se encontra no topo da stack) para o topo da Stack.
 * @param s Stack
 */
void trsc (STACK*s);


/**
* \brief Função que converte o elemento no topo da Stack num Inteiro.
* @param s Stack 
*/
void trsi (STACK*s);


/**
* \brief Função que converte o elemento no topo da Stack num Double.
* @param s Stack 
*/
void trsd (STACK*s);


/**
 * \brief      Esta função divide a string dada no input usando delimitadores, separando os números dos operadores.
               É comparado o token com todos os possiveis operadores aritméticos, sendo chamada a função correspondente ao operador dado.
 * @param line A linha que foi lida e à qual se irá aplicar o parse
 * @param s    Stack
 */

STACK *parse(char *line, STACK *s, DATA ll[]);


/**
 * \brief Função que separa um token do resto da linha, devolvendo os dois.     
 * @param line A linha quer será lida
 * @param rest O resto da linha após ser separada do token   
 */
char *get_token3(char *line, char **rest);
//char *get_token2(char *line, char **rest);
//char *get_token(char **rest);

/** 
 * \brief Função que dado algo delimitado por [] ou "", devolve o conteúdo dentro das delimitações.   
 * @param line A linha que será lida
 * @param rest O resto da linha  
 */
char *get_delimited(char *line, char **rest);

void initVetor(DATA *ll);

#endif
