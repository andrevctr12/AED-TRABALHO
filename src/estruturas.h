
/**
 *  @file estruturas.h
 *  
 *  @author André Victor Teixeira Lopes
 *  @author Khadije Eliza El Zein
 */

#ifndef estruturas_h
#define estruturas_h
#define MAX 100
#define MAX_LIVRO 50
#define MAX_PRATELEIRA 10

#include <stdio.h>

typedef struct Cab {
    int pos_cabeca;
    int pos_topo;
    int pos_livre;
}cabecalho;

typedef struct Book {
    int cod;
    int prox;
    char titulo[MAX];
    char autor[MAX];
    int prateleira;
    int estante;
}Livro;

typedef struct Shelf {
    int num;
    int prox;
    int cod_livro[MAX_LIVRO];
    int end_livro[MAX_LIVRO];
}Prateleira;

typedef struct Bookcase {
    int num;
    int prox;
    int num_prat[MAX_PRATELEIRA];
    int end_prat[MAX_PRATELEIRA];
}Estante;


cabecalho* le_cabecalho(FILE * arq);

void escreve_cabecalho(FILE* arq, cabecalho* cab);

Livro* le_livro(FILE* arq, int pos);

void escreve_livro(FILE* arq, Livro* x, int pos);

Prateleira* le_prateleira(FILE* arq, int pos);

void escreve_prateleira(FILE* arq, Prateleira* x, int pos);

Estante* le_estante(FILE* arq, int pos);

void escreve_estante(FILE* arq, Estante* x, int pos);






#endif /* estruturas_h */
