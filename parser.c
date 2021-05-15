/*
 @file parser.c
 @brief Ficheiro com as funções relativas ao parser.
*/


#define _GNU_SOURCE
#include <string.h>
#include <math.h>
#include <stdio.h>

#include "arit.h"
#include "parser.h"


/**
 * \brief Função que decrementa 1 valor ao elemento do topo da Stack. Caso seja um array/string o primeiro elemento é colocado no topo da Stack.
 * @param s Stack
 */
void parA(STACK *s) {
    char c;
    DATA p = pop(s);
    TYPE tp = p.type;
    switch (tp) {
        case LONG:   make_datas(p,LONG  ,p.elems.LONG-1  ); break;
        case DOUBLE: make_datas(p,DOUBLE,p.elems.DOUBLE-1); break;
        case CHAR:   make_datas(p,CHAR  ,p.elems.CHAR-1  ); break;
        case STRING: 
            c = p.elems.STRING[0];
            p.elems.STRING++;
            push(s,p);
            make_datas(p,CHAR,c);
            break;
        case ARRAY: break; //FIXME
    }

    push(s,p);
}

/**
 * \brief Função que incrementa 1 valor ao elemento do topo da Stack. Caso seja um array/string o último elemento é colocado no topo da Stack.
 * @param s Stack
 */
void parF(STACK *s) {
    DATA p = pop(s), fim;
    TYPE tp = p.type;
    char c;
    switch (tp) {
        case LONG:   make_datas(p,LONG  ,p.elems.LONG+1  ); break;
        case DOUBLE: make_datas(p,DOUBLE,p.elems.DOUBLE+1); break;
        case CHAR:   make_datas(p,CHAR  ,p.elems.CHAR+1  ); break;
        case STRING:
            c = p.elems.STRING [ strlen(p.elems.STRING) +1];
            p.elems.STRING [ strlen(p.elems.STRING) -1] = '\0';
            push(s,p);
            make_datas(p,CHAR,c);break;
        case ARRAY: //FIXME
            fim = pop(p.elems.ARRAY);
            p.elems.ARRAY->n_elems--;
            push(s,p);
            push(s,fim);
            return;
    }

    push(s,p);
}

/**
 * \brief Função bitwise que incrementa e troca o sinal do elemento no topo da stack. Caso seja um array/string todos os seus elementos são colocados na Stack.
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
    //FIXME DEVE EXISTIR UM DEEP COPY
}


/**
 * \brief Função que copia o n-ésimo elemento (definido pelo elemento que se encontra no topo da stack) para o topo da Stack.
 * @param s Stack
 */
void tpi (STACK *s) {
    DATA a = pop(s);
    TYPE ta = a.type;
    DATA z;
    int n=s->n_elems;
    switch (ta) {
        case LONG: z = s->stack[n-a.elems.LONG-1]; break;
        case DOUBLE: z = s->stack[n-(int)a.elems.DOUBLE-1]; break;
        case CHAR: z = s->stack[n-a.elems.CHAR-1]; break;
        default: break;
    }

    push(s, z);
}


/**
* \brief Função que lê uma linha.
* @param s Stack
*/
void lei (STACK *s){
    char x[256];
    //assert(scanf("\n%100[^\n]", x) == 1);
    assert(fgets(x,256, stdin) != NULL );
    //x [strlen(x)-1]= '\0';
    //printf("%s\n",x);
    DATA z;
    make_datas(z,STRING,strdup(x))
    push(s,z);
}

/**
* \brief Função que converte o elemento no topo da Stack num Char.
* @param s Stack 
*/
void trsc (STACK*s){
    DATA a = pop(s);
    TYPE ta= a.type;
    switch (ta) {
        case LONG:   make_datas(a,CHAR,(char)a.elems.LONG  ); break;
        case DOUBLE: make_datas(a,CHAR,(char)a.elems.DOUBLE); break;
        case CHAR:   make_datas(a,CHAR, a.elems.CHAR       ); break;
        default  : break;
    }

    push(s,a);
}

