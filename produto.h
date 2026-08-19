#pragma once

typedef struct {
    int id;
    char *nome;
    float preco;
    int quantidade;
} produto_t;

void listar_produto(produto_t *item, int tam, int base);