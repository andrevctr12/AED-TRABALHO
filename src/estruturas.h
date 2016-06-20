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
/**
 * Estrutura para cabecalho
 */
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
/**
 * Estrutura para livro
 */
typedef struct Book {
    int cod;
    int status;
    int prox;
    char titulo[MAX];
    char autor[MAX];
    int num_prat;
    int num_est;
}Livro;
/**
 * Estrutura para prateleira
 */
typedef struct Shelf {
    int num;
    int prox;
    int cod_livro[MAX_LIVRO];
    int end_livro[MAX_LIVRO];
    int quant_livro;
    int num_est;
}Prateleira;
/**
 * Estrutura para estante
 */
typedef struct Bookcase {
    int num;
    int prox;
    int num_prat[MAX_PRATELEIRA];
    int end_prat[MAX_PRATELEIRA];
    int quant_prat;
}Estante;
/**
 * Estrutura para sala de estudos
 */
typedef struct Room{
    int num;
    int prox;
    int ra;
}Sala;
/**
 * Estrutura para fila
 */
typedef struct Queue{
    int prox;
    int ra;
}Fila;
/**
 * Estrutura para pilha de livros emprestados
 */
typedef struct Stack{
    int prox;
    int pos_livro;
    int ra;
    int pos_sala;
}Pilha_Livro;

/**
 * Funcao que le o cabecalho do arquivo
 * pre-condicao: arquivo valido
 * pos-condicao: retorna cabecalho do arquivo
 */
cabecalho* le_cabecalho(FILE * arq);

/**
 * Funcao que escreve o cabecalho do arquivo
 * pre-condicao: arquivo valido,ponteiro de cabecalho nao nulo
 * pos-condicao: nenhum
 */
void escreve_cabecalho(FILE* arq, cabecalho* cab);

/**
 * Funcao que le o cabecalho estilo struct fila de um arquivo
 * pre-condicao: arquivo valido
 * pos-condicao: retorna cabecalho do arquivo
 */
cab_fila* le_cab_fila(FILE * arq);
/**
 * Funcao que escreve o cabecalho estilo struct fila de um arquivo
 * pre-condicao: arquivo valido, ponteiro nao nulo de cabecalho
 * pos-condicao: nenhuma
 */
void escreve_cab_fila(FILE* arq, cab_fila* cab);
/**
 * Funcao que le o no de livros de um arquivo
 * pre-condicao: arquivo valido, posicao valida
 * pos-condicao: retorna o no de livros
 */
Livro* le_livro(FILE* arq, int pos);
/**
 * Funcao que escreve o no de livros em um arquivo
 * pre-condicao: arquivo valido, ponteiro de livro nao nulo, posicao valida
 * pos-condicao: nenhum
 */
void escreve_livro(FILE* arq, Livro* x, int pos);
/**
 * Funcao que le o no de prateleiras de um arquivo
 * pre-condicao: arquivo valido, posicao valida
 * pos-condicao: retorna o no de prateleiras
 */
Prateleira* le_prateleira(FILE* arq, int pos);
/**
 * Funcao que escreve o no de prateleiras em um arquivo
 * pre-condicao: arquivo valido, ponteiro de prateleiras nao nulo, posicao valida
 * pos-condicao: nenhum
 */
void escreve_prateleira(FILE* arq, Prateleira* x, int pos);
/**
 * Funcao que le o no de estantes de um arquivo
 * pre-condicao: arquivo valido, posicao valida
 * pos-condicao: retorna o no de estantes
 */
Estante* le_estante(FILE* arq, int pos);
/**
 * Funcao que escreve o no de estantes em um arquivo
 * pre-condicao: arquivo valido, ponteiro de estante nao nulo, posicao valida
 * pos-condicao: nenhum
 */
void escreve_estante(FILE* arq, Estante* x, int pos);
/**
 * Funcao que le o no de salas de estudos de um arquivo
 * pre-condicao: arquivo valido, posicao valida
 * pos-condicao: retorna o no de sala de estudos
 */
Sala* le_sala(FILE* arq, int pos);
/**
 * Funcao que escreve o no de sala de estudos em um arquivo
 * pre-condicao: arquivo valido, ponteiro de sala de estudos nao nulo, posicao valida
 * pos-condicao: nenhum
 */
void escreve_sala(FILE* arq, Sala* x, int pos);
/**
 * Funcao que le o no de fila de espera de um arquivo
 * pre-condicao: arquivo valido, posicao valida
 * pos-condicao: retorna o no de fila de espera
 */
Fila* le_fila(FILE* arq, int pos);
/**
 * Funcao que escreve o no de fila de espera em um arquivo
 * pre-condicao: arquivo valido, ponteiro de fila de espera nao nulo, posicao valida
 * pos-condicao: nenhum
 */
void escreve_fila(FILE* arq, Fila* x, int pos);
/**
 * Funcao que le a pilha de livros emprestados de um arquivo
 * pre-condicao: arquivo valido, posicao valida
 * pos-condicao: retorna os livros emprestados
 */
Pilha_Livro* le_pilha(FILE* arq, int pos);
/**
 * Funcao que escreve a pilha de livros emprestados em um arquivo
 * pre-condicao: arquivo valido, ponteiro da pilha de livros nao nulo, posicao valida
 * pos-condicao: nenhum
 */
void escreve_pilha(FILE* arq, Pilha_Livro* x, int pos);





#endif /* estruturas_h */
