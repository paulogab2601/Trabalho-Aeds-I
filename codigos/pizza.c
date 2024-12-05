#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../headers/pizza.h"

// Função para adicionar uma pizza
void adicionarPizza(Pizza *pizzas, int *numPizzas)
{
    if (*numPizzas >= MAX_PIZZAS)
    {
        printf("Limite de pizzas atingido.\n");
        system("PAUSE");
        system("CLS");
        return;
    }
    Pizza novaPizza;
    novaPizza.id = *numPizzas + 1; // ID auto-incremental
    printf("Nome da pizza: ");

    getchar(); // Limpa o buffer de entrada
    fgets(novaPizza.nome, 100, stdin);

    // Remove o '\n' do final da string, se existir
    int tamanho = strlen(novaPizza.nome);
    if (tamanho > 0 && novaPizza.nome[tamanho - 1] == '\n')
    {
        novaPizza.nome[tamanho - 1] = '\0';
    }

    do
    {
        printf("Tamanho (P, M, G): ");
        scanf(" %c", &novaPizza.tamanho);

        if ((novaPizza.tamanho != 'P') && (novaPizza.tamanho != 'p') && (novaPizza.tamanho != 'M') && (novaPizza.tamanho != 'm') && (novaPizza.tamanho != 'G') && (novaPizza.tamanho != 'g'))
        {
            printf("Digite uma opcao valida!\n");

            system("PAUSE");
            system("CLS");
        }

    } while ((novaPizza.tamanho != 'P') && (novaPizza.tamanho != 'p') && (novaPizza.tamanho != 'M') && (novaPizza.tamanho != 'm') && (novaPizza.tamanho != 'G') && (novaPizza.tamanho != 'g'));

    printf("Preco: ");
    scanf("%f", &novaPizza.preco);

    // Adiciona ingredientes padrão
    novaPizza.num_ingredientes = 0;
    printf("Quantos ingredientes padrao deseja adicionar? ");
    scanf("%d", &novaPizza.num_ingredientes);

    for (int i = 0; i < novaPizza.num_ingredientes; i++)
    {
        printf("Nome do ingrediente %d: ", i + 1);
        getchar(); // Limpa o buffer de entrada
        fgets(novaPizza.ingredientes[i].nome, 100, stdin);

        // Remove o '\n' do final da string, se existir
        tamanho = strlen(novaPizza.ingredientes[i].nome);
        if (tamanho > 0 && novaPizza.ingredientes[i].nome[tamanho - 1] == '\n')
        {
            novaPizza.ingredientes[i].nome[tamanho - 1] = '\0';
        }

        printf("Preco do ingrediente %d: ", i + 1);
        scanf("%f", &novaPizza.ingredientes[i].preco);
        novaPizza.ingredientes[i].id = i + 1; // ID auto-incremental para ingredientes
    }

    pizzas[*numPizzas] = novaPizza;
    (*numPizzas)++;
    printf("Pizza adicionada com sucesso!\n");

    system("PAUSE");
    system("CLS");
}

// Função para visualizar todas as pizzas
void visualizarPizzas(Pizza *pizzas, int numPizzas)
{
    if (numPizzas == 0)
    {
        printf("Nenhuma pizza cadastrada.\n");

        system("PAUSE");
        system("CLS");

        return;
    }
    for (int i = 0; i < numPizzas; i++)
    {
        printf("ID: %d, Nome: %s, Tamanho: %c, Preco: %.2f\n", pizzas[i].id, pizzas[i].nome, pizzas[i].tamanho, pizzas[i].preco);
        printf("Ingredientes:\n");
        for (int j = 0; j < pizzas[i].num_ingredientes; j++)
        {
            printf("  - %s (%.2f)\n", pizzas[i].ingredientes[j].nome, pizzas[i].ingredientes[j].preco);
        }
        printf("\n");
    }

    system("PAUSE");
    system("CLS");
}

