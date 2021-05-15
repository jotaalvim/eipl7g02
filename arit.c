#define _GNU_SOURCE


#include "arit.h"
#include "parser.h"
#include "stack.h"


/**
 * \brief Função que realiza uma determinada operação aritmética (determinada pelo caracter dado) aos dois elementos do topo da Stack.
 * @param s Stack
 * @param c Caracter que vai determinar a operação aritmética a realizar
 */
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
    char   *x3, *saf, *sbf;
    int i;
    if (tb == ARRAY  || ta == ARRAY) {
        if (tb == ARRAY && ta == ARRAY) {
            for(i = 0; i < a.elems.ARRAY->n_elems; i++){
                push(b.elems.ARRAY, a.elems.ARRAY->stack[i]);
            }
            free(a.elems.ARRAY);
            push(s, b);
        }
        else {

        }
    }
    if (tb == STRING || ta == STRING ){
        switch(*c) {
            case 'e':
                switch (*(c+1)) {
                    case '<':
                        saf = a.elems.STRING;
                        sbf = b.elems.STRING;
                        x3 = strcmp(saf, sbf) > 0 ? sbf : saf;
                        make_datas(z,STRING,x3); break;
                    case '>':
                        saf = a.elems.STRING;
                        sbf = b.elems.STRING;
                        x3 = strcmp(saf, sbf) < 0 ? sbf : saf;
                        make_datas(z,STRING,x3); break;
                    default : printf("sitio inesperado, '%c'",*c);break;
                } break;
            case '+':

                // "ola" 'b'
                if (tb == CHAR) {
                    char *f;
                    int t = asprintf(&f ,"%c%s", b.elems.CHAR, a.elems.STRING);
                    t++;
                    make_datas(z,STRING,f);
                }
                else
                if (ta == CHAR) {
                    char *f;
                    int t = asprintf(&f ,"%s%c", b.elems.STRING, a.elems.CHAR);
                    t++;
                    make_datas(z,STRING,f);
                }
                else {
                    char *f;
                    int t = asprintf(&f ,"%s%s", b.elems.STRING, a.elems.STRING);
                    t++;
                    make_datas(z,STRING,f);
                } break;
            case '*':
                if (tb == LONG) {
                    char *f = malloc (sizeof(char)* strlen(a.elems.STRING) * b.elems.LONG +1);
                    f[0] = '\0';
                    for ( int i = 0; b.elems.LONG > i ; i++) {
                       strcat( f, a.elems.STRING);
                    }
                    //f [strlen(a.elems.STRING) * b.elems.LONG] = '\0';
                    //printf("%s",f);
                    make_datas(z,STRING,f);
                }
                if (ta == LONG) {
                    char *f = malloc (sizeof(char)* strlen(b.elems.STRING) * a.elems.LONG +1);
                    for ( int i = 0; a.elems.LONG > i ; i++) {
                       strcat(f, b.elems.STRING);
                    }
                    //f [strlen(b.elems.STRING) * a.elems.LONG] = '\0';
                    //printf("%s",f);
                    make_datas(z,STRING,f);
                } break;
                break;
        }
    }
    else
    if (tb == DOUBLE || ta == DOUBLE ){
        switch(*c) {
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

