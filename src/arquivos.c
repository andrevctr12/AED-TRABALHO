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


/**
 *  Inicialização do arquivo sala
 *  @pre        Arquivo precisa estar aberto
 *  @param sala Arquivo sala a ser modificado
 *  @param fila Arquivo fila a ser modificado
 */
void inicializacao_sala_fila_pilha(FILE *sala, FILE *fila, FILE *pilha1, FILE *pilha2, FILE *pilha3){
    cria_lista_vazia(sala);
    cria_lista_vazia(pilha1);
    cria_lista_vazia(pilha2);
    cria_lista_vazia(pilha3);
    inserir_sala(sala, 3);
    inserir_sala(sala, 2);
    inserir_sala(sala, 1);
    cria_fila_vazia(fila);
}

/**
 *  Cria uma lista vazia de determinada lista, modificando seu cabeçalho
 *
 *  @pre       Arquivo precisa estar aberto
 *
 *  @param arq Arquivo a ser modificado
 */
void cria_lista_vazia(FILE* arq){
    cabecalho * cab = (cabecalho*) malloc(sizeof(cabecalho));
    cab->pos_cabeca = -1;
    cab->pos_topo = 0;
    cab->pos_livre = -1;
    escreve_cabecalho(arq,cab);
    free(cab);
}

void cria_fila_vazia(FILE *arq) {
    cab_fila *cab_fl = (cab_fila*) malloc(sizeof(cab_fila));
    cria_lista_vazia(arq);
    cab_fl->pos_final = -1;
    cab_fl->pos_inicial = -1;
    escreve_cab_fila(arq, cab_fl);
    free(cab_fl);
}

/**
 *  Remove espaço no inicio da string
 *
 *  @param s string
 *
 *  @return retorna a string sem o espaço no inicio
 */
char* remover_espaco(char *s) {
    char *p = s;
    if (strcmp(p, " ")) {
        s = s + 1;
    }
    return s;
}

/**
 *  Carrega os dados do arquivo informado com determinado tipo de sintaxe
 *
 *  @pre              Arquivos precisam estar abertos
 *  @pos              Dados carregados no arquivo
 *
 *  @param info       Arquivo que contem as informações (leitura)
 *  @param estante    Arquivo da estante
 *  @param prateleira Arquivo da prateleira
 *  @param livro      Arquivo do livro
 */
void carregar_arquivos(FILE *info, FILE *estante, FILE *prateleira, FILE *livro) {
    int quant_livro = 0;
    int quant_prat = 0;
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
        while (!feof(info) && fscanf(info, "P%d\n", &prat.num)) {
            while(!feof(info) && fscanf(info, "%d ", &liv.cod)) {
                fgets(linha, MAX_GET, info);
                token = strtok (linha,s);
                strcpy(liv.titulo, remover_espaco(token));
                token = strtok(NULL, s);
                strcpy(liv.autor, remover_espaco(token));
                token = NULL;
                
                prat.end_livro[quant_livro] = inserir_livro(livro, liv.cod, liv.autor, liv.titulo, prat.num, est.num);
                prat.cod_livro[quant_livro] = liv.cod;
                quant_livro++;
            }
            
            est.end_prat[quant_prat] = inserir_prateleira(prateleira, prat.num, prat.cod_livro, prat.end_livro, quant_livro, est.num);
            est.num_prat[quant_prat] = quant_prat;
            quant_prat++;
            quant_livro = 0;
        }
        inserir_estante(estante, est.num, est.num_prat, est.end_prat, quant_prat);
        quant_prat = 0;
    }
    
    
}









