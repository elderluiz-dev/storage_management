#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "interface.h"

int main()
{  
    produto_t *lista_produto;
    int id = 1;
    int qty_lista = 0;
    int cadastro_novo = 0;

    while (1)
    {
        int option = home();
        
        switch(option)
        {
            case 1:
            {
                produto_t produto_novo = {};

                while (getchar() != '\n' && getchar() != EOF); 
                printf("Nome: ");
                fgets(produto_novo.nome, sizeof(produto_novo.nome), stdin);
                produto_novo.nome[strcspn(produto_novo.nome, "\n")] = '\0';

                printf("Preço: ");
                scanf("%f", &produto_novo.preco);
                
                printf("Quantidade: ");
                scanf("%d", &produto_novo.quantidade);

                produto_novo.id = id;

                if(cadastro_novo == 0)
                {
                    lista_produto = cadastra_produto_novo(produto_novo);

                    qty_lista++;
                    cadastro_novo = 1;
                }
                else
                {
                    cadastra_produto(&lista_produto, qty_lista, produto_novo);
                    
                    id++;
                    qty_lista++;
                }

                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                if(lista_produto == NULL)
                {
                    printf("Lista não existente!");
                    break;
                }

                unsigned int id;

                printf("Digite o id: ");
                scanf("%u", &id);

                produto_t lista_buscada = busca_produto_id(lista_produto, id, qty_lista);
                
                if(strcmp(lista_buscada.nome, "NULL_STRUCT") == 0)
                {
                    printf("Produto não encontrado!\n");
                    break;
                }
                else
                {
                    printf("\n=== Lista encontrada ===\n");
                    printf("Id: %u\n", lista_buscada.id);
                    printf("Nome: %s\n", lista_buscada.nome);
                    printf("Preço: %f\n", lista_buscada.preco);           
                    printf("Quantidade: %d\n", lista_buscada.quantidade);
                    
                    break;
                }

                break;
            }
            case 5:
            {
                break;
            }

            case 6:
            {
                break;
            }

            default:
            {
                printf("Opção inválida!\n");
                break;
            }
        }
    }
    
    return 0;
}