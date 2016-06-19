//
//  funcoes.c
//  AED-TRABALHO-1
//
//  Created by Andre Victor on 18/06/16.
//  Copyright © 2016 Andre Victor. All rights reserved.
//

#include "funcoes.h"
#include <stdlib.h>



void remover_livro(int cod, FILE *livro, FILE *estante, FILE *prateleira) {
    int num_est, num_prat, pos_ant;
    if ((pos_ant = busca_end_livro(livro, cod, &num_est, &num_prat)) != -1) {
        cabecalho *cab_est;
        Estante *est;
        Prateleira *prat;
        Livro *liv;
        cab_est = le_cabecalho(estante);
        int pos_est = cab_est->pos_cabeca;
        while (!feof(estante) && pos_est != -1) {
            est = le_estante(estante, pos_est);
            pos_est = est->prox;
            if (num_est == est->num) {
                for (int i = 0; i < est->quant_prat; i++) {
                    prat = le_prateleira(prateleira, est->end_prat[i]);
                    if (num_prat == prat->num) {
                        
                        for (int j = 0; j < prat->quant_livro; j++) {
                            liv = le_livro(livro, prat->end_livro[j]);
                            if (cod == liv->cod) {
                                delete_livro(livro, pos_ant);
                                return;
                            }
                            
                        }
                    }
                    
            }

            }
            
            
        }
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
            *est = liv->estante;
            *prat = liv->prateleira;
            return pos_ant;
        }
        pos_ant = pos;
        pos = liv->prox;
    }
    printf("Livro indisponível\n");
    free(cab);
    free(liv);
    return -1;
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