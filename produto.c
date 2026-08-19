 #include "produto.h"
 #include <stdio.h>

 void listar_produto(produto_t *item, int tam, int base)
 {
   if(base == tam) return;
   printf("id: %d\nproduto: %s\npreco: %.2f\nquantidade: %d\n", item[base].id, item[base].nome, item[base].preco, item[base].quantidade);
   listar_produto(item, tam, base + 1);
 }