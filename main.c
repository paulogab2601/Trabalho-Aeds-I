#include <stdio.h>
#include <stdlib.h>
#include "head\ingrediente.h"
#include "head\pizza.h"

#define FILENAME_INGREDIENTES "ingredientes.txt"
#define FILENAME_PIZZAS "pizzas.txt"

int main()
{
    Ingrediente ingredientes[MAX_INGREDIENTES];
    Pizza pizzas[MAX_INGREDIENTES]; // O número máximo de pizzas é o mesmo que ingredientes
    int numIngredientes = 0;
    int numPizzas = 0;

    int idSelecionado;

    // Importar ingredientes e pizzas ao iniciar o programa
    importarIngredientes(ingredientes, &numIngredientes, FILENAME_INGREDIENTES);
    importarPizzas(pizzas, &numPizzas, FILENAME_PIZZAS);

    int opcao;
    do
    {
        // Exibir menu principal
        printf("Menu Principal:\n");
        printf("1. Gerenciador de Pizzas\n");
        printf("2. Gerenciador de Ingredientes\n");
        printf("3. Vender Pizza\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        system("CLS");

        switch (opcao)
        {
        case 1:
            // Gerenciador de Pizzas
            printf("Gerenciador de Pizzas:\n");
            printf("1. Adicionar Pizza\n");
            printf("2. Visualizar Pizzas\n");
            printf("3. Editar Pizza\n");
            printf("4. Remover Pizza\n");
            printf("Escolha uma opcao: ");
            int opcaoPizza;
            scanf("%d", &opcaoPizza);

            system("CLS");

            switch (opcaoPizza)
            {
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
                printf("Opcao invalida!\n");
            }
            break;

        case 2:
            // Gerenciador de Ingredientes
            printf("Gerenciador de Ingredientes:\n");
            printf("1. Adicionar Ingrediente\n");
            printf("2. Visualizar Ingredientes\n");
            printf("3. Editar Ingrediente\n");
            printf("4. Remover Ingrediente\n");
            printf("Escolha uma opcao: ");
            int opcaoIngrediente;
            scanf("%d", &opcaoIngrediente);

            system("CLS");

            switch (opcaoIngrediente)
            {
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
                printf("Opcao invalida!\n");
            }
            break;

        case 3:

            if (numPizzas == 0)
            {
                printf("Nenhuma pizza cadastrada para venda.\n");
                system("PAUSE");
                system("CLS");
                break;
            }

            printf("Pizzas disponiveis:\n");
            for (int i = 0; i < numPizzas; i++)
            {
                printf("ID: %d, Nome: %s, Preco: R$ %.2f\n", pizzas[i].id, pizzas[i].nome, pizzas[i].preco);
            }

            printf("Digite o ID da pizza que deseja vender: ");
            scanf("%d", &idSelecionado);

            Pizza *pizzaVendida = NULL;
            for (int i = 0; i < numPizzas; i++)
            {
                if (pizzas[i].id == idSelecionado)
                {
                    pizzaVendida = &pizzas[i];
                    break;
                }
            }

            if (pizzaVendida == NULL)
            {
                printf("Pizza com ID %d nao encontrada.\n", idSelecionado);
                system("PAUSE");
                system("CLS");
                break;
            }

            // Exibe os detalhes da pizza selecionada
            printf("Venda confirmada:\n");
            printf("Pizza: %s\n", pizzaVendida->nome);
            printf("Preco base: R$ %.2f\n", pizzaVendida->preco);
            printf("Ingredientes:\n");
            for (int i = 0; i < MAX_INGREDIENTES_PIZZA; i++)
            {
                if (pizzaVendida->ingredientes[i].id != 0) // Verifica se o ingrediente é válido
                {
                    printf("  - %s (R$ %.2f)\n", pizzaVendida->ingredientes[i].nome, pizzaVendida->ingredientes[i].preco);
                }
            }

            // Pergunta se o usuário quer adicionar ingredientes extras
            printf("\nDeseja adicionar ingredientes extras? (1 - Sim / 0 - Não): ");
            int adicionarExtras;
            scanf("%d", &adicionarExtras);

            float precoFinal = pizzaVendida->preco;

            if (adicionarExtras)
            {
                int ingredienteExtraId;
                char continuar = 's';

                while (continuar == 's')
                {
                    printf("\nIngredientes disponiveis:\n");
                    for (int i = 0; i < numIngredientes; i++)
                    {
                        printf("ID: %d, Nome: %s, Preco: R$ %.2f\n", ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
                    }

                    printf("Digite o ID do ingrediente que deseja adicionar: ");
                    scanf("%d", &ingredienteExtraId);

                    Ingrediente *ingredienteExtra = NULL;
                    for (int i = 0; i < numIngredientes; i++)
                    {
                        if (ingredientes[i].id == ingredienteExtraId)
                        {
                            ingredienteExtra = &ingredientes[i];
                            break;
                        }
                    }

                    if (ingredienteExtra == NULL)
                    {
                        printf("Ingrediente com ID %d nao encontrado.\n", ingredienteExtraId);
                    }
                    else
                    {
                        precoFinal += ingredienteExtra->preco;
                        printf("Ingrediente %s adicionado! Novo preco: R$ %.2f\n", ingredienteExtra->nome, precoFinal);
                    }

                    printf("Deseja adicionar outro ingrediente? (s - Sim / n - Não): ");
                    scanf(" %c", &continuar);
                }
            }

            printf("\nResumo da venda:\n");
            printf("Pizza: %s\n", pizzaVendida->nome);
            printf("Preco final: R$ %.2f\n", precoFinal);
            printf("\nVenda realizada com sucesso!\n");

            system("PAUSE");
            system("CLS");

            break;

        case 0:
            // Sair do programa
            printf("Saindo do programa...\n");
            break;

        default:
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    // Exportar ingredientes e pizzas ao fechar o programa

    printf("\n");
    exportarIngredientes(ingredientes, numIngredientes, FILENAME_INGREDIENTES);
    printf("\n");
    exportarPizzas(pizzas, numPizzas, FILENAME_PIZZAS);

    return 0;
}