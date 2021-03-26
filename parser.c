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
    int Y = *stack;
    int X = *stack;

    char *delims = " \t\n";
    for(char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {

        char *sobra;
        long val_i = strtol(token, &sobra, 10);
        if(strlen(sobra) == 0) {
            push(val_i);
        }
        switch (token[0]) {
            case '+':
                Y = pop();
                X = pop();
                 push(X + Y);
                break;
            case '-':
                Y = pop();
                X = pop();
                push(X - Y); 
                break;
            case '*':
                Y = pop();
                X = pop();
                push(X * Y);
                break;
            case '/':
                Y = pop();
                X = pop();
                push(X / Y);    
                break;
            case '(':
                Y = pop();
                push(Y-1);
                break;
            case ')':
                Y = pop();
                push(Y+1);
                break;
            case '%':
                Y = pop();
                X = pop();
                push(X % Y);
                break;
            case '#':
                Y = pop();
                X = pop();
                int a,b=1;
                for (a=0;a<Y;a++){
                    b=b*X;
                }
                push(b);
                break;
            case '&':
                Y = pop();
                X = pop();
                push( X & Y);
                break;
            case '|':
                Y = pop();
                X = pop();
                push(X | Y);
                break;
            case '^':
                Y = pop();
                X = pop();
                push( X ^ Y);
                break;
            //push( (X & ~Y) | (~X & Y));
            case '~':
                Y = pop();
                push( ~Y );
                break;
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
void push(int x) {
    count++;
    stack[count] = x;
}

/**
 * \brief Função auxiliar que nos permite retirar o último elemento da stack.
 *
 *
 * @returns res Último elemento da stack.
 */
int pop() {
    int res = stack[count];
    count--;
    return res;
}

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
