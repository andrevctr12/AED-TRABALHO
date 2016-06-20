//
//  funcoes.c
//  AED-TRABALHO-1
//
//  Created by Andre Victor on 18/06/16.
//  Copyright © 2016 Andre Victor. All rights reserved.
//

#include "funcoes.h"
#include <stdlib.h>

void inserir_livro_prat() {
    
}

void delete_livro(FILE *arq, int pos_ant, int pos) {
    cabecalho* cab = le_cabecalho(arq);
    Livro *liv_ant = le_livro(arq, pos_ant);
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
    cabecalho cab_prat = *le_cabecalho(prateleira);
    Prateleira *prat = NULL;
    int pos_prat = cab_prat.pos_cabeca;
    int aux = 0;
    while (pos_prat != -1) {
        prat = le_prateleira(prateleira, pos_prat);
        if (num_est == prat->num_est) {
            if (num_prat == prat->num) {
                for (int i = 0; i < prat->quant_livro; i++) {
                    if (prat->cod_livro[i] >= cod_livro) {
                        prat->cod_livro[i] = prat->cod_livro[i + 1];
                        aux = pos_prat;
                        
                    }
                    
                }
                prat->quant_livro--;
                escreve_prateleira(prateleira, prat, aux);
                free(prat);
                return;
            }
        }
        pos_prat = prat->prox;
    }
    free(prat);
}

void retirar_livro(int cod, FILE *livro, FILE *prateleira) {
    int num_est, num_prat, pos_ant, pos;
    if ((pos_ant = busca_end_livro(livro, cod, &num_est, &num_prat, &pos))) {
        delete_livro(livro, pos_ant, pos);
        delete_livro_prat(prateleira, num_prat, num_est, cod);
    }
}

int busca_end_livro(FILE *livro, int cod, int *est, int *prat, int *pos) {
    cabecalho cab = *le_cabecalho(livro);
    Livro liv;
    *pos = cab.pos_cabeca;
    int pos_ant = *pos;
    fseek(livro, 0, SEEK_SET);
    while (!feof(livro) && *pos != -1) {
        liv = *le_livro(livro, *pos);
        
        
        if (cod == liv.cod) {
            if (liv.status) {
                *est = liv.num_est;
                *prat = liv.num_prat;
            }
            return pos_ant;
        }
        pos_ant = *pos;
        *pos = liv.prox;
    }
    printf("Livro indisponível\n");
    return 0;
}


int emprestar_livro(FILE *pilha1, FILE *pilha2,FILE *pilha3, FILE *sala, FILE* livro, int cod, int ra) {
    cabecalho cab_sala = *le_cabecalho(sala);
    Sala sl;
    int pos = cab_sala.pos_cabeca;
    int pos_sala = 0;
    int num_sala = 0;
    while (pos != -1) {
        sl = *le_sala(sala, pos);
        pos = sl.prox;
        if(sl.ra == ra) {
            pos_sala = pos;
            num_sala = sl.num;
        }
        else {
            printf("Esse aluno em nenhuma sala");
            return 0;
        }
    }
    if (num_sala == 1) {
        verificar_livro(pilha1, livro, cod, ra, pos_sala);
    }
    if (num_sala == 2) {
        verificar_livro(pilha2, livro, cod, ra, pos_sala);
    }
    if (num_sala == 3) {
        verificar_livro(pilha3, livro, cod, ra, pos_sala);
    }
    return 1;
}

void verificar_livro(FILE* pilha, FILE* livro,int cod, int ra, int pos_sala){
    Livro *liv;
    int est, prat;
    int pos_livro;
    liv->status = 0;
    if(busca_end_livro(livro, cod, &est, &prat, &pos_livro)) {
        liv = le_livro(livro, pos_livro);
        if(liv->status == -1) {
            printf("livro emprestado");
            free(liv);
            return;
        }
    
        push_pilha(pilha, ra, pos_livro, pos_sala);
        liv->status = -1;
        escreve_livro(livro, liv, pos_livro);

    }else printf("Livro inexistente");
    free(liv);
}

void imprime_estante(FILE* livro, FILE *estante, FILE *prateleira) {
    int pos_est;
    cabecalho cab_est;
    Estante est;
    Prateleira prat;
    Livro liv;
    cab_est = *le_cabecalho(estante);
    pos_est = cab_est.pos_cabeca;
    while (pos_est != -1) {
        est = *le_estante(estante, pos_est);
        pos_est = est.prox;
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
        enqueue_fila_espera(fila, ra);
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
void imprime_mapa_sala(FILE *sala, FILE *livro, FILE *pilha1, FILE *pilha2, FILE *pilha3) {
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
        printf("Livros:\n");
        if (sl.num == 1) {
            imprime_pilha_livro(pilha1, livro);
        }
        if (sl.num == 2) {
            imprime_pilha_livro(pilha2, livro);
        }
        if (sl.num == 3) {
            imprime_pilha_livro(pilha3, livro);
        }
    }
}

void imprime_pilha_livro(FILE *pilha, FILE *livro) {
    cabecalho cab = *le_cabecalho(pilha);
    Pilha_Livro pil;
    Livro liv;
    int pos = cab.pos_cabeca;
    while (pos != -1) {
        pil = *le_pilha(pilha, pos);
        liv = *le_livro(livro, pil.pos_livro);
        printf("%d, ",liv.cod);
        printf("%s, ",liv.autor);
        printf("%s\n",liv.titulo);
        pos = pil.prox;
    }
}


void imprime_fila(FILE *arq) {
    int pos_fila;
    Fila fila;
    cab_fila *cab = le_cab_fila(arq);
    pos_fila = cab->pos_final;
    printf("Fila:\n");
    int n = 0;
    while (pos_fila != -1) {
        fila = *le_fila(arq, pos_fila);
        n++;
        pos_fila = fila.prox;
    }
    pos_fila = cab->pos_final;
    while (pos_fila != -1) {
        fila = *le_fila(arq, pos_fila);
        printf("%do RA: %d\n",n,fila.ra);
        pos_fila = fila.prox;
        n--;
    }
    free(cab);
}


