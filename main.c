#include <stdio.h>
#include <stdlib.h>
#include "head\ingrediente.h"
#include "head\pizza.h"

#define FILENAME_INGREDIENTES "ingredientes.txt"
#define FILENAME_PIZZAS "pizzas.txt"

int main() {
    Ingrediente ingredientes[MAX_INGREDIENTES];
    Pizza pizzas[MAX_INGREDIENTES]; //O número máximo de pizzas é o mesmo que ingredientes
    int numIngredientes = 0;
    int numPizzas = 0;

    // Importar ingredientes e pizzas ao iniciar o programa
    importarIngredientes(ingredientes, &numIngredientes, FILENAME_INGREDIENTES);
    importarPizzas(pizzas, &numPizzas, FILENAME_PIZZAS);

    int opcao;
    do {
        // Exibir menu principal
        printf("Menu Principal:\n");
        printf("1. Gerenciador de Pizzas\n");
        printf("2. Gerenciador de Ingredientes\n");
        printf("3. Vender Pizza\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Gerenciador de Pizzas
                printf("Gerenciador de Pizzas:\n");
                printf("1. Adicionar Pizza\n");
                printf("2. Visualizar Pizzas\n");
                printf("3. Editar Pizza\n");
                printf("4. Remover Pizza\n");
                printf("Escolha uma opção: ");
                int opcaoPizza;
                scanf("%d", &opcaoPizza);
                switch (opcaoPizza) {
                    case 1:
                        adicionarPizza(pizzas, &numPizzas, ingredientes, &numIngredientes);
                        break;
                    case 2:
                        visualizarPizzas(pizzas, numPizzas);
                        break;
                    case 3:
                        editarPizza(pizzas, numPizzas, ingredientes, &numIngredientes);
                        break;
                    case 4:
                        removerPizza(pizzas, &numPizzas);
                        break;
                    default:
                        printf("Opção inválida!\n");
                }
                break;

            case 2:
                // Gerenciador de Ingredientes
                printf("Gerenciador de Ingredientes:\n");
                printf("1. Adicionar Ingrediente\n");
                printf("2. Visualizar Ingredientes\n");
                printf("3. Editar Ingrediente\n");
                printf("4. Remover Ingrediente\n");
                printf("Escolha uma opção: ");
                int opcaoIngrediente;
                scanf("%d", &opcaoIngrediente);
                switch (opcaoIngrediente) {
                    case 1:
                        adicionarIngrediente(ingredientes, &numIngredientes);
                        break;
                    case 2:
                        visualizarIngredientes(ingredientes, numIngredientes);
                        break;
                    case 3:
                        editarIngrediente(ingredientes, numIngredientes);
                        break;
                    case 4:
                        removerIngrediente(ingredientes, &numIngredientes);
                        break;
                    default:
                        printf("Opção inválida!\n");
                }
                break;

            case 3:
                break;

            case 0:
                // Sair do programa
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    // Exportar ingredientes e pizzas ao fechar o programa
    exportarIngredientes(ingredientes, numIngredientes, FILENAME_INGREDIENTES);
    exportarPizzas(pizzas, numPizzas, FILENAME_PIZZAS);

    return 0;
}