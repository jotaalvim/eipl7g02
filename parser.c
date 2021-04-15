#include "parser.h"
#include <string.h>



void parse(char *line, STACK *s) {
    char *delims = " \t\n";
    for(char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra;
        int val_i = strtol(token, &sobra, 10);
        int temp = 1;
        if(strlen(sobra) == 0) {

            DATA z;
            make_datas(z,LONG,val_i);
            push(s,z);

            temp = 0;
        }
        double val_d = strtod(token, &sobra);
        if(strlen(sobra) == 0 && temp){

            DATA k;
            make_datas(k, DOUBLE, val_d);
            push(s,k);
        }
        else if (temp)
            switch (*token) {
                case '+' :  break;
            }
    }
}
