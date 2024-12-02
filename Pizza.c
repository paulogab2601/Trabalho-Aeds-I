#include "Headers/Pizza.h"

pizza newPizza()
{

    pizza pizza_;
    printf("<============ CADASTRO DE NOVO SABOR ============>\n\n");
    printf("Digite o nome da pizza: ");
    fgets(pizza_.pizza_nome, 100, stdin);

    printf("Digite o preço da pizza: ");
    scanf("%f", &pizza_.pizza_preco);

    // Incluir cadastro dos ingredientes

    printf("Pizza cadastrada com sucesso!");

    pizza_.pizza_tam = 'c';
    pizza_.pizza_id = 0;

    return pizza_;
}


void removePizza(pizza* vet_pizza){

    int id_pizza_removida;
    printf("Digite o ID da pizza a ser removida do cardapio: ");
    scanf("%d", &id_pizza_removida);


};