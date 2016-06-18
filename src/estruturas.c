//
//  estruturas.c
//  AED-TRABALHO-1
//
//  Created by Andre Victor on 18/06/16.
//  Copyright © 2016 Andre Victor. All rights reserved.
//

#include "estruturas.h"
#include <stdlib.h>


cabecalho* le_cabecalho(FILE * arq) {
    cabecalho * cab = (cabecalho*) malloc(sizeof(cabecalho));
    fseek(arq,0,SEEK_SET);
    fread(cab,sizeof(cabecalho),1,arq);
    return cab;
}

void escreve_cabecalho(FILE* arq, cabecalho* cab){
    fseek(arq,0,SEEK_SET);
    fwrite(cab,sizeof(cabecalho),1,arq);
}

Livro* le_livro(FILE* arq, int pos) {
    Livro* x = malloc(sizeof(Livro));
    fseek(arq,sizeof(cabecalho) + pos*sizeof(Livro),SEEK_SET);
    fread(x,sizeof(Livro),1,arq);
    return x;
}

void escreve_livro(FILE* arq, Livro* x, int pos) {
    fseek(arq,sizeof(cabecalho) + pos*sizeof(Livro),SEEK_SET);
    fwrite(x,sizeof(Livro),1,arq);
}

Prateleira* le_prateleira(FILE* arq, int pos) {
    Prateleira* x = malloc(sizeof(Prateleira));
    fseek(arq,sizeof(cabecalho) + pos*sizeof(Prateleira),SEEK_SET);
    fread(x,sizeof(Prateleira),1,arq);
    return x;
}

void escreve_prateleira(FILE* arq, Prateleira* x, int pos) {
    fseek(arq,sizeof(cabecalho) + pos*sizeof(Prateleira),SEEK_SET);
    fwrite(x,sizeof(Prateleira),1,arq);
}

Estante* le_estante(FILE* arq, int pos) {
    Estante* x = malloc(sizeof(Estante));
    fseek(arq,sizeof(cabecalho) + pos*sizeof(Estante),SEEK_SET);
    fread(x,sizeof(Estante),1,arq);
    return x;
}

void escreve_estante(FILE* arq, Estante* x, int pos) {
    fseek(arq,sizeof(cabecalho) + pos*sizeof(Estante),SEEK_SET);
    fwrite(x,sizeof(Estante),1,arq);
}