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

int busca_end_livro(FILE *livro, int cod, int *est, int *prat);

void imprime_estante(FILE* livro, FILE *estante, FILE *prateleira);




#endif /* funcoes_h */
