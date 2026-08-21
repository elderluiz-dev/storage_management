#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

int home(){
    int option;

    printf("\n===== Sistema de Estoque =====\n");
    printf("\nDigite a opção desejada: \n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Remover produto\n");
    printf("3 - Listar produtos\n");
    printf("4 - Buscar produtos\n");
    printf("5 - Ordenar produtos\n");
    printf("6 - Calcular valor total do estoque\n");
    printf("7 - Sair\n");

    printf("> ");
    scanf("%d", &option);

    return option;
}

void limpaTerminal()
{
    system("clear");
}
