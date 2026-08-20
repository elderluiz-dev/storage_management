#include <stdio.h>
#include <stdlib.h>
#include "produto.h"
#include "interface.h"

int main()
{  
    produto_t *lista_produto;
    int id = 0;
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

                printf("Nome: ");
                scanf("%s", &produto_novo.nome);

                printf("Preço: ");
                scanf("%f", &produto_novo.preco);
                
                printf("Quantidade: ");
                scanf("%d", &produto_novo.quantidade);

                if(cadastro_novo == 0)
                {
                    lista_produto = cadastra_produto_novo(produto_novo);

                    qty_lista++;
                    cadastro_novo = 1;
                }
                else
                {
                    cadastra_produto(&lista_produto, qty_lista, produto_novo);
                    
                    qty_lista++;
                }

                break;
            }
            case 2:
            {
                break;
            }
        }
    }
    
    return 0;
}