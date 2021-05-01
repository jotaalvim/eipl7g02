/**
 @file parser.c
 @brief Ficheiro com as funções relativas às operações aritméticas e ao parser.
 */
#include "parser.h"
#include <string.h>
#include <math.h>
#include <stdio.h>


//FIXME FAZER UMA FUNÇAO ARITMÈTICA
//ter double d1,d2
//long d1, d2
//e usar o que me interessa a partir dai
void aritmetica (STACK *s, char *c) {//c é o operdor
    DATA a, da, ia, z, b, db, ib; 
    TYPE ta, tb;
    a = top(s); // a ori
    ta = a.type;
    
    trsd(s);      
    da = top(s); // a double
    trsi(s);      
    ia = top(s); // a int
    
    z = pop(s); 
      
    b = top(s); // b ori
    tb = b.type;
     
    trsd(s);      
    db = top(s); // b double
    trsi(s);      
    ib = top(s); // b int
    
    z = pop(s); 
    double daf = da.elems.DOUBLE, dbf = db.elems.DOUBLE,x2; 
    int    iaf = ia.elems.LONG,   ibf = ib.elems.LONG, x ; 
    if (tb == DOUBLE || ta == DOUBLE ){ 
        switch (*c) {
            case '+': make_datas(z,DOUBLE,daf+dbf);break;
            case '-': make_datas(z,DOUBLE,dbf-daf);break;
            case '/': make_datas(z,DOUBLE,dbf/daf);break;
            case '*': make_datas(z,DOUBLE,daf*dbf);break;
            case '%': make_datas(z,LONG,ibf%iaf);break;
            case '&': make_datas(z,LONG,iaf&ibf);break;
            case '|': make_datas(z,LONG,iaf||ibf);break;
            case '^': make_datas(z,LONG,ibf^iaf);break;
            case '#': make_datas(z,DOUBLE,pow(dbf,daf));break;
            case 'e':
                switch (*(c+1)) {
                    case '&':
                        x2 = dbf ? daf : 0 ;
                        make_datas(z,DOUBLE,x2); break;
                    case '|':
                        x2 = dbf ? dbf : daf ;
                        make_datas(z,DOUBLE,x2); break;
                    case '<':
                        x2 = dbf < daf ? dbf : daf;
                        make_datas(z,DOUBLE,x2); break;
                    case '>':
                        //printf("\n%f %f\n",dbf, daf); 
                        x2 = (dbf > daf) ? dbf : daf;
                        //printf("\n%f\n",x2); 
                        make_datas(z,DOUBLE,x2); break;
                    default : printf("sitio inesperado, '%c'",*c);break;
                }break;
            default : printf("sitio inesperado, '%c'",*c);break;
        }
    }
    else 
        switch (*c) {
            case '+': make_datas(z,LONG,iaf+ibf);break;
            case '-': make_datas(z,LONG,ibf-iaf);break;
            case '/': make_datas(z,LONG,ibf/iaf);break;
            case '*': make_datas(z,LONG,iaf*ibf);break;
            case '%': make_datas(z,LONG,ibf%iaf);break;
            case '&': make_datas(z,LONG,iaf&ibf);break;
            case '|': make_datas(z,LONG,iaf||ibf);break;
            case '^': make_datas(z,LONG,ibf^iaf);break;
            case '#': make_datas(z,DOUBLE,pow(dbf,daf));break;
            case 'e': 
                switch (*(c+1)) {
                    case '&': 
                        x = ibf ? iaf : 0 ;
                        make_datas(z,LONG,x); break;
                    case '|':
                        x = ibf ? ibf : iaf ;
                        make_datas(z,LONG,x); break;
                    case '<':
                        x = ibf < iaf ? ibf : iaf ;
                        make_datas(z,LONG,x); break;
                    case '>':
                        x = ibf > iaf ? ibf : iaf ;
                        make_datas(z,LONG,x); break;
                    default : printf("sitio inesperado, '%c'",*c);break; }break;
            default : printf("sitio inesperado, '%c'",*c);break;
    }
    push(s,z);
}


