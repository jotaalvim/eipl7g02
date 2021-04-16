#include "parser.h"
#include <string.h>
#include <math.h>

void soma(STACK *s) {
    DATA p = pop(s);
    TYPE tp = p.type;
    DATA sg = pop(s);
    TYPE ts = sg.type;          
    if (tp == LONG && ts == LONG){
        DATA z;
        make_datas(z, LONG, p.elems.LONG + sg.elems.LONG);
        push(s,z);}
    else if (tp == DOUBLE && ts == LONG){
        DATA z;
        make_datas(z, DOUBLE, p.elems.DOUBLE + sg.elems.LONG);
        push(s,z);}
    else if (tp == LONG && ts == DOUBLE){
        DATA z;
        make_datas(z, DOUBLE, p.elems.LONG + sg.elems.DOUBLE);
        push(s,z);}
    else if (tp == DOUBLE && ts == DOUBLE){
        DATA z;
        make_datas(z, DOUBLE, p.elems.DOUBLE + sg.elems.DOUBLE);
        push(s,z);}
}


void sub(STACK *s){
    DATA p = pop(s);
    TYPE tp = p.type;
    DATA sg = pop(s);
    TYPE ts = sg.type;
    if (tp==LONG&&ts==LONG){DATA z;
        make_datas(z,LONG,p.elems.LONG-sg.elems.LONG);
        push(s,z);}
    else if (tp==DOUBLE&&ts==LONG){
        DATA z;
        make_datas(z,DOUBLE,p.elems.DOUBLE-sg.elems.LONG);
        push(s,z);}
    else if (tp == LONG && ts == DOUBLE){
        DATA z;
        make_datas(z,DOUBLE,p.elems.LONG-sg.elems.DOUBLE);
        push(s,z);}
    else if (tp==DOUBLE&&ts==DOUBLE){
        DATA z;
        make_datas(z,DOUBLE,p.elems.DOUBLE-sg.elems.DOUBLE);
        push(s,z);}
} 

void divi(STACK *s) {
    DATA p = pop(s);
    TYPE tp = p.type;
    DATA sg = pop(s);
    TYPE ts = sg.type;
    if (tp == LONG && ts == LONG){
        DATA z;
        make_datas(z, LONG, p.elems.LONG/sg.elems.LONG);
        push(s,z);}
    else if (tp == DOUBLE && ts == LONG){
        DATA z;
        make_datas(z, DOUBLE, p.elems.DOUBLE/sg.elems.LONG);
        push(s,z);}
    else if (tp==LONG&&ts==DOUBLE){
        DATA z;
        make_datas(z, DOUBLE, p.elems.LONG/sg.elems.DOUBLE);
        push(s,z);}
    else if (tp == DOUBLE && ts == DOUBLE){
        DATA z;
        make_datas(z, DOUBLE, p.elems.DOUBLE/sg.elems.DOUBLE);
        push(s,z);}
} 
void mult(STACK *s) {
    DATA p = pop(s);
    TYPE tp = p.type;
    DATA sg = pop(s);
    TYPE ts = sg.type;
    if (tp==LONG&&ts==LONG){DATA z;
        make_datas(z,LONG,p.elems.LONG*sg.elems.LONG);
        push(s,z);}
    else if (tp==DOUBLE&&ts==LONG){
        DATA z;
        make_datas(z,DOUBLE,p.elems.DOUBLE*sg.elems.LONG);
        push(s,z);}
    else if (tp == LONG && ts == DOUBLE){
        DATA z;
        make_datas(z,DOUBLE,p.elems.LONG*sg.elems.DOUBLE);
        push(s,z);}
    else if (tp==DOUBLE&&ts==DOUBLE){
        DATA z;
        make_datas(z,DOUBLE,p.elems.DOUBLE*sg.elems.DOUBLE);
        push(s,z);}
}
void parA(STACK *s) {
    DATA p = pop(s);
    TYPE tp = p.type;
    if (tp == LONG) {
        DATA z;
        make_datas(z,LONG,p.elems.LONG-1);
        push(s,z);}
    else if (tp == DOUBLE) {
        DATA k;
        make_datas(k,DOUBLE,p.elems.DOUBLE-1);
        push(s,k);}
    else if (tp == CHAR) {
        DATA q;
        make_datas(q,CHAR,p.elems.CHAR-1);
        push(s,q);
    }
}
void parF(STACK *s) {
    DATA p = pop(s);
    TYPE tp = p.type;
    if (tp == LONG) {
        DATA z;
        make_datas(z,LONG,p.elems.LONG+1);
        push(s,z);}
    else if (tp == DOUBLE) {
        DATA k;
        make_datas(k,DOUBLE,p.elems.DOUBLE+1);
        push(s,k);}
    else if (tp == CHAR) {
        DATA q;
        make_datas(q,CHAR,p.elems.CHAR+1);
        push(s,q);
    }
}

