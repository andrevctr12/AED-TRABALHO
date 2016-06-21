/**
 * Autores: Andre Victor e Khadije El Zein
 */

#ifndef inserir_arquivo_h
#define inserir_arquivo_h

#include <stdio.h>
#include "estruturas.h"


/**
 *  Insere uma struct livro no arquivo na cabeça da lista
 *
 *  pre-condicao:Arquivo precisa estar aberto
 *  pos-condicao:Struct livro inserida no arquivo na cabeça da lista
 *  Retorno:retorna a posição do livro no arquivo
 */
int inserir_livro(FILE* arq,int cod, char autor[],char titulo[], int num_prat, int num_est);

/**
 *  Insere uma struct estante no arquivo na cabeça da lista
 *pre-condicao:Arquivo precisa estar aberto
 *pos-condicao:Struct estante inserida no arquivo na cabeça da lista
 *retorno:retorna a posição da estante no arquivo
 */
int inserir_estante(FILE* arq,int num, int num_prat[], int end_prat[], int quant_prat);

/**
 *  Insere uma struct prateleiras no arquivo na cabeça da lista
 *  pre-condicao:Arquivo precisa estar aberto
 *  pos-condicao: Struct prateleira inserida no arquivo na cabeça da lista
 *  retorno:retorna a posição da prateleira no arquivo
 */
int inserir_prateleira(FILE* arq,int num, int cod_livro[], int end_livro[], int quant_livro, int num_est) ;

/**
 * Funcao que insere uma struct sala no arquivo na cabeça da lista
 * pre-condicao: Arquivo precisa estar aberto
 * pos-condicao: Struct sala inserida no arquivo na cabeça da lista
 */
void inserir_sala(FILE* arq, int num);
/**
 *  Funcao que insere uma struct pilha no arquivo na cabeça da pilha
 *  pre-condicao: Arquivo precisa estar aberto
 *  pos-condicao: Struct sala inserida no arquivo na cabeça da pilha
 */
void push_pilha(FILE* arq, int ra, int pos_livro, int pos_sala);

/**
 *  Funcao que retira a struct da pilha e coloca na posição livre do arquivo
 *  pre-condicao: Arquivo aberto
 *  pos-condicao: pilha eh colocada na posicao livre do arquivo
 *  retorno: retorna 1 se desempilhou ou 0 se não tem mais o que desempilhar
 */
int pop_pilha(FILE* pilha, FILE *livro);
/**
 *  Funcao que insere uma struct fila no arquivo no final da fila
 *  pre-condicao: Arquivo precisa estar aberto
 *  pos-condicao: Struct fila inserida no arquivo no final da fila
 */
void enqueue_fila_espera(FILE *arq, int ra);
/**
 *  Funcao que retira a struct da fila e coloca na posição livre do arquivo
 *  pre-condicao: Arquivo aberto
 *  pos-condicao: fila eh colocada na posicao livre do arquivo
 *  retorno: retorna o RA do aluno na fila de espera
 */
int dequeue_fila_espera(FILE *arq);

#endif /* inserir_arquivo_h */
