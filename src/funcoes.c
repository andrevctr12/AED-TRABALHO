//
//  funcoes.c
//  AED-TRABALHO-1
//
//  Created by Andre Victor on 18/06/16.
//  Copyright © 2016 Andre Victor. All rights reserved.
//

#include "funcoes.h"
#include <stdlib.h>

void delete_livro(FILE *arq, int pos_ant) {
    cabecalho* cab = le_cabecalho(arq);
    Livro *liv_ant = le_livro(arq, pos_ant);
    int pos = liv_ant->prox;
    Livro *liv = le_livro(arq, pos);
    if (cab->pos_cabeca == pos) //Remoção na cabeça
        cab->pos_cabeca = liv->prox;
    else
        liv_ant->prox = liv->prox;
    liv->prox = cab->pos_livre;
    cab->pos_livre = pos;
    escreve_cabecalho(arq, cab);
    escreve_livro(arq, liv_ant,pos_ant);
    escreve_livro(arq, liv, pos);
    free(cab);
    free(liv);
    free(liv_ant);
}

void delete_livro_prat(FILE *prateleira, int num_prat, int num_est, int cod_livro) {
    cabecalho *cab_prat = le_cabecalho(prateleira);
    Prateleira *prat = NULL;
    int pos_prat = cab_prat->pos_cabeca;
    while (pos_prat != -1) {
        prat = le_prateleira(prateleira, pos_prat);
        if (num_est == prat->num_est) {
            if (num_prat == prat->num) {
                for (int i = 0; i < prat->quant_livro; i++) {
                    if (prat->cod_livro[i] >= cod_livro) {
                        prat->cod_livro[i - 1] = prat->cod_livro[i];
                    }
                }
            }
        }
        pos_prat = prat->prox;
        
    }
    prat->quant_livro--;
}

void retirar_livro(int cod, FILE *livro, FILE *prateleira) {
    int num_est, num_prat, pos_ant;
    if ((pos_ant = busca_end_livro(livro, cod, &num_est, &num_prat))) {
        delete_livro(livro, pos_ant);
        delete_livro_prat(prateleira, num_prat, num_est, cod);
    }
}

int busca_end_livro(FILE *livro, int cod, int *est, int *prat) {
    cabecalho *cab = le_cabecalho(livro);
    Livro *liv = NULL;
    int pos = cab->pos_cabeca;
    int pos_ant = pos;
    fseek(livro, 0, SEEK_SET);
    while (!feof(livro) && pos != -1) {
        liv = le_livro(livro, pos);
        if (cod == liv->cod) {
            *est = liv->num_est;
            *prat = liv->num_prat;
            return pos_ant;
        }
        pos_ant = pos;
        pos = liv->prox;
    }
    printf("Livro indisponível\n");
    free(cab);
    free(liv);
    return 0;
}

void imprime_estante(FILE* livro, FILE *estante, FILE *prateleira) {
    int pos_est;
    cabecalho cab_est;
    Estante est;
    Prateleira prat;
    Livro liv;
    cab_est = *le_cabecalho(estante);
    pos_est = -1;
    while (!feof(estante) && pos_est != cab_est.pos_cabeca) {
        est = *le_estante(estante, pos_est);
        pos_est = est.ant;
        printf("\nEstante: %d\n",est.num);
        for (int i = 0; i < est.quant_prat; i++) {
            prat = *le_prateleira(prateleira, est.end_prat[i]);
            printf("Prateleira: %d\n",prat.num);
            for (int j = 0; j < prat.quant_livro; j++) {
                liv = *le_livro(livro, prat.end_livro[j]);
                printf("%d, ",liv.cod);
                printf("%s, ",liv.autor);
                printf("%s\n",liv.titulo);
            }
        }
    }
}

/**
 *
 *
 *  @param sala <#sala description#>
 *  @param fila <#fila description#>
 *  @param ra   <#ra description#>
 *
 *  @return retorna o número da sala locada ou 0 se estiver na lista de espera
 */
int locar_sala(FILE* sala, FILE *fila, int ra){
    cabecalho* cab = le_cabecalho(sala);
    Sala *sl;
    int aux;
    if(cab->pos_cabeca == -1) {
        //inserir_fila_espera(fila, ra);
        return 0;
    }
    else {
        sl = le_sala(sala,cab->pos_cabeca);
        int num = sl->num;
        sl->ra = ra;
        aux = cab->pos_cabeca;
        cab->pos_cabeca = sl->prox;
        sl->prox = cab->pos_livre;
        cab->pos_livre = aux;
        escreve_sala(sala,sl,cab->pos_livre);
        escreve_cabecalho(sala, cab);
        return num;
        
    }

}

/**
 *  Imprime o mapa de salas
 * 
 *  @pre         Arquivo aberto
 *
 *  @param sala  Arquivo contendo as salas
 *  @param pilha Arquivo contendo a pilha de livros emprestados
 */
void imprime_mapa_sala(FILE *sala, FILE *pilha) {
    cabecalho cab = *le_cabecalho(sala);
    Sala sl;
    int pos_sala_ocupada = cab.pos_livre;
    int pos_sala_livre = cab.pos_cabeca;
    printf("Salas livres:\n");
    while (pos_sala_livre != -1) {
        sl = *le_sala(sala, pos_sala_livre);
        printf("Sala %d, ", sl.num);
        pos_sala_livre = sl.prox;
    }
    printf("\nSalas ocupadas:\n");
    while (pos_sala_ocupada != -1) {
        sl = *le_sala(sala, pos_sala_ocupada);
        printf("Sala %d:\n", sl.num);
        printf("RA: %d\n", sl.ra);
        pos_sala_ocupada = sl.prox;
        
        //adicionar livros
    }
}



