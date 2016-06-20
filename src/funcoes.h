//
//  funcoes.h
//  AED-TRABALHO-1
//
//  Created by Andre Victor on 18/06/16.
//  Copyright © 2016 Andre Victor. All rights reserved.
//

#ifndef funcoes_h
#define funcoes_h

#include <stdio.h>
#include "arquivos.h"
#include "inserir_arquivo.h"

void delete_livro(FILE *arq, int pos_ant, int pos);

void delete_livro_prat(FILE *prateleira, int num_prat, int num_est, int cod_livro);

void retirar_livro(int cod, FILE *livro, FILE *prateleira);

int busca_end_livro(FILE *livro, int cod, int *est, int *prat, int *pos);

int emprestar_livro(FILE *pilha1, FILE *pilha2,FILE *pilha3, FILE *sala, FILE* livro, int cod, int ra);

void verificar_livro(FILE* pilha, FILE* livro,int cod, int ra, int pos_sala);

void imprime_estante(FILE* livro, FILE *estante, FILE *prateleira);

int locar_sala(FILE* sala, FILE *fila, int ra);

void imprime_mapa_sala(FILE *sala, FILE *livro, FILE *pilha1, FILE *pilha2, FILE *pilha3);

void imprime_pilha_livro(FILE *pilha, FILE *livro);

void imprime_fila(FILE *arq);






#endif /* funcoes_h */
