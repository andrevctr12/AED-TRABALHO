
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

/**
 *  Estrutura auxiliar para a fila
 */
typedef struct Cab_Fila {
    int pos_inicial;
    int pos_final;
}cab_fila;

typedef struct Book {
    int cod;
    int prox;
    char titulo[MAX];
    char autor[MAX];
    int num_prat;
    int num_est;
}Livro;

typedef struct Shelf {
    int num;
    int prox;
    int cod_livro[MAX_LIVRO];
    int end_livro[MAX_LIVRO];
    int quant_livro;
    int num_est;
}Prateleira;

typedef struct Bookcase {
    int num;
    int prox;
    int ant;
    int num_prat[MAX_PRATELEIRA];
    int end_prat[MAX_PRATELEIRA];
    int quant_prat;
}Estante;

typedef struct Room{
    int num;
    int prox;
    int ra;
}Sala;

typedef struct Queue{
    int prox;
    int ra;
}Fila;

typedef struct Stack{
    int prox;
    int end_livro;
    int ra;
}Pilha_Livro;


cabecalho* le_cabecalho(FILE * arq);

void escreve_cabecalho(FILE* arq, cabecalho* cab);

cab_fila* le_cab_fila(FILE * arq);

void escreve_cab_fila(FILE* arq, cab_fila* cab);

Livro* le_livro(FILE* arq, int pos);

void escreve_livro(FILE* arq, Livro* x, int pos);

Prateleira* le_prateleira(FILE* arq, int pos);

void escreve_prateleira(FILE* arq, Prateleira* x, int pos);

Estante* le_estante(FILE* arq, int pos);

void escreve_estante(FILE* arq, Estante* x, int pos);

Sala* le_sala(FILE* arq, int pos);

void escreve_sala(FILE* arq, Sala* x, int pos);

Fila* le_fila(FILE* arq, int pos);

void escreve_fila(FILE* arq, Fila* x, int pos);

Pilha_Livro* le_pilha(FILE* arq, int pos);

void escreve_pilha(FILE* arq, Pilha_Livro* x, int pos);





#endif /* estruturas_h */
