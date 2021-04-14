/**
 * @file Ficheiro no qual se encontram as funções referentes ao parser.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "parser.h"


int stack[10240];
int count = -1;




/**
 * \brief Função que fará o parse de uma linha.
 *
 * Esta função faz o parse de uma dada linha e, dependendo do input, realiza diferentes operações.
 *
 * @param line Linha a que faremos parse.
 *
 */
void parse(char *line) {
    //int Y = *stack;
    //int X = *stack;

    char *delims = " \t\n";
    for(char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {

        char *sobra;
        //char *val_i = token;
        long val_i = strtol(token, &sobra, 10);
        int temp = 1;

        if(strlen(sobra)) {
            push(s, LONG, val_i);
            temp = 0;
        }
        double val_d = strtod(token, &sobra);
        if(strlen(sobra) == 0 && temp)
            push(s, DOUBLE, val_d);

        switch (token[0]) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '(':
            case '#':
            case '&':
            case '|':
            case '^':
            case '~':
        }
    }

    print(count);
}

/**
 * \brief Função auxiliar que nos permite adicionar um elemento à stack.
 *
 *
 * @param x É o elemento que será adicionado à stack.
 */

/**
 * \brief Função auxiliar que nos permite retirar o último elemento da stack.
 *
 *
 * @returns res Último elemento da stack.
 */

/**
 * \brief Função utilizada para imprimir a stack.
 *
 *
 * @param x É o tamanho da stack a ser imprimida.
 */
void print(int x) {
    int y = 0;
    while (y<=x) {
        printf("%d",stack[y]);
        y++;
    }
printf("\n");
}


// pow
