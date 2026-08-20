#pragma once

typedef struct {
    unsigned int id;
    char nome[50];
    float preco;
    int quantidade;
} produto_t;

typedef enum {
    SUCCESS,
    ALLOCATION_ERROR,
} ERROR_TYPE_T;

produto_t *cadastra_produto_novo(produto_t produto_novo);

int cadastra_produto(produto_t **lista_produto, int size_lista, produto_t produto_novo);

produto_t busca_produto_id(produto_t *lista_item, unsigned int search_id, int size_lista);

ERROR_TYPE_T remove_produto(produto_t *v, int id, int tam);

float calc_estoque(produto_t *vet, int tam, int i);

void listar_produto(produto_t *item, int tam, int base);

void ordenacao(produto_t *item, int tam);

void encerra_programa(produto_t **listas, int size_listas);