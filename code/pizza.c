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
        return;
    }

    Pizza novaPizza;
    novaPizza.id = *numPizzas + 1; // ID simples baseado na contagem

    printf("Digite o nome da pizza: ");
    scanf(" %[^\n]", novaPizza.nome);

    printf("Digite o preço da pizza: ");
    scanf("%f", &novaPizza.preco);

    // Exibe os ingredientes disponíveis e permite selecioná-los
    printf("Ingredientes disponíveis:\n");
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
            printf("ID de ingrediente inválido.\n");
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
}

// Função para visualizar pizzas
void visualizarPizzas(Pizza *pizzas, int numPizzas)
{
    if (numPizzas == 0)
    {
        printf("Nenhuma pizza cadastrada.\n");
        return;
    }

    printf("Pizzas:\n");
    for (int i = 0; i < numPizzas; i++)
    {
        printf("ID: %d, Nome: %s, Preço: %.2f\n", pizzas[i].id, pizzas[i].nome, pizzas[i].preco);
        printf("Ingredientes:\n");
        for (int j = 0; j < MAX_INGREDIENTES_PIZZA; j++)
        {
            if (pizzas[i].ingredientes[j].id != 0) // Verifica se o ingrediente é válido
            {
                printf("  - %s (%.2f)\n", pizzas[i].ingredientes[j].nome, pizzas[i].ingredientes[j].preco);
            }
        }
    }
}

// Função para editar uma pizza
void editarPizza(Pizza *pizzas, int numPizzas, Ingrediente *ingredientes, int *numIngredientes)
{
    int id;
    printf("Digite o ID da pizza que deseja editar: ");
    scanf("%d", &id);

    if (id < 1 || id > numPizzas)
    {
        printf("ID inválido.\n");
        return;
    }

    Pizza *pizza = &pizzas[id - 1];
    printf("Editar pizza (atual: %s, %.2f):\n", pizza->nome, pizza->preco);
    printf("Novo nome: ");
    scanf(" %[^\n]", pizza->nome);

    printf("Novo preço: ");
    scanf("%f", &pizza->preco);

    // Exibe os ingredientes disponíveis e permite selecioná-los
    printf("Ingredientes disponíveis:\n");
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
            printf("ID de ingrediente inválido.\n");
        }
    }

    // Atualiza o número de ingredientes selecionados
    for (int i = numIngredientesSelecionados; i < MAX_INGREDIENTES_PIZZA; i++)
    {
        pizza->ingredientes[i].id = 0; // Zera os ingredientes não utilizados
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
        printf("ID inválido.\n");
        return;
    }

    for (int i = id - 1; i < *numPizzas - 1; i++)
    {
        pizzas[i] = pizzas[i + 1];
    }
    (*numPizzas)--;
    printf("Pizza removida com sucesso!\n");
}

// Função para exportar pizzas para um arquivo
void exportarPizzas(Pizza *pizzas, int numPizzas, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < numPizzas; i++)
    {
        // Removido o tamanho da pizza da exportação
        fprintf(file, "%d;%s;%.2f;", pizzas[i].id, pizzas[i].nome, pizzas[i].preco);
        for (int j = 0; j < MAX_INGREDIENTES_PIZZA; j++)
        {
            if (pizzas[i].ingredientes[j].id != 0) // Verifica se o ingrediente é válido
            {
                fprintf(file, "%d;%s;%.2f;", pizzas[i].ingredientes[j].id, pizzas[i].ingredientes[j].nome, pizzas[i].ingredientes[j].preco);
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Pizzas exportadas com sucesso para %s!\n", filename);
}

void importarPizzas(Pizza *pizzas, int *numPizzas, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (*numPizzas < MAX_INGREDIENTES_PIZZA && !feof(file))
    {
        Pizza novaPizza;
        char linha[256];

        if (fgets(linha, sizeof(linha), file))
        {
            // Lê os dados da pizza sem o tamanho
            sscanf(linha, "%d;%99[^;];%f", &novaPizza.id, novaPizza.nome, &novaPizza.preco);
            novaPizza.ingredientes[0] = (Ingrediente){0}; // Inicializa o primeiro ingrediente
            int numIngredientesLidos = 0;

            // Lê os ingredientes da linha
            char *token = strtok(linha, ";");
            while (token != NULL && numIngredientesLidos < MAX_INGREDIENTES_PIZZA)
            {
                // Ignora os dados da pizza
                if (numIngredientesLidos == 0)
                {
                    token = strtok(NULL, ";"); // Pula o primeiro token
                    continue;
                }

                // Lê os ingredientes
                Ingrediente novoIngrediente;
                sscanf(token, "%d;%99[^;];%f", &novoIngrediente.id, novoIngrediente.nome, &novoIngrediente.preco);
                novaPizza.ingredientes[numIngredientesLidos - 1] = novoIngrediente; // Armazena o ingrediente
                numIngredientesLidos++;

                token = strtok(NULL, ";");
            }

            // Atualiza o número de ingredientes lidos
            novaPizza.ingredientes[numIngredientesLidos - 1] = (Ingrediente){0}; // Finaliza a lista de ingredientes
            *numPizzas += 1;
            pizzas[*numPizzas - 1] = novaPizza; // Adiciona a nova pizza ao array
        }
    }

    fclose(file);
}