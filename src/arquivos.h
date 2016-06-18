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

int inserir_livro(FILE* arq,int cod, char autor[],char titulo[], int prateleira, int estante);
void inserir_estante(FILE* arq,int num, int num_prat[], int end_prat[], int n);
int inserir_prateleira(FILE* arq,int num, int cod_livro[], int end_livro[], int n);
void cria_lista_vazia(FILE* arq);
void carregar_arquivos(FILE *info, FILE *estante, FILE *prateleira, FILE *livro);
FILE *abrir_arquivo_leitura(FILE *arq, char *nome);
FILE *abrir_arquivo_escrita(FILE *arq, char *nome);


#endif /* arquivos_h */
