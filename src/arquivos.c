//
//  arquivos.c
//  AED-TRABALHO-1
//
//  Created by Andre Victor on 28/05/16.
//  Copyright © 2016 Andre Victor. All rights reserved.
//


#include "arquivos.h"
#include <stdlib.h>
#include <string.h>
#define MAX_GET 2*MAX+3

int inserir_livro(FILE* arq,int cod, char autor[],char titulo[], int prateleira, int estante) {
    cabecalho* cab = le_cabecalho(arq);
    Livro liv;
    
    liv.cod = cod;
    liv.estante = estante;
    liv.prateleira = prateleira;
    liv.prox = cab->pos_cabeca;
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

int inserir_estante(FILE* arq,int num, int num_prat[], int end_prat[], int n) {
    cabecalho* cab = le_cabecalho(arq);
    Estante est;
    est.num = num;
    est.prox = cab->pos_cabeca;
    for (int i = 0; i < n; i++) { //inserir ordenado depois!!!
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

int inserir_prateleira(FILE* arq,int num, int cod_livro[], int end_livro[], int n) {
    cabecalho* cab = le_cabecalho(arq);
    Prateleira prat;
    prat.num = num;
    prat.prox = cab->pos_cabeca;
    for (int i = 0; i < n; i++) { //inserir ordenado depois!!!
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

void cria_lista_vazia(FILE* arq){
    cabecalho * cab = (cabecalho*) malloc(sizeof(cabecalho));
    cab->pos_cabeca = -1;
    cab->pos_topo = 0;
    cab->pos_livre = -1;
    escreve_cabecalho(arq,cab);
    free(cab);
}

void carregar_arquivos(FILE *info, FILE *estante, FILE *prateleira, FILE *livro) {
    int n_livro = 0;
    int n_prateleira = 0;
    Prateleira prat;
    Estante est;
    Livro liv;
    char linha[MAX_GET];
    char *token;
    char s[3] = ",\n";
    cria_lista_vazia(estante);
    cria_lista_vazia(prateleira);
    cria_lista_vazia(livro);
    fseek(info, 0, SEEK_SET);
    while (!feof(info) && fscanf(info, "E%d\n", &est.num)) {
        printf("estante add\n");
        while (!feof(info) && fscanf(info, "P%d\n", &prat.num)) {
            while(!feof(info) && fscanf(info, "%d", &liv.cod)) {
                fgets(linha, MAX_GET, info);
                token = strtok (linha,s);
                strcpy(liv.titulo, token);
                token = strtok(NULL, s);
                strcpy(liv.autor, token);
                token = NULL;
                
                prat.end_livro[n_livro] = inserir_livro(livro, liv.cod, liv.autor, liv.titulo, prat.num, est.num);
                prat.cod_livro[n_livro] = liv.cod;
                n_livro++;
            }
            
            est.end_prat[n_prateleira] = inserir_prateleira(prateleira, prat.num, prat.cod_livro, prat.end_livro, n_livro);
            est.num_prat[n_prateleira] = n_prateleira;
            n_prateleira++;
            n_livro = 0;
        }
        inserir_estante(estante, est.num, est.num_prat, est.end_prat, n_prateleira);
        n_prateleira = 0;
    }
    
}

FILE *abrir_arquivo_leitura(FILE *arq, char *nome) {
    if ((arq = fopen(nome, "r")) == NULL) {
        printf("Não foi possível abrir o arquivo\n");
        exit(0);
    }
    return arq;
}
FILE *abrir_arquivo_escrita(FILE *arq, char *nome) {
    if ((arq = fopen(nome, "w+b")) == NULL) {
        printf("Não foi possível abrir o arquivo\n");
        exit(0);
    }
    return arq;
}









