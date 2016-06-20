//
//  inserir_arquivo.c
//  AED-TRABALHO-1
//
//  Created by Andre Victor on 19/06/16.
//  Copyright © 2016 Andre Victor. All rights reserved.
//

#include "inserir_arquivo.h"
#include <stdlib.h>
#include <string.h>

/**
 *  Insere uma struct livro no arquivo no arquivo na cabeça da lista
 *
 *  @pre               Arquivo precisa estar aberto
 *  @pos               Struct livro inserida no arquivo na cabeça da lista
 *
 *  @param arq      Arquivo a ser modificado
 *  @param cod      código do livro
 *  @param autor    Autor do livro
 *  @param titulo   Título do livro
 *  @param num_prat Número da prateleira que o livro esta inserido
 *  @param num_est  Número da estante que o livro esta inserido
 *
 *  @return retorna a posição do livro no arquivo
 */
int inserir_livro(FILE* arq,int cod, char autor[],char titulo[], int num_prat, int num_est) {
    cabecalho* cab = le_cabecalho(arq);
    Livro liv;
    liv.cod = cod;
    liv.num_est = num_est;
    liv.num_prat = num_prat;
    liv.prox = cab->pos_cabeca;
    liv.status = 1;
    strcpy(liv.autor, autor);
    strcpy(liv.titulo, titulo);
    
    if(cab->pos_livre == -1) {
        escreve_livro(arq,&liv,cab->pos_topo);
        cab->pos_cabeca = cab->pos_topo;
        cab->pos_topo++;
    }
    else {
        Livro* aux = le_livro(arq,cab->pos_livre);
        escreve_livro(arq,&liv,cab->pos_livre);
        cab->pos_cabeca = cab->pos_livre;
        cab->pos_livre = aux->prox;
        free(aux);
    }
    escreve_cabecalho(arq,cab);
    int x = cab->pos_cabeca;
    free(cab);
    return x;
}
/**
 *  Insere uma struct estante no arquivo na cabeça da lista
 *
 *  @pre               Arquivo precisa estar aberto
 *  @pos               Struct estante inserida no arquivo na cabeça da lista
 *
 *  @param arq        Arquivo a ser modificado
 *  @param num        numero da estante
 *  @param num_prat   vetor de números de prateleiras nessa estante
 *  @param end_prat   vetor de endereços de prateleiras nessa estante
 *  @param quant_prat quantidade de prateleiras nessa estante
 *
 *  @return retorna a posição da estante no arquivo
 */
int inserir_estante(FILE* arq,int num, int num_prat[], int end_prat[], int quant_prat) {
    cabecalho* cab = le_cabecalho(arq);
    Estante est;
    est.num = num;
    est.quant_prat = quant_prat;
    est.prox = cab->pos_cabeca;
    for (int i = 0; i < quant_prat; i++) {
        est.num_prat[i] = num_prat[i];
        est.end_prat[i] = end_prat[i];
    }
    if(cab->pos_livre == -1) {
        escreve_estante(arq,&est,cab->pos_topo);
        cab->pos_cabeca = cab->pos_topo;
        cab->pos_topo++;
    }
    else {
        Estante* aux = le_estante(arq,cab->pos_livre);
        escreve_estante(arq,&est,cab->pos_livre);
        cab->pos_cabeca = cab->pos_livre;
        cab->pos_livre = aux->prox;
        free(aux);
    }
    escreve_cabecalho(arq,cab);
    int x = cab->pos_cabeca;
    free(cab);
    return x;
}


/**
 *  Insere uma struct prateleiras no arquivo na cabeça da lista
 *
 *  @pre               Arquivo precisa estar aberto
 *  @pos               Struct prateleira inserida no arquivo na cabeça da lista
 *
 *  @param arq         Arquivo a ser modificado
 *  @param num         numero da prateleira
 *  @param cod_livro   vetor de códigos de livros na prateleira
 *  @param end_livro   vetor de endereços de livros na prateleira
 *  @param quant_livro quantidade de livros na prateleira
 *  @param num_est     num da estante que a prateleira está
 *
 *  @return retorna a posição da prateleira no arquivo
 */
int inserir_prateleira(FILE* arq,int num, int cod_livro[], int end_livro[], int quant_livro, int num_est) {
    cabecalho* cab = le_cabecalho(arq);
    Prateleira prat;
    prat.num = num;
    prat.quant_livro = quant_livro;
    prat.prox = cab->pos_cabeca;
    prat.num_est = num_est;
    for (int i = 0; i < quant_livro; i++) {
        prat.cod_livro[i] = cod_livro[i];
        prat.end_livro[i] = end_livro[i];
    }
    
    if(cab->pos_livre == -1) {
        escreve_prateleira(arq,&prat,cab->pos_topo);
        cab->pos_cabeca = cab->pos_topo;
        cab->pos_topo++;
    }
    else {
        Prateleira* aux = le_prateleira(arq,cab->pos_livre);
        escreve_prateleira(arq,&prat,cab->pos_livre);
        cab->pos_cabeca = cab->pos_livre;
        cab->pos_livre = aux->prox;
        free(aux);
    }
    escreve_cabecalho(arq,cab);
    int x = cab->pos_cabeca;
    free(cab);
    return x;
}

/**
 *  Insere uma struct sala no arquivo na cabeça da lista
 *
 *  @pre       Arquivo precisa estar aberto
 *  @pos       Struct sala inserida no arquivo na cabeça da lista
 *
 *  @param arq Arquivo a ser modificado
 *  @param num numero da sala
 */