/**
* \brief Função que converte o elemento no topo da Stack num Inteiro.
* @param s Stack 
*/
void trsi (STACK*s){
    DATA a = pop(s);
    TYPE ta= a.type;

    if (ta == LONG) {
        make_datas(a,LONG,a.elems.LONG);
        push(s,a);}
    else if (ta == DOUBLE) {
        make_datas(a,LONG,(int) a.elems.DOUBLE);
        push(s,a);}
    else if (ta == CHAR) {
        make_datas(a,LONG,(int) a.elems.CHAR);
        push(s,a); }
    else if (ta == STRING) {
        char *sobra;
        make_datas(a,LONG, strtol(a.elems.STRING,&sobra,10));
    push(s,a); }
}

/**
* \brief Função que converte o elemento no topo da Stack num Double.
* @param s Stack 
*/
void trsd (STACK*s){
    DATA a = pop(s);
    TYPE ta= a.type;
    if (ta == LONG) {
        make_datas(a,DOUBLE,(double)a.elems.LONG); }
    else if (ta == DOUBLE) {
        make_datas(a,DOUBLE,a.elems.DOUBLE); }
    else if (ta == CHAR) {
        make_datas(a,DOUBLE,(double)a.elems.CHAR); }
    else if (ta == STRING) {
        make_datas(a,DOUBLE,atof(a.elems.STRING)); }
    push(s,a);
}

/**
 * \brief Função que compara os dois elementos do topo da Stack dependendo do caracter dado.
 * @param s Stack
 * @param c Caracter que corresponde a um dos sinais de comparação lógicos
 */
