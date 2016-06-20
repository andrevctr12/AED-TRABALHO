//
//  inserir_arquivo.h
//  AED-TRABALHO-1
//
//  Created by Andre Victor on 19/06/16.
//  Copyright © 2016 Andre Victor. All rights reserved.
//

#ifndef inserir_arquivo_h
#define inserir_arquivo_h

#include <stdio.h>
#include "estruturas.h"

int inserir_livro(FILE* arq,int cod, char autor[],char titulo[], int num_prat, int num_est);
int inserir_estante(FILE* arq,int num, int num_prat[], int end_prat[], int quant_prat);
int inserir_prateleira(FILE* arq,int num, int cod_livro[], int end_livro[], int quant_livro, int num_est) ;
void inserir_sala(FILE* arq, int num);
void push_pilha(FILE* arq, int ra, int pos_livro, int pos_sala);
int pop_pilha(FILE* pilha, FILE *livro);
void enqueue_fila_espera(FILE *arq, int ra);
void dequeue_fila_espera(FILE *arq);

#endif /* inserir_arquivo_h */
