/**
 @file parser.c
 @brief Ficheiro com as funções relativas às operações aritméticas e ao parser.
 */


#include "parser.h"
#include <string.h>
#include <math.h>
#include <stdio.h>


/**
 * \brief Função que soma os 2 elementos do topo da Stack.
 * @param s Stack
 */
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

/**
 * \brief Função que subtrai os 2 primeiros elementos do topo da Stack.
 * @param s Stack
 */
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


/**
 * \brief Função que divide os 2 primeiros elementos da Stack.
 * @param s Stack
 */
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


/**
 * \brief Função que multiplica os 2 primeiros elementos do topo da Stack.
 * @param s Stack
 */
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


/**
 * \brief Função que decrementa 1 valor ao elemento do topo da Stack.
 * @param s Stack
 */
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

/**
 * \brief Função que incrementa 1 valor ao elemento do topo da Stack.
 * @param s Stack
 */
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

/**
 * \brief Função que devolve o resto da divisão inteira dos 2 primeiro elementos da Stack.
 * @param s Stack
 */
void mod(STACK *s) {
    DATA p = pop(s);
    DATA z = pop(s);
    DATA k;
    make_datas(k,LONG,z.elems.LONG % p.elems.LONG );
    push(s,k);
}

/**
 * \brief Função que calcula a potência dos 2 primeiros elementos do topo da Stack.
 * @param s Stack
 */
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

/**
 * \brief Operador bitwise em que cada bit é comparado e é retornado o valor 1 quando ambos os bits forem 1 e 0 caso contrário.
 * @param s Stack
 */
void con(STACK *s) {
    DATA p = pop(s);
    DATA sg = pop(s);
    DATA z;
    make_datas(z,LONG,p.elems.LONG & sg.elems.LONG)
    push(s,z);
}

/**
* \brief Operador bitwise em que cada bit é comparado e é retornado o valor 1 quando um dos bits for 1 e 0 caso contrário.
* @param s Stack
*/
void dis(STACK *s) {
    DATA p = pop(s);
    DATA sg = pop(s);
    DATA z;
    make_datas(z,LONG,p.elems.LONG || sg.elems.LONG)
    push(s,z);
}

/**
* \brief Operador bitwise em que cada bit é comparado e é retornado o valor 1 quando os bits comparados são diferentes e 0 caso contrário.
* @param s Stack
*/
void xor(STACK *s) {
    DATA p = pop(s);
    DATA sg = pop(s);
    DATA z;
    make_datas(z,LONG,p.elems.LONG ^ sg.elems.LONG)
    push(s,z);
}

/**
* \brief Operador bitwise em que cada bit é comparado e é retornado o valor representado em Complemento2.
* @param s Stack
*/
void not(STACK *s) {
    DATA p = pop(s);
    DATA z;
    make_datas(z,LONG,~p.elems.LONG)
    push(s,z);
}

/**
* \brief Função que troca os três elementos do topo da Stack entre si.
* @param s Stack
*/
void arr(STACK *s) {
    DATA a = pop(s);
    DATA b = pop(s);
    DATA c = pop(s);
    push(s,b);
    push(s,a);
    push(s,c);
}

/**
 * \brief Função que troca os dois elementos do topo da Stack.
 * @param s Stack
 */
void stop(STACK *s) {
    DATA a = pop(s);
    DATA b = pop(s);
    push(s,a);
    push(s,b);
}


/**
 * \brief Função que duplica o elemento do topo da Stack.
 * @param s Stack
 */
void und(STACK *s) {
    DATA a = pop(s);
    push(s,a);
    push(s,a);
}



void tpi (STACK *s) {
    DATA a = pop(s);
    TYPE ta = a.type;
    DATA z;
    int n=s->n_elems;
    if(ta == LONG ) {
        z = s->stack[n-a.elems.LONG-1];
        push(s, z);
    }
    else if (ta == DOUBLE ) {
        z = s->stack[n-(int)a.elems.DOUBLE-1];
        push(s, z);
    }
    else if (ta == CHAR) {
        z =s->stack[n - a.elems.CHAR-1];
        push(s, z);
    }
}


/**
* \brief Função que lê uma linha.
* @param s Stack
*/
void lei (STACK*s){
    char x[256];
    assert(scanf("\n%100[^\n]", x) == 1);
    DATA z;
    make_datas(z,STRING,x)
    push(s,z);
}

/**
* \brief Função que converte o elemento no topo da Stack num Char.
* @param s Stack 
*/
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

/**
* \brief Função que converte o elemento no topo da Stack num Inteiro.
* @param s Stack 
*/
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
        make_datas(q,LONG,(int) a.elems.CHAR);
        push(s,q);
    }
    else if (ta == STRING) {
        DATA q;
        make_datas(q,LONG,atoi(a.elems.STRING));
        push(s,q);
    }
}

/**
* \brief Função que converte o elemento no topo da Stack num Double.
* @param s Stack 
*/
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

void a(STACK *s) {
    DATA z;
    make_datas(z,LONG,10);
    push(s,z);
}


void b(STACK *s) {
    DATA z;
    make_datas(z,LONG,11);
    push(s,z);
}

void c(STACK *s) {
    DATA z;
    make_datas(z,LONG,12);
    push(s,z);
}

void d(STACK *s) {
    DATA z;
    make_datas(z,LONG,13);
    push(s,z);
}

void e(STACK *s) {
    DATA z;
    make_datas(z,LONG,14);
    push(s,z);
}

void f(STACK *s) {
    DATA z;
    make_datas(z,LONG,15);
    push(s,z);
}

void n(STACK *s) {
    DATA z;
    make_datas(z,CHAR,'\n');
    push(s,z);
}

void s(STACK *st) {
    DATA z;
    make_datas(z,CHAR,' ');
    push(st,z);
}

void x(STACK *s) {
    DATA z;
    make_datas(z,LONG,0);
    push(s,z);
}

void y(STACK *s) {
    DATA z;
    make_datas(z,LONG,1);
    push(s,z);
}

void z(STACK *s) {
    DATA k;
    make_datas(k,LONG,2);
    push(s,k);
}

void igual(STACK *s) {
    trsd(s);
    DATA a = pop(s);
    trsd(s);
    DATA b = pop(s);
    make_datas(a,LONG,(int) a.elems.LONG==b.elems.LONG);
    push(s,a);
}

void menor (STACK *s) {
    trsd(s);
    DATA a = pop(s);
    trsd(s);
    DATA b = pop(s);
    make_datas(a,LONG,(int) (a.elems.DOUBLE<b.elems.DOUBLE));
    push(s,a);
}

void maior (STACK *s) {
    trsd(s);
    DATA a = pop(s);
    trsd(s);
    DATA b = pop(s);
    make_datas(a,LONG,(int)( a.elems.DOUBLE>b.elems.DOUBLE));
    push(s,a);
}

void nao (STACK *s) {
    trsd(s);
    DATA a = pop(s);
    make_datas(a,LONG,! a.elems.LONG);
    push(s,a);
}

void maior (STACK *s) {
    DATA a = pop(s);
    DATA b = pop(s);
    make_datas(a,LONG,(int)( a.elems.DOUBLE>b.elems.DOUBLE));
    push(s,a);
}

/**
 * \brief      Função que divide uma dada string usando delimitadores, separando os números dos operadores.
 *             É comparado o token com todos os possiveis operadores aritméticos, sendo chamada a função correspondente ao operador dado.
 *
 * @param line A linha que foi lida e à qual se irá aplicar o parse
 * @param s    Stack
 */
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
                case '$' :
                    tpi(string); break;
                case 'l' :
                    lei(string); break;
                case 'c' :
                    trsc(string); break;
                case 'i' :
                    trsi(string); break;
                case 'f' :
                    trsd(string); break;
                
                case 'A' :
                    a(string); break;
                case 'B' :
                    b(string); break;
                case 'C' :
                    c(string); break;
                case 'D' :
                    d(string); break;
                case 'E' :
                    e(string); break;
                case 'F' :
                    f(string); break;
                case 'N' :
                    n(string); break;
                case 'S' :
                    s(string); break;
                case 'X' :
                    x(string); break;
                case 'Y' :
                    y(string); break;
                case 'Z' :
                    z(string); break;
                
                case '=' :
                    igual(string); break;
                case '<' :
                    menor(string); break;
                case '>' :
                    maior(string); break;
				case '!' :
                    nao(string); break;
                default : break;
            }
    }
}