void compara(STACK *s, char c) {
    DATA a, da, z, b, db;//ia, ib 
    TYPE ta, tb;
    int x;
    a = top(s); // a ori
    ta = a.type;

    trsd(s);      
    da = top(s); // a double
    
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
                x = strcmp(a.elems.STRING,b.elems.STRING) < 0 ? 0: 1;
                make_datas(z,LONG,x); break;
            case '>' : 
                x = strcmp(a.elems.STRING,b.elems.STRING) > 0 ? 0: 1;
                make_datas(z,LONG,x); break;
            default : printf("sitio inesperado, '%c'",c);break;
        }
    } 
    else
    if (tb == STRING && ta == LONG) {//FIXME
        char *aux = malloc(sizeof(char) * strlen(b.elems.STRING) +1);
        int i = 0, c2 = 0;
        switch( c ) {
            case '=' : 
                make_datas(z,CHAR,  b.elems.STRING[a.elems.LONG]); break;
            case '<':
                while ( i < a.elems.LONG ) {
                    aux [i] = b.elems.STRING[i];
                    i++;
                }
                aux[i] = '\0';
                make_datas(z,STRING, aux); break;
            case '>':
                i = a.elems.LONG;
                //printf("%d",i);
                while ( b.elems.STRING[i] ) {
                    aux [c2] = b.elems.STRING[i];
                    i++;
                    c2++;
                }
                aux[c2] = '\0';
                make_datas(z,STRING, aux); break;
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

/**
 * \brief Função que funciona como um "Não" lógico.
 * @param s Stack
 */
void nao (STACK *s) {
    trsd(s);
    DATA a = pop(s);
    make_datas(a,LONG,! a.elems.LONG);
    push(s,a);
}

/**
 * \brief Função que guarda numa variável o valor que se encontra no topo da Stack. 
 * @param s Stack
 * @param c Caracter que corresponde à letra da variavel
 * @param ll[] 
 */
void guardavar (STACK *s, char c, DATA ll[]) {
    DATA a = top(s);
    ll[c-'A'] = a;
}

/**
 * \brief Função que dados os 3 valores dos elementos no topo da Stack devolve o segundo caso o valor lógico do primeiro seja verdadeiro, caso contrário devolve o terceiro.
 * @param s Stack
 */
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

/**
 * \brief Função que inicializa um array de Datas com os respetivos valores por omissão.
 * @param ll Lista de Letras
 */
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
 * \brief Função que devolve o tamanho do elemento no topo da Stack.
 * @param s Stack
 */
void vir(STACK *s) {
    DATA a = pop(s);
    TYPE ta = a.type;
    switch (ta) {
        case ARRAY: make_datas(a,LONG, a.elems.ARRAY->n_elems ); break;
        case STRING:make_datas(a,LONG,strlen(a.elems.STRING)); break;
        default: break;
    }

    push(s,a);
}

/**
 * \brief Função que separa um token do resto da linha, devolvendo os dois.     
 * @param line A linha quer será lida
 * @param rest O resto da linha após ser separada do token   
 */
char *get_token3(char *line, char **rest) { //**rest é um apontador para uma string
    char *delims = " \t\n";
    int i = 0;
    while ( strchr(delims,*line) != NULL && *line != '\0') {
        line ++;
    }
    //if ( strlen(line) == 0 ) {
    //    return NULL;
    //}
    if (*line == '\0') return NULL;
    char *token;
    token = strdup(line);
    while ( strchr(delims,token[i]) == NULL) i++;
    token[i] = '\0';
    *rest = line+i+1; 
    //line = token;
    return token;
}

/** 
 * \brief Função que dado algo delimitado por [], devolve o conteúdo dentro das delimitações.   
 * @param line A linha que será lida
 * @param rest O resto da linha  
 */
char *get_delimited(char *line, char **rest) {//só para arrays
    int c, i=0;
    char *ini = strdup(line+2);
    for (c = 1; c != 0; i++) {
        if ( ini[i]  == '[' ) c++;
        if ( ini[i]  == ']' ) c--;
    }
    *rest = (ini[i] == '\0') ? "" : line+i+2;
    ini[i-1] = '\0';
   // ini[i-2] = '\0';
//    printf("%s",*rest);
    return ini;
}

/** 
 * \brief Função que dado algo delimitado por "", devolve o conteúdo dentro das delimitações.   
 * @param line A linha que será lida
 * @param rest O resto da linha  
 */
char *getAspas(char * token, char **rest) {
    char * ini = token+1;
    for (token++; *token != '"'; token++) {
        if (*token == '\0') *token = ' ';
    }
    if (*token != '\0') *rest = token+2;
    else *rest = token;
    *token = '\0';
    //token = line+1;
    token = ini;
    return token;
}

STACK *parse(char *line, STACK *stack, DATA ll[]) {
    //char *delims = " \t\n";
    char *rest[strlen(line)+1];
    *rest = (char*) malloc (sizeof(char) * strlen(line));
    
    char *token;// = (char*) malloc (sizeof(char) * strlen(line));
    for ( token = get_token3(line, rest); token != NULL; token = get_token3(line,rest)) {
        //while ( strchr(delims,*line) != NULL && *line != '\0') line ++;
        if(*token =='"') {//por numa função getdelimited
            
            char *ini = getAspas(token, rest);
            DATA z;
            {make_datas(z,STRING,ini);}
            push(stack,z);
        }
        else
        if(*token =='[') {
            token = get_delimited(line, rest);
            //printf("token: %s\n",token);
            //printf(" rest: '%s'\n",*rest);
            STACK *s2;
            s2 = create_stack();
            s2 = parse(token,s2,ll);
            //printf(" rest: '%s'\n",*rest);
            DATA k;
            make_datas(k,ARRAY,s2);
            push(stack,k); 
        }
        else {
            char *sobra;
            int val_i = strtol(token, &sobra, 10);// "20"-> 20; "20mesa" -> 20 , sobra = "mesa" 
            int temp = 1;//
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
            else // "20 30 +"
            if (temp) {

                if (*token == '-' && *(token+1) != '\0') {
                    DATA k;
                    {make_datas(k, LONG, strtol(token,&sobra,10))};
                    push(stack,k);
                }
                if (strchr("+-/*^%#&|e",*token))  aritmetica(stack,token); 
                else
                if (strchr("<>=",*token)) compara(stack,*token); 
                else
                if (*token >= 'A' && *token <= 'Z') push(stack,ll[*token-'A']);
                else {
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
                        case ',' : vir(stack); break;
                        default : printf("sitio inesperado fim parse '%c'", *token);break;
                    }
                }
            }
        }
        strcpy(line,*rest);
    }
    return stack;
}
