//
//  arquivos.h
//  AED-TRABALHO-1
//
//  Created by Andre Victor on 28/05/16.
//  Copyright © 2016 Andre Victor. All rights reserved.
//

#ifndef arquivos_h
#define arquivos_h

#include <stdio.h>
#include "estruturas.h"
#include "inserir_arquivo.h"

void inicializacao_sala_fila_pilha(FILE *sala, FILE *fila, FILE *pilha1, FILE *pilha2, FILE *pilha3);

void cria_lista_vazia(FILE* arq);

void cria_fila_vazia(FILE *arq);

char* remover_espaco(char *s);

void carregar_arquivos(FILE *info, FILE *estante, FILE *prateleira, FILE *livro);



#endif /* arquivos_h */
