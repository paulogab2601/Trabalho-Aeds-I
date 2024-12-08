#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../head/ingrediente.h"
#include "../head/pizza.h"

// Função para adicionar uma pizza
void adicionarPizza(Pizza *pizzas, int *numPizzas, Ingrediente *ingredientes, int *numIngredientes)
{
    if (*numPizzas >= MAX_INGREDIENTES_PIZZA)
    {
        printf("Limite de pizzas atingido.\n");

        system("PAUSE");
        system("CLS");

        return;
    }

    Pizza novaPizza;
    novaPizza.id = *numPizzas + 1; // ID simples baseado na contagem

    printf("Digite o nome da pizza: ");
    scanf(" %[^\n]", novaPizza.nome);

    printf("Digite o preco da pizza: ");
    scanf("%f", &novaPizza.preco);

    // Exibe os ingredientes disponíveis e permite selecioná-los
    printf("Ingredientes disponiveis:\n");
    for (int i = 0; i < *numIngredientes; i++)
    {
        printf("%d - %s (%.2f)\n", i + 1, ingredientes[i].nome, ingredientes[i].preco);
    }

    int numIngredientesSelecionados = 0;
    printf("Selecione os ingredientes (digite 0 para parar):\n");
    int ingredienteId;
    while (numIngredientesSelecionados < MAX_INGREDIENTES_PIZZA && scanf("%d", &ingredienteId) && ingredienteId != 0)
    {
        if (ingredienteId >= 1 && ingredienteId <= *numIngredientes)
        {
            novaPizza.ingredientes[numIngredientesSelecionados] = ingredientes[ingredienteId - 1];
            numIngredientesSelecionados++;
        }
        else
        {
            printf("ID de ingrediente invalido.\n");
        }
    }

    // Atualiza o número de ingredientes selecionados
    for (int i = numIngredientesSelecionados; i < MAX_INGREDIENTES_PIZZA; i++)
    {
        novaPizza.ingredientes[i].id = 0; // Zera os ingredientes não utilizados
    }

    pizzas[*numPizzas] = novaPizza;
    (*numPizzas)++;
    printf("Pizza adicionada com sucesso!\n");

    system("PAUSE");
    system("CLS");
}

// Função para visualizar pizzas
void visualizarPizzas(Pizza *pizzas, int numPizzas)
{
    if (numPizzas == 0)
    {
        printf("Nenhuma pizza cadastrada.\n");
        system("PAUSE");
        system("CLS");
        return;
    }

    printf("Pizzas:\n");
    for (int i = 0; i < numPizzas; i++)
    {
        printf("ID: %d, Nome: %s, Preco: %.2f\n", pizzas[i].id, pizzas[i].nome, pizzas[i].preco);
        printf("Ingredientes:\n");

        // Loop apenas nos ingredientes válidos
        for (int j = 0; j < MAX_INGREDIENTES_PIZZA; j++)
        {
            if (pizzas[i].ingredientes[j].id > 0) // Ingredientes com ID > 0 são válidos
            {
                printf("  - %s (R$ %.2f)\n", pizzas[i].ingredientes[j].nome, pizzas[i].ingredientes[j].preco);
            }
        }
        printf("\n");
    }

    system("PAUSE");
    system("CLS");
}

