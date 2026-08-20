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
                printf("\nPreencha as informações abaixo: \n");
                printf("Nome do item: ");
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
                    id++;
                }
                else
                {
                    cadastra_produto(&lista_produto, qty_lista, produto_novo);
                    
                    qty_lista++;
                    id++;
                }

                break;
            }
            case 2:
            {
            int remv_id;
            
            printf("Digite o ID do produto a ser removido: ");
            scanf("%d", &remv_id);
          
          
            if(qty_lista == 1)
            {
                cadastro_novo = 0;
                printf("%d", qty_lista);
                remove_produto(&lista_produto, remv_id, qty_lista);
                qty_lista--;
            }else
            {
                remove_produto(&lista_produto, remv_id, qty_lista);
                qty_lista--;
            }
            break;
            }
            case 3:
            {
                if(qty_lista != 0)
                {
                    listar_produto(lista_produto, qty_lista, 0);
                    break;
                }
                printf("\nNenhum produto foi cadastrado ainda.\n");
                break;
            }
            case 4:
            {
                if(lista_produto == NULL)
                {
                    printf("\nNenhum item foi cadastrado ainda.\n");
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
                if(qty_lista == 0)
                {
                    printf("\nNenhum item foi cadastrado ainda.\n");
                    break;
                }

                printf("\nLista ordenada com sucesso!\n");
                ordenacao(lista_produto, qty_lista);
                break;
            }

            case 6:
            {
                produto_t *lista_free[] = {lista_produto};
                encerra_programa(lista_free, 1);
             
                printf("\nPrograma encerrado pelo usuário.\n");
                return 0;
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