// Função para editar uma pizza
void editarPizza(Pizza *pizzas, int numPizzas)
{
    int id;
    printf("Digite o ID da pizza que deseja editar: ");
    scanf("%d", &id);

    if (id < 1 || id > numPizzas)
    {
        printf("Pizza nao encontrada.\n");

        system("PAUSE");
        system("CLS");

        return;
    }

    Pizza *pizza = &pizzas[id - 1]; // Acesso à pizza
    printf("Novo nome da pizza (atual: %s): ", pizza->nome);

    getchar();
    fgets(pizza->nome, 100, stdin);

    do
    {
        printf("Novo tamanho da pizza (atual: %c): ", pizza->tamanho);
        scanf(" %c", &pizza->tamanho);
        if ((pizza->tamanho != 'P') && (pizza->tamanho != 'p') && (pizza->tamanho != 'M') && (pizza->tamanho != 'm') && (pizza->tamanho != 'G') && (pizza->tamanho != 'g'))
        {
            printf("Digite uma opcao valida!\n");

            system("PAUSE");
            system("CLS");
        }

    } while ((pizza->tamanho != 'P') && (pizza->tamanho != 'p') && (pizza->tamanho != 'M') && (pizza->tamanho != 'm') && (pizza->tamanho != 'G') && (pizza->tamanho != 'g'));

    printf("Novo preco da pizza (atual: %.2f): ", pizza->preco);
    scanf("%f", &pizza->preco);

    printf("Quantos ingredientes padrao deseja adicionar? ");
    scanf("%d", &pizza->num_ingredientes);

    for (int i = 0; i < pizza->num_ingredientes; i++)
    {
        printf("Nome do ingrediente %d: ", i + 1);

        getchar();
        fgets(pizza->ingredientes[i].nome, 100, stdin);
        printf("Preco do ingrediente %d: ", i + 1);
        scanf("%f", &pizza->ingredientes[i].preco);
        pizza->ingredientes[i].id = i + 1; // ID auto-incremental para ingredientes
    }
    printf("Pizza editada com sucesso!\n");

    system("PAUSE");
    system("CLS");
}

// Função para remover uma pizza
void removerPizza(Pizza *pizzas, int *numPizzas)
{
    int id;
    printf("Digite o ID da pizza que deseja remover: ");
    scanf("%d", &id);

    if (id < 1 || id > *numPizzas)
    {
        printf("Pizza nao encontrada.\n");

        system("PAUSE");
        system("CLS");

        return;
    }

    // Remover a pizza, deslocando os elementos
    for (int i = id - 1; i < *numPizzas - 1; i++)
    {
        pizzas[i] = pizzas[i + 1];
    }
    (*numPizzas)--; // Decrementa o número de pizzas
    printf("Pizza removida com sucesso!\n");

    system("PAUSE");
    system("CLS");
}

// Função para exportar pizzas para um arquivo
void exportarPizzas(Pizza *pizzas, int numPizzas)
{
    FILE *file = fopen("pizzas.txt", "w");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para exportacao.\n");
        system("PAUSE");
        system("CLS");

        return;
    }
    for (int i = 0; i < numPizzas; i++)
    {
        fprintf(file, "%d %s %c %.2f %d\n", pizzas[i].id, pizzas[i].nome, pizzas[i].tamanho, pizzas[i].preco, pizzas[i].num_ingredientes);
        for (int j = 0; j < pizzas[i].num_ingredientes; j++)
        {
            fprintf(file, "%s %.2f\n", pizzas[i].ingredientes[j].nome, pizzas[i].ingredientes[j].preco);
        }
    }
    fclose(file);
    printf("Pizzas exportadas com sucesso!\n");

    system("PAUSE");
    system("CLS");
}

// Função para importar pizzas de um arquivo
void importarPizzas(Pizza *pizzas, int *numPizzas)
{
    FILE *file = fopen("pizzas.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para importacao.\n");

        system("PAUSE");
        system("CLS");

        return;
    }
    while (fscanf(file, "%d %s %c %f %d", &pizzas[*numPizzas].id, pizzas[*numPizzas].nome, &pizzas[*numPizzas].tamanho, &pizzas[*numPizzas].preco, &pizzas[*numPizzas].num_ingredientes) != EOF)
    {
        for (int j = 0; j < pizzas[*numPizzas].num_ingredientes; j++)
        {
            fscanf(file, "%s %f", pizzas[*numPizzas].ingredientes[j].nome, &pizzas[*numPizzas].ingredientes[j].preco);
            pizzas[*numPizzas].ingredientes[j].id = j + 1; // ID auto-incremental para ingredientes
        }
        (*numPizzas)++;
        if (*numPizzas >= MAX_PIZZAS)
        {
            printf("Limite de pizzas atingido durante a importacao.\n");
            break;
        }
    }
    fclose(file);
    printf("Pizzas importadas com sucesso!\n");

    system("PAUSE");
    system("CLS");
}