//void constantes (STACK *s, char c) {
//    DATA z;
//    
//    switch (c) {
//        case 'A' :
//            {make_datas(z,LONG,10)}; break;
//        case 'B' :
//            {make_datas(z,LONG,11)}; break;
//        case 'C' :
//            {make_datas(z,LONG,12)}; break;  
//        case 'D' :
//            {make_datas(z,LONG,13)}; break;
//        case 'E' :
//            {make_datas(z,LONG,14)}; break;
//        case 'F' :
//            {make_datas(z,LONG,15)}; break;
//        case 'N' :
//            {make_datas(z,CHAR,'\n')}; break;
//        case 'S' :
//            {make_datas(z,CHAR,' ')};break;
//        case 'X' :
//            {make_datas(z,LONG,0)}; break;
//        case 'Y' :
//            {make_datas(z,LONG,1)}; break;
//        case 'Z' :
//            {make_datas(z,LONG,2)}; break;
//        case ':' :
//            break;
//
//        default : printf("sitio inesperado, '%c'",c);break;
//    }
//    push(s,z);
//} 


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
    //FIXME DEVE EXISTIR UM DEEP COPY
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


void compara(STACK *s, char c) {
    DATA a, da, z, b, db;//ia, ib 
    TYPE ta, tb;
    int x;
    a = top(s); // a ori
    ta = a.type;

    trsd(s);      
    da = top(s); // a double
    //trsi(s);      
    //ia = top(s); // a int
    
    z = pop(s); 
      
    b = top(s); // b ori
    tb = b.type;
     
    trsd(s);      
    db = top(s); // b double
    z = pop(s); 
    //trsi(s);      
    //ib = top(s); // b int
    double daf = da.elems.DOUBLE, dbf = db.elems.DOUBLE; 
    //int    iaf = ia.elems.LONG;
    //int    ibf = ib.elems.LONG; 
    
    if (ta == STRING && tb == STRING) {
        switch( c ) {
            case '=' : 
                x = strcmp(a.elems.STRING,b.elems.STRING) == 0 ? 1: 0;
                make_datas(z,LONG,x); break;
            case '<' : 
                x = strcmp(a.elems.STRING,b.elems.STRING) < 0 ? 1: 0;
                make_datas(z,LONG,x); break;
            case '>' : 
                x = strcmp(a.elems.STRING,b.elems.STRING) > 0 ? 1: 0;
                make_datas(z,LONG,x); break;
            default : printf("sitio inesperado, '%c'",c);break;
        }
    } 
    else {
        switch( c ) {
            case '=' :
                x = dbf == daf ? 1: 0;
                make_datas(z,LONG,x); break;
            case '<' :
                x = dbf < daf ? 1: 0;
                make_datas(z,LONG,x); break;
            case '>' : 
                x = dbf > daf ? 1: 0;
                make_datas(z,LONG,x); break;
            default : printf("sitio inesperado, '%c'",c);break;
        }
    } 
    push(s,z);
}

//void igual(STACK *s) {
//    trsd(s);
//    DATA a = pop(s);
//    trsd(s);
//    DATA b = pop(s);
//    double va = a.elems.DOUBLE;
//    double vb = b.elems.DOUBLE;
//    DATA z;
//    if (va == vb) { 
//        make_datas(z,LONG, 1);
//    }
//    else {
//        make_datas(z,LONG, 0);
//    }
//    push(s,z);
//    //FIXME 
//}
//
//void menor (STACK *s) {
//    trsd(s);
//    DATA a = pop(s);
//    trsd(s);
//    DATA b = pop(s);
//    make_datas(a,LONG,(int) (a.elems.DOUBLE<b.elems.DOUBLE));
//    push(s,a);
//}
//
//void maior (STACK *s) {
//    trsd(s);
//    DATA a = pop(s);
//    trsd(s);
//    DATA b = pop(s);
//    make_datas(a,LONG,(int)( a.elems.DOUBLE>b.elems.DOUBLE));
//    push(s,a);
//}

