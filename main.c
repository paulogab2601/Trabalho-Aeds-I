#include <stdio.h>
#include <stdlib.h>
#include "headers/pizza.h"
#include "headers/ingredientes.h"

int main()
{
    Pizza pizzas[MAX_PIZZAS];
    Ingrediente ingredientes[MAX_INGREDIENTES];
    int numPizzas = 0, numIngredientes = 0;
    int opcao, subOpcao;

    do
    {
        printf("\n=== Sistema de Gerenciamento Pizzaria Joao Fortao ===\n");
        printf("1. Gerenciar Pizzas\n");
        printf("2. Gerenciar Ingredientes\n");
        printf("3. Vender Pizza\n");
        printf("4. Exportar Pizzas\n");
        printf("5. Importar Pizzas\n");
        printf("6. Exportar Ingredientes\n");
        printf("7. Importar Ingredientes\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        system("CLS");

        switch (opcao)
        {
        case 1: // Gerenciar Pizzas
            do
            {
                printf("\n=== Gerenciar Pizzas ===\n");
                printf("1. Adicionar Pizza\n");
                printf("2. Visualizar Pizzas\n");
                printf("3. Editar Pizza\n");
                printf("4. Remover Pizza\n");
                printf("0. Voltar\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &subOpcao);

                system("CLS");

                switch (subOpcao)
                {
                case 1:
                    system("CLS");

                    adicionarPizza(pizzas, &numPizzas);
                    break;
                    system("CLS");

                case 2:
                    visualizarPizzas(pizzas, numPizzas);
                    break;
                case 3:
                    system("CLS");

                    editarPizza(pizzas, numPizzas);
                    break;
                case 4:
                    system("CLS");

                    removerPizza(pizzas, &numPizzas);
                    break;
                case 0:
                    break;
                default:
                    system("CLS");

                    printf("Opcao invalida!\n");
                }
            } while (subOpcao != 0);
            break;

        case 2: // Gerenciar Ingredientes
            do
            {
                printf("\n=== Gerenciar Ingredientes ===\n");
                printf("1. Adicionar Ingrediente\n");
                printf("2. Visualizar Ingredientes\n");
                printf("3. Editar Ingrediente\n");
                printf("4. Remover Ingrediente\n");
                printf("0. Voltar\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &subOpcao);

                system("CLS");

                switch (subOpcao)
                {
                case 1:
                    system("CLS");

                    adicionarIngrediente(ingredientes, &numIngredientes);
                    break;
                case 2:
                    system("CLS");

                    visualizarIngredientes(ingredientes, numIngredientes);
                    break;
                case 3:
                    system("CLS");

                    editarIngrediente(ingredientes, numIngredientes);
                    break;
                case 4:
                    system("CLS");

                    removerIngrediente(ingredientes, &numIngredientes);
                    break;
                case 0:
                    break;
                default:
                    system("CLS");

                    printf("Opcao invalida!\n");
                }
            } while (subOpcao != 0);
            break;

        case 3: // Vender Pizza
            system("CLS");

            printf("Funcionalidade de venda de pizza ainda nao implementada.\n");
            break;

        case 4: // Exportar Pizzas
            system("CLS");

            exportarPizzas(pizzas, numPizzas);
            break;

        case 5: // Importar Pizzas
            system("CLS");

            importarPizzas(pizzas, &numPizzas);
            break;

        case 6: // Exportar Ingredientes
            system("CLS");

            exportarIngredientes(ingredientes, numIngredientes);
            break;

        case 7: // Importar Ingredientes
            system("CLS");

            importarIngredientes(ingredientes, &numIngredientes);
            break;

        case 0: // Sair
            printf("Saindo do sistema...\n");
            exit(0);
            break;

        default:
            system("CLS");

            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