// Função para editar uma pizza
void editarPizza(Pizza *pizzas, int numPizzas, Ingrediente *ingredientes, int *numIngredientes)
{
    int id;
    printf("Digite o ID da pizza que deseja editar: ");
    scanf("%d", &id);

    if (id < 1 || id > numPizzas)
    {
        printf("ID invalido.\n");

        system("PAUSE");
        system("CLS");

        return;
    }

    Pizza *pizza = &pizzas[id - 1];
    printf("Editar pizza (atual: %s, %.2f):\n", pizza->nome, pizza->preco);
    printf("Novo nome: ");
    scanf(" %[^\n]", pizza->nome);

    printf("Novo preco: ");
    scanf("%f", &pizza->preco);

    // Exibe os ingredientes disponíveis e permite selecioná-los
    printf("Ingredientes disponiveis:\n");
    for (int i = 0; i < *numIngredientes; i++)
    {
        printf("%d - %s (%.2f)\n", i + 1, ingredientes[i].nome, ingredientes[i].preco);
    }

    int numIngredientesSelecionados = 0;
    printf("Selecione os ingredientes (digite 0 para parar):\n");
    int ingredienteId;
    while (numIngredientesSelecionados < MAX_INGREDIENTES_PIZZA && scanf("%d", &ingredienteId) && ingredienteId != 0)
    {
        if (ingredienteId >= 1 && ingredienteId <= *numIngredientes)
        {
            pizza->ingredientes[numIngredientesSelecionados] = ingredientes[ingredienteId - 1];
            numIngredientesSelecionados++;
        }
        else
        {
            printf("ID de ingrediente invalido.\n");
        }
    }

    // Atualiza o número de ingredientes selecionados
    for (int i = numIngredientesSelecionados; i < MAX_INGREDIENTES_PIZZA; i++)
    {
        pizza->ingredientes[i].id = 0; // Zera os ingredientes não utilizados
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
        printf("ID invalido.\n");

        system("PAUSE");
        system("CLS");
        return;
    }

    for (int i = id - 1; i < *numPizzas - 1; i++)
    {
        pizzas[i] = pizzas[i + 1];
    }
    (*numPizzas)--;
    printf("Pizza removida com sucesso!\n");

    system("PAUSE");
    system("CLS");
}

// Função para exportar pizzas para um arquivo
void exportarPizzas(Pizza *pizzas, int numPizzas, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        system("PAUSE");
        system("CLS");
        return;
    }

    for (int i = 0; i < numPizzas; i++)
    {
        // Exportar informações da pizza
        fprintf(file, "%d;%s;%.2f;", pizzas[i].id, pizzas[i].nome, pizzas[i].preco);

        // Exportar os ingredientes da pizza
        for (int j = 0; j < MAX_INGREDIENTES_PIZZA; j++)
        {
            if (pizzas[i].ingredientes[j].id != 0) // Verifica se o ingrediente é válido
            {
                fprintf(file, "%d;%s;%.2f;",
                        pizzas[i].ingredientes[j].id,
                        pizzas[i].ingredientes[j].nome,
                        pizzas[i].ingredientes[j].preco);
            }
        }

        // Finalizar a linha para esta pizza
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Pizzas exportadas com sucesso para %s!\n", filename);

    system("PAUSE");
    system("CLS");
}

void importarPizzas(Pizza *pizzas, int *numPizzas, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        system("PAUSE");
        system("CLS");
        return;
    }

    char linha[512];
    while (*numPizzas < 50 && fgets(linha, sizeof(linha), file)) // Corrige a lógica de leitura
    {
        Pizza novaPizza;
        novaPizza.id = 0;
        novaPizza.preco = 0.0f;
        memset(novaPizza.ingredientes, 0, sizeof(novaPizza.ingredientes)); // Zera os ingredientes

        // Lê os dados da pizza (ID, nome, preço)
        char *token = strtok(linha, ";");
        if (token != NULL)
            novaPizza.id = atoi(token);

        token = strtok(NULL, ";");
        if (token != NULL)
            strncpy(novaPizza.nome, token, MAX_NOME - 1);

        token = strtok(NULL, ";");
        if (token != NULL)
            novaPizza.preco = atof(token);

        // Lê os ingredientes
        int numIngredientesLidos = 0;
        while ((token = strtok(NULL, ";")) != NULL && numIngredientesLidos < MAX_INGREDIENTES_PIZZA)
        {
            Ingrediente novoIngrediente;
            novoIngrediente.id = atoi(token);

            token = strtok(NULL, ";");
            if (token != NULL)
                strncpy(novoIngrediente.nome, token, MAX_NOME - 1);

            token = strtok(NULL, ";");
            if (token != NULL)
                novoIngrediente.preco = atof(token);

            novaPizza.ingredientes[numIngredientesLidos++] = novoIngrediente;
        }

        pizzas[*numPizzas] = novaPizza; // Adiciona a pizza ao array
        (*numPizzas)++;
    }

    fclose(file);
    printf("Pizzas importadas com sucesso!\n\n");
    system("PAUSE");
    system("CLS");
}
