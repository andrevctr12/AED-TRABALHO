//
//  main.c
//  AED-TRABALHO-1
//
//  Created by Andre Victor on 24/05/16.
//  Copyright © 2016 Andre Victor. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void menu() {
    FILE *info;
    FILE *estante;
    FILE *prateleira;
    FILE *livro;
    FILE *usuario;
    
    info = fopen("/Users/andrevictor/Documents/Coding/AED/AED-TRABALHO-1-QT/build/info.txt", "r");
    estante = fopen("/Users/andrevictor/Documents/Coding/AED/AED-TRABALHO-1-QT/build/estante", "w+b");
    prateleira = fopen("/Users/andrevictor/Documents/Coding/AED/AED-TRABALHO-1-QT/build/prateleira", "w+b");
    livro = fopen("/Users/andrevictor/Documents/Coding/AED/AED-TRABALHO-1-QT/build/livro", "w+b");
    /*
    info = fopen("info.txt", "r");
    estante = fopen("estante", "w+b");
    prateleira = fopen("prateleira", "w+b");
    livro = fopen("livro", "w+b");
     */
    carregar_arquivos(info, estante, prateleira, livro);
    int op = -1;
    int cod;
    char *caminho;
    while (op != 10) {
        printf("\n[0]Carregar arquivo de inicialização\n");
        printf("[1]Inserir livro\n");
        printf("[2]Retirar livro\n");
        printf("[3]Busca endereço do livro\n");
        printf("[4]Locar sala\n");
        printf("[5]Emprestar livro\n");
        printf("[6]Liberar sala\n");
        printf("[7]Imprimir mapa de estantes\n");
        printf("[8]Imprimir mapa de salas\n");
        printf("[9]Imprimir fila de espera da sala\n");
        printf("[10]Sair\n");
        printf("> ");
        scanf("%d",&op);
        switch(op)
        {
            case 0:
                printf("Qual o caminho do arquivo texto?\n> ");
                scanf("%s", caminho);
                usuario = fopen(caminho, "w+b");
                carregar_arquivos(usuario, estante, prateleira, livro);
                break;
            case 1:
                inserir_livro(livro, 1, "alguem", "titulo", 10, 10);
                break;
            case 2:
                printf("funcao2");
                break;
            case 3:
                printf("Qual o codigo do livro?\n> ");
                scanf("%d", &cod);
                int prat, est;
                if (busca_end_livro(livro, cod, &est, &prat) != -1) {
                    printf("Estante: %d\n", est);
                    printf("Prateleira: %d\n", prat);
                }
                break;
            case 4:
                printf("funcao4");
                break;
            case 5:
                printf("funcao5");
                break;
            case 6:
                printf("funcao6");
                break;
            case 7:
                imprime_estante(livro, estante, prateleira);
                break;
            case 8:
                printf("funcao8");
                break;
            case 9:
                printf("funcao9");
                break;
            case 10:
                fclose(info);
                fclose(livro);
                fclose(estante);
                fclose(prateleira);
            default:
                printf("Digite outro número\n");
                
        }
        system("clear");
        
    }
}

int main()
{
    menu();
    return 0;
}