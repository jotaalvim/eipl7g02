#include "parser.h"
#include <string.h>
#include <math.h>
#include <stdio.h>

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
        make_datas(z,LONG,-p.elems.LONG+sg.elems.LONG);
        push(s,z);}
    else if (tp==DOUBLE&&ts==LONG){
        DATA z;
        make_datas(z,DOUBLE,-p.elems.DOUBLE+sg.elems.LONG);
        push(s,z);}
    else if (tp == LONG && ts == DOUBLE){
        DATA z;
        make_datas(z,DOUBLE,-p.elems.LONG+sg.elems.DOUBLE);
        push(s,z);}
    else if (tp==DOUBLE&&ts==DOUBLE){
        DATA z;
        make_datas(z,DOUBLE,-p.elems.DOUBLE+sg.elems.DOUBLE);
        push(s,z);}
} 

void divi(STACK *s) {
    DATA p = pop(s);
    TYPE tp = p.type;
    DATA sg = pop(s);
    TYPE ts = sg.type;
    if (tp == LONG && ts == LONG){
        DATA z;
        make_datas(z, LONG, sg.elems.LONG/p.elems.LONG);
        push(s,z);}
    else if (tp == DOUBLE && ts == LONG){
        DATA z;
        make_datas(z, DOUBLE, sg.elems.LONG/p.elems.DOUBLE);
        push(s,z);}
    else if (tp==LONG&&ts==DOUBLE){
        DATA z;
        make_datas(z, DOUBLE, sg.elems.DOUBLE/p.elems.LONG);
        push(s,z);}
    else if (tp == DOUBLE && ts == DOUBLE){
        DATA z;
        make_datas(z, DOUBLE, sg.elems.DOUBLE/p.elems.DOUBLE);
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

void mod(STACK *s) {
    DATA p = pop(s);
    DATA z = pop(s);
    DATA k;
    make_datas(k,CHAR,p.elems.LONG % z.elems.LONG );
    push(s,k);
}

void expo (STACK *s) {
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
    DATA a = pop(s);
    DATA b = pop(s);
    DATA c = pop(s);
    push(s,b);
    push(s,a);
    push(s,c);
}

void stop(STACK *s) {
    DATA a = pop(s);
    DATA b = pop(s);
    push(s,a);
    push(s,b);
}

void und(STACK *s) {
    DATA a = pop(s);
    push(s,a);
    push(s,a);
}



//void tpindex (STACK *s) {
//    DATA a = pop(s);
//    TYPE ta = a.type;
//    if (ta == LONG) {
//        DATA z;
//        make_datas(z,LONG,s->p.elems.LONG);
//        //s->p[(s->size)-1-v_n.l].valor.l
//        push(s,z);
//    } else
//    if (ta == DOUBLE) {
//        
//    } else
//    if (ta == CHAR) {
//        
//    } else 
//    if (ta == STRING) {
//        
//    }
//}

void lei (STACK*s){
    char x[256];
    assert(scanf("\n%100[^\n]", x) == 1);
    DATA z;
    make_datas(z,STRING,x)
    push(s,z);
}

void trsc (STACK*s){
    DATA a = pop(s);
    TYPE ta= a.type;
    if (ta == LONG) {
        DATA z;
        make_datas(z,CHAR,(char)a.elems.LONG);
        push(s,z);}
    else if (ta == DOUBLE) {
        DATA k;
        make_datas(k,CHAR,(char) a.elems.DOUBLE);
        push(s,k);}
    else if (ta == CHAR) {
        DATA q;
        make_datas(q,CHAR,a.elems.CHAR);
        push(s,q);
    }
}

void trsi (STACK*s){
    DATA a = pop(s);
    TYPE ta= a.type;
    if (ta == LONG) {
        DATA z;
        make_datas(z,LONG,a.elems.LONG);
        push(s,z);}
    else if (ta == DOUBLE) {
        DATA k;
        make_datas(k,LONG,(int) a.elems.DOUBLE);
        push(s,k);}
    else if (ta == CHAR) {
        DATA q;
        make_datas(q,LONG,(int)a.elems.CHAR);
        push(s,q);
    }
    else if (ta == STRING) {
        DATA q;
        make_datas(q,LONG,atoi(a.elems.STRING));
        push(s,q);
    }
}

void trsd (STACK*s){
    DATA a = pop(s);
    TYPE ta= a.type;
    if (ta == LONG) {
        DATA z;
        make_datas(z,DOUBLE,(double)a.elems.LONG);
        push(s,z);}
    else if (ta == DOUBLE) {
        DATA k;
        make_datas(k,DOUBLE,a.elems.DOUBLE);
        push(s,k);}
    else if (ta == CHAR) {
        DATA q;
        make_datas(q,DOUBLE,(double)a.elems.CHAR);
        push(s,q);
    }
    else if (ta == STRING) {
        DATA q;
        make_datas(q,DOUBLE,atof(a.elems.STRING));
        push(s,q);
    }
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
                case '\\' :
                    stop(string); break;
                case ';' :
                    pop(string); break;
                case '_' :
                    und(string); break;
                //case '$' :
                //    tpindex(string); break;
                
                case 'l' :
                    lei(string); break;
                case 'c' :
                    trsc(string); break;
                case 'i' :
                    trsi(string); break;
                case 'f' :
                    trsd(string); break;
                //default : break;
            }
    }
}
