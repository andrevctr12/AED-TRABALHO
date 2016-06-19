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

cab_fila* le_cab_fila(FILE * arq) {
    cab_fila * cab = (cab_fila*) malloc(sizeof(cab_fila));
    fseek(arq,sizeof(cabecalho),SEEK_SET);
    fread(cab,sizeof(cab_fila),1,arq);
    return cab;
}

void escreve_cab_fila(FILE* arq, cab_fila* cab){
    fseek(arq,sizeof(cabecalho),SEEK_SET);
    fwrite(cab,sizeof(cab_fila),1,arq);
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

Sala* le_sala(FILE* arq, int pos) {
    Sala* x = malloc(sizeof(Sala));
    fseek(arq,sizeof(cabecalho) + pos*sizeof(Sala),SEEK_SET);
    fread(x,sizeof(Sala),1,arq);
    return x;
}

void escreve_sala(FILE* arq, Sala* x, int pos) {
    fseek(arq,sizeof(cabecalho) + pos*sizeof(Sala),SEEK_SET);
    fwrite(x,sizeof(Sala),1,arq);
}

Fila* le_fila(FILE* arq, int pos) {
    Fila* x = malloc(sizeof(Fila));
    fseek(arq,sizeof(cabecalho) + sizeof(cab_fila) + pos*sizeof(Fila),SEEK_SET);
    fread(x,sizeof(Fila),1,arq);
    return x;
}

void escreve_fila(FILE* arq, Fila* x, int pos) {
    fseek(arq,sizeof(cabecalho) + sizeof(cab_fila) + pos*sizeof(Fila),SEEK_SET);
    fwrite(x,sizeof(Fila),1,arq);
}

Pilha_Livro* le_pilha(FILE* arq, int pos) {
    Pilha_Livro* x = malloc(sizeof(Pilha_Livro));
    fseek(arq,sizeof(cabecalho) + sizeof(cab_fila) + pos*sizeof(Pilha_Livro),SEEK_SET);
    fread(x,sizeof(Pilha_Livro),1,arq);
    return x;
}

void escreve_pilha(FILE* arq, Pilha_Livro* x, int pos) {
    fseek(arq,sizeof(cabecalho) + sizeof(cab_fila) + pos*sizeof(Pilha_Livro),SEEK_SET);
    fwrite(x,sizeof(Pilha_Livro),1,arq);
}