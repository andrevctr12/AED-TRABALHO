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

void delete_livro(FILE *arq, int pos_ant);

void delete_livro_prat(FILE *prateleira, int num_prat, int num_est, int cod_livro);

void retirar_livro(int cod, FILE *livro, FILE *prateleira);

int busca_end_livro(FILE *livro, int cod, int *est, int *prat);

void imprime_estante(FILE* livro, FILE *estante, FILE *prateleira);

int locar_sala(FILE* sala, FILE *fila, int ra);

void imprime_mapa_sala(FILE *sala, FILE *pilha);




#endif /* funcoes_h */