void mod(STACK *s) { // FIXME NÂO FUNCIONA
    DATA p = pop(s);
    DATA z = pop(s);
    DATA k;
    make_datas(k,CHAR,p.elems.LONG % z.elems.LONG );
    push(s,k);
}

void expo(STACK *s) {
    DATA p = pop(s);
    TYPE tp = p.type;
    DATA sg = pop(s);
    TYPE ts = sg.type;
    if (tp==LONG&&ts==LONG){DATA z;
        make_datas(z,LONG,pow(sg.elems.LONG,p.elems.LONG));
        push(s,z);}
    else if (tp==DOUBLE&&ts==LONG){
        DATA z;
        make_datas(z,DOUBLE,pow(sg.elems.LONG,p.elems.DOUBLE));
        push(s,z);}
    else if (tp == LONG && ts == DOUBLE){
        DATA z;
        make_datas(z,DOUBLE,pow(sg.elems.DOUBLE,p.elems.LONG));
        push(s,z);}
    else if (tp==DOUBLE&&ts==DOUBLE){
        DATA z;
        make_datas(z,DOUBLE,pow(sg.elems.DOUBLE,p.elems.DOUBLE));
        push(s,z);}
}

void con(STACK *s) {
    DATA p = pop(s);
    DATA sg = pop(s);
    DATA z;
    make_datas(z,LONG,p.elems.LONG & sg.elems.LONG)
    push(s,z);
}

void dis(STACK *s) {
    DATA p = pop(s);
    DATA sg = pop(s);
    DATA z;
    make_datas(z,LONG,p.elems.LONG || sg.elems.LONG)
    push(s,z);
}

void xor(STACK *s) {
    DATA p = pop(s);
    DATA sg = pop(s);
    DATA z;
    make_datas(z,LONG,p.elems.LONG ^ sg.elems.LONG)
    push(s,z);
}

void not(STACK *s) {
    DATA p = pop(s);
    DATA z;
    make_datas(z,LONG,~p.elems.LONG)
    push(s,z);
}

void arr(STACK *s) {
    DATA p = pop(s);
    push(s,z);
    DATA p = pop(s);
    DATA z;

    push(s,z);
    DATA p = pop(s);
    DATA z;

    push(s,z);
    DATA p = pop(s);
    DATA z;

    push(s,z);
    DATA p = pop(s);
    DATA z;

    push(s,z);
}
void parse(char *line, STACK *string) {
    char *delims = " \t\n";
    for(char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra;
        int val_i = strtol(token, &sobra, 10);
        int temp = 1;
        if(strlen(sobra) == 0) {

            DATA z;
            make_datas(z,LONG,val_i);
            push(string,z);

            temp = 0;
        }
        double val_d = strtod(token, &sobra);
        if(strlen(sobra) == 0 && temp){

            DATA k;
            make_datas(k, DOUBLE, val_d);
            push(string,k);
        }
        else if (temp)
            switch (*token) {
                case '+' :
                    soma(string); break;
                case '-' :
                    sub(string); break;
                case  '/':
                     divi(string); break;
                case '*' :
                    mult(string); break;
                case '(' :
                    parA(string); break;
                case ')' :
                    parF(string); break;
                case '%' :
                    mod(string); break;
                case '#' :
                    expo(string); break;
                case '&' :
                    con(string); break;
                case '|' :
                    dis(string); break;
                case '^' :
                    xor(string); break;
                case '~' :
                    not(string); break;
                case '@' :
                    arr(string); break;
                //case ';' : 
                //    pop(s); break;
                //case '_' :
                //    und(s); break;
                //case '\\' :
                //    switchtop(s); break;
                //case '$' :
                //    tpindex(s); break;
                //case 'l' :
                //    leitura(s); break;
                //case 'c' : 
                //    trschar(s); break;
                //case 'i' :
                //    trsint(s); break;
                //case 'f' :
                //    trsdouble(s); break;
                //default : break;
            }
    }
}
