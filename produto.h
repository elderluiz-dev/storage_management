#pragma once

typedef struct {
    int id;
    char *nome;
    float preco;
    int quantidade;
} produto_t;

produto_t *cadastra_produto_novo(produto_t produto_novo);

int cadastra_produto(produto_t *lista_produto, int size_lista, produto_t produto_novo);