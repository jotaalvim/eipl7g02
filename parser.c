#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "parser.h"


int stack[10240];
int count = -1;







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
            push(Y-1);
        }
        else if(strcmp(token,")") == 0) {
            int Y = pop();
            push(Y+1);
        }
        else if(strcmp(token,"%") == 0) {
            int Y = pop();
            int X = pop();
            push(X % Y);
        }
        else if(strcmp(token,"#") == 0) {
            int Y = pop();
            int X = pop();
            int a,b=1;
            for (a=0;a<Y;a++){
                b=b*X;
            };
            push(b);
        }
        else if(strcmp(token,"&") == 0) {
            int Y = pop();
            int X = pop();
            push( X & Y);
        }
        else if(strcmp(token,"|") == 0) {
            int Y = pop();
            int X = pop();
            push(X | Y);
        }
        else if(strcmp(token,"^") == 0) {
            int Y = pop();
            int X = pop();
            push( X ^ Y);
            //push( (X & ~Y) | (~X & Y));
        }
        else if(strcmp(token,"~") == 0) {
            int Y = pop();
            push( ~Y );
        }
        
    }

    print(count);
}


void push(int x) {
    count++;
    stack[count] = x;
}


int pop() {
    int res = stack[count];
    count--;
    return res;
}


void print(int x) {
    int y = 0;
    while (y<=x) {
        printf("%d",stack[y]);
        y++;
    }
printf("\n");
}


// pow