void inserir_sala(FILE* arq, int num) {
    cabecalho* cab = le_cabecalho(arq);
    Sala sala;
    sala.num = num;
    sala.prox = cab->pos_cabeca;
    sala.ra = 0;
    if(cab->pos_livre == -1) {
        escreve_sala(arq,&sala,cab->pos_topo);
        cab->pos_cabeca = cab->pos_topo;
        cab->pos_topo++;
    }
    else {
        Sala* aux = le_sala(arq,cab->pos_livre);
        escreve_sala(arq,&sala,cab->pos_livre);
        cab->pos_cabeca = cab->pos_livre;
        cab->pos_livre = aux->prox;
        free(aux);
    }
    escreve_cabecalho(arq,cab);
    free(cab);
}


/**
 *  Insere uma struct pilha no arquivo na cabeça da pilha
 *
 *  @pre             Arquivo precisa estar aberto
 *  @pos             Struct sala inserida no arquivo na cabeça da pilha
 *
 *  @param arq       Arquivo a ser modificado
 *  @param num       número de identificação da pilha
 *  @param end_livro endereço do livro no arquivo
 */
void push_pilha(FILE* arq, int ra, int pos_livro, int pos_sala) {
    cabecalho* cab = le_cabecalho(arq);
    Pilha_Livro pilha;
    pilha.ra = ra;
    pilha.pos_livro = pos_livro;
    pilha.pos_sala = pos_sala;
    pilha.prox = cab->pos_cabeca;
    
    if(cab->pos_livre == -1) {
        escreve_pilha(arq,&pilha,cab->pos_topo);
        cab->pos_cabeca = cab->pos_topo;
        cab->pos_topo++;
    }
    else {
        Pilha_Livro* aux = le_pilha(arq,cab->pos_livre);
        escreve_pilha(arq,&pilha,cab->pos_livre);
        cab->pos_cabeca = cab->pos_livre;
        cab->pos_livre = aux->prox;
        free(aux);
    }
    escreve_cabecalho(arq,cab);
    free(cab);
}


int pop_pilha(FILE* pilha, FILE *livro) {
    cabecalho *cab = le_cabecalho(pilha);
    Pilha_Livro *pil = le_pilha(pilha,cab->pos_cabeca);
    Livro *liv;
    int pos_livro;
    int aux;
    if (cab->pos_cabeca != -1) {
        pos_livro = pil->pos_livro;
        liv = le_livro(livro, pos_livro);
        liv->status = 1;
        escreve_livro(livro,liv,pos_livro);
        free(liv);
        aux = cab->pos_cabeca;
        cab->pos_cabeca = pil->prox;
        pil->prox = cab->pos_livre;
        cab->pos_livre = aux;
        escreve_pilha(pilha, pil, aux);
        escreve_cabecalho(pilha, cab);
        free(pil);
        return 1;
    }
    free(liv);
    free(pil);
    return 0;
}

/**
 *  Insere uma struct fila no arquivo no final da fila
 *
 *  @pre       Arquivo precisa estar aberto
 *  @pos       Struct fila inserida no arquivo no final da fila
 *
 *  @param arq Arquivo a ser modificado
 *  @param ra  RA do aluno
 */
void enqueue_fila_espera(FILE *arq, int ra){
    cab_fila *cab_fila = le_cab_fila(arq);
    cabecalho* cab = le_cabecalho(arq);
    Fila fila;
    fila.ra = ra;
    fila.prox = cab->pos_cabeca;
    
    if (cab->pos_cabeca == -1) {
        cab_fila->pos_inicial = cab->pos_topo;
    }
    
    if(cab->pos_livre == -1) {
        escreve_fila(arq,&fila,cab->pos_topo);
        cab->pos_cabeca = cab->pos_topo;
        cab_fila->pos_final = cab->pos_topo;
        cab->pos_topo++;
    }
    else {
        Pilha_Livro* aux = le_pilha(arq,cab->pos_livre);
        escreve_fila(arq,&fila,cab->pos_livre);
        cab->pos_cabeca = cab->pos_livre;
        cab_fila->pos_final = cab->pos_livre;
        cab->pos_livre = aux->prox;
        free(aux);
    }
    escreve_cabecalho(arq,cab);
    escreve_cab_fila(arq, cab_fila);
    free(cab);
    free(cab_fila);
}
/**
 *  Retira a struct da fila e coloca na posição livre do arquivo
 *
 *  @pre       Arquivo aberto
 *
 *  @param arq Arquivo a ser modificado
 */
void dequeue_fila_espera(FILE *arq) {
    cab_fila *cab_fila = le_cab_fila(arq);
    cabecalho* cab = le_cabecalho(arq);
    Fila *fila = NULL;
    Fila *fila_ant;
    int pos = cab_fila->pos_final;
    int pos_ant = 0;
    while (pos != cab_fila->pos_inicial) {
        fila = le_fila(arq, pos);
        pos_ant = pos;
        pos = fila->prox;
    }
    fila_ant = le_fila(arq, pos_ant);
    fila_ant->prox = -1;
    cab_fila->pos_inicial = pos_ant;
    fila->prox = cab->pos_livre;
    escreve_fila(arq, fila, pos);
    escreve_fila(arq, fila_ant, pos_ant);
    escreve_cab_fila(arq, cab_fila);
    escreve_cabecalho(arq, cab);
    free(cab);
    free(cab_fila);
    free(fila);
    free(fila_ant);
}

