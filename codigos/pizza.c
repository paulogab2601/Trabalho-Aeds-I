#include <stdio.h>
#include <string.h>
#include "../headers/pizza.h"

// Função para adicionar uma pizza
void adicionarPizza(Pizza *pizzas, int *numPizzas)
{

    if (*numPizzas >= MAX_PIZZAS)
    {
        printf("Limite de pizzas atingido.\n");
        return;
    }
    Pizza novaPizza;
    novaPizza.id = *numPizzas + 1; // ID auto-incremental
    printf("Nome da pizza: ");

    getchar();
    fgets(novaPizza.nome, 100, stdin);
    printf("Tamanho (P, M, G): ");
    scanf(" %c", &novaPizza.tamanho);
    printf("Preco: ");
    scanf("%f", &novaPizza.preco);

    // Adiciona ingredientes padrão
    novaPizza.num_ingredientes = 0;
    printf("Quantos ingredientes padrao deseja adicionar? ");
    scanf("%d", &novaPizza.num_ingredientes);

    for (int i = 0; i < novaPizza.num_ingredientes; i++)
    {
        printf("Nome do ingrediente %d: ", i + 1);
        getchar();
        fgets(novaPizza.ingredientes[i].nome, 100, stdin);
        printf("Preco do ingrediente %d: ", i + 1);
        scanf("%f", &novaPizza.ingredientes[i].preco);
        novaPizza.ingredientes[i].id = i + 1; // ID auto-incremental para ingredientes
    }

    pizzas[*numPizzas] = novaPizza;
    (*numPizzas)++;
    printf("Pizza adicionada com sucesso!\n");
}

// Função para visualizar todas as pizzas
void visualizarPizzas(Pizza *pizzas, int numPizzas)
{
    if (numPizzas == 0)
    {
        printf("Nenhuma pizza cadastrada.\n");
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
    }
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
        return;
    }

    Pizza *pizza = &pizzas[id - 1]; // Acesso à pizza
    printf("Novo nome da pizza (atual: %s): ", pizza->nome);

    getchar();
    fgets(pizza->nome, 100, stdin);
    printf("Novo tamanho da pizza (atual: %c): ", pizza->tamanho);
    scanf(" %c", &pizza->tamanho);
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
        return;
    }

    // Remover a pizza, deslocando os elementos
    for (int i = id - 1; i < *numPizzas - 1; i++)
    {
        pizzas[i] = pizzas[i + 1];
    }
    (*numPizzas)--; // Decrementa o número de pizzas
    printf("Pizza removida com sucesso!\n");
}

// Função para exportar pizzas para um arquivo
void exportarPizzas(Pizza *pizzas, int numPizzas)
{
    FILE *file = fopen("pizzas.txt", "w");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para exportacao.\n");
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
}

// Função para importar pizzas de um arquivo
void importarPizzas(Pizza *pizzas, int *numPizzas)
{
    FILE *file = fopen("pizzas.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para importacao.\n");
        return;
    }

    while (*numPizzas < MAX_PIZZAS)
    {
        // Leitura dos dados principais da pizza
        if (fscanf(file, "%d %c %f %d",
                   &pizzas[*numPizzas].id,
                   &pizzas[*numPizzas].tamanho,
                   &pizzas[*numPizzas].preco,
                   &pizzas[*numPizzas].num_ingredientes) != 4)
        {
            break; // Sai do loop se a leitura falhar
        }

        // Limpar o buffer e ler o nome da pizza
        fgetc(file); // Consome o '\n' que sobrou
        fgets(pizzas[*numPizzas].nome, 100, file);
        pizzas[*numPizzas].nome[strcspn(pizzas[*numPizzas].nome, "\n")] = '\0'; // Remove '\n'

        // Leitura dos ingredientes
        for (int j = 0; j < pizzas[*numPizzas].num_ingredientes; j++)
        {
            fscanf(file, "%s %f", pizzas[*numPizzas].ingredientes[j].nome,
                   &pizzas[*numPizzas].ingredientes[j].preco);
            pizzas[*numPizzas].ingredientes[j].id = j + 1;
        }

        (*numPizzas)++;
    }

    fclose(file);
    printf("Pizzas importadas com sucesso!\n");
}
