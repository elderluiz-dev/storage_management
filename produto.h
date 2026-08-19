#pragma once

typedef struct {
    int id;
    char *nome;
    float preco;
    int quantidade;
} produto_t;

produto_t *cadastra_produto_novo(produto_t produto_novo);

int cadastra_produto(produto_t **lista_produto, int size_lista, produto_t produto_novo);

produto_t busca_produto_id(produto_t *lista_item, int search_id, int size_lista);

void remove_produto(produto_t v[], int id, int tam);

float calc_estoque(produto_t vet[], int tam, int i);

void encerra_programa(produto_t **listas, int size_listas);