void nao (STACK *s) {
    trsd(s);
    DATA a = pop(s);
    make_datas(a,LONG,! a.elems.LONG);
    push(s,a);
}

void ee (STACK *s) {
    trsd(s);
    DATA a = pop(s);
    trsd(s);
    DATA b = pop(s);
    if (!b.elems.DOUBLE) {make_datas(a,DOUBLE,0);}
    push(s,a);
}

void emenor (STACK *s) {
    DATA a = pop(s);
    TYPE ta = a.type;
    DATA b = pop(s);
    TYPE tb = b.type;
    if (ta == STRING && tb == STRING) 
        strcmp(a.elems.STRING,b.elems.STRING) < 0 ? push(s,a) : push(s,b);
    else 
    if (ta == LONG && tb == LONG)
        a.elems.LONG > b.elems.LONG ? push(s,a) : push(s,b);
}

void guardavar (STACK *s, char c, DATA ll[]) {
    DATA a = top(s);
    ll[c-'A'] = a;
}

void ifthenelse(STACK *s) {
    DATA a,b,c;
    a = pop(s);
    b = pop(s);
    c = pop(s);
    if (c.elems.LONG) 
        push(s,b);
    else 
        push(s,a);
}


void initVetor(DATA *ll) {
    make_datas(ll[0],LONG,10);
    make_datas(ll[1],LONG,11); 
    make_datas(ll[2],LONG,12); 
    make_datas(ll[3],LONG,13); 
    make_datas(ll[4],LONG,14); 
    make_datas(ll[5],LONG,15); 
    make_datas(ll[13],CHAR,'\n'); 
    make_datas(ll[18],CHAR,' ');
    make_datas(ll[23],LONG,0); 
    make_datas(ll[24],LONG,1); 
    make_datas(ll[25],LONG,2); 
}

/**
 * \brief      Função que divide uma dada string usando delimitadores, separando os números dos operadores.
 *             É comparado o token com todos os possiveis operadores aritméticos, sendo chamada a função correspondente ao operador dado.
 *
 * @param line A linha que foi lida e à qual se irá aplicar o parse
 * @param s    Stack
 */
void parse(char *line, STACK *stack) {
    char *delims = " \t\n";
    DATA ll[26];
    initVetor(ll);
    for(char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra;
        int val_i = strtol(token, &sobra, 10);
        int temp = 1;
        if(strlen(sobra) == 0) {
            DATA z;
            make_datas(z,LONG,val_i);
            push(stack,z);
            temp = 0;
        }
        double val_d = strtod(token, &sobra);
        if(strlen(sobra) == 0 && temp){
            DATA k;
            make_datas(k, DOUBLE, val_d);
            push(stack,k);
        }
        else if (temp) {
            if (strchr("+-/*^%#&|e",*token)) {
                aritmetica(stack,token); 
            }   
            else
            if (*token >= 'A' && *token <= 'Z') {//FIXME FALTA COISA 
                push(stack,ll[*token-'A']);
                //constantes(stack,*token); 
            }
            else
            if (strchr("<>=",*token)) {
                compara(stack,*token); 
            }
            else
            switch (*token) {
                case '(' : parA(stack); break;
                case ')' : parF(stack); break;
                case '~' : not(stack);  break;
                case '@' : arr(stack);  break;
                case '\\': stop(stack); break;
                case ';' : pop(stack);  break;
                case '_' : und(stack);  break;
                case '$' : tpi(stack);  break;
                case 'l' : lei(stack);  break;
                case 'c' : trsc(stack); break;
                case 'i' : trsi(stack); break;
                case 'f' : trsd(stack); break;
                case ':' : guardavar(stack,*(token+1),ll); break;
				case '!' : nao(stack);  break;
                case '?' : ifthenelse(stack); break;
                default : printf("sitio inesperado fim parse '%c'", *token);break;
            }
        }
    }
}
