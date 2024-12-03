#include "../Headers/pizza.h"

pizza newPizza(int *posicao) // recebe o vetor contendo informação sobre as pizzas já cadastradas, e sua posicao
{

    pizza pizza_;

    for (int i = 0; i < 10; i++)
    {
        pizza_.ingredientes_pizza[i].id_ingrediente = 0;
    }

    printf("Digite o nome da pizza: ");
    fgets(pizza_.nome_pizza, 100, stdin);
    pizza_.nome_pizza[strcspn(pizza_.nome_pizza, "\n")] = '\0'; // Remove o '\n' gerado pelo fgets

    printf("Digite o preco da pizza: ");
    scanf("%f", &pizza_.preco_pizza);

    pizza_.id_pizza = 100 + *posicao; // O ID da nova pizza é a sua posicao no vetor + 100

    pizza_.tamanho_pizza = '0'; // Para nao deixar a posicao vazia, usamos o '0', para identificação em loops e etc

    return pizza_;
}
