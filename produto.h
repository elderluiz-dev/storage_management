  #pragma once

typedef struct {
    int id;
    char *nome;
    float preco;
    int quantidade;
} produto_t;  

int remove_produto(produto_t v[], int id, int tam);
