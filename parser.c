#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

void parse(char *line) {

    char *delims = " \t\n";

    for(char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra;
        long val_i = strtol(token, &sobra, 10);
        if(strlen(sobra) == 0) {
            push(val_i);
        } else if(strcmp(token, "+") == 0) {
            int Y = pop();
            int X = pop();
            push(X + Y);
        }
          else if(strcmp(token, "-") == 0) {
            int Y = pop();
            int X = pop();
            push(X - Y); 
        }
          else if(strcmp(token, "*") == 0) {
            int Y = pop();
            int X = pop();
            push(X * Y);
        }
          else if(strcmp(token, "/") == 0) {
            int Y = pop();
            int X = pop();
            push(X / Y);    
        }
        else if(strcmp(token,"(") == 0) {
            int Y = pop();
            push(Y--);
        }
        else if(strcmp(token,")") == 0) {
            int Y = pop();
            push(Y++);
        }
        else if(strcmp(token,"%") == 0) {
            int Y = pop();
            push(abs(Y));
        }
        else if(strcmp(token,"#") == 0) {
            int Y = pop();
            int X = pop();
            push(pow(Y,X));
        }
        else if(strcmp(toke n,"&") == 0) {
            int Y = pop();
            int X = pop();
            push(X&&Y);
        }
        else if(strcmp(toke n,"|") == 0) {
            int Y = pop();
            int X = pop();
            push(X||Y);
        }
        else if(strcmp(toke n,"^") == 0) {
            int Y = pop();
            int X = pop();
            push( (X&&!Y) || (!X&&Y));
        }
        else if(strcmp(toke n,"~") == 0) {
            int Y = pop();
            push(!Y);
        }
        // 
    }
}
