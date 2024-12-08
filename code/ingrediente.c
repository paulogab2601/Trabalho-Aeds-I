#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../head/ingrediente.h"

// Função para adicionar um ingrediente
void adicionarIngrediente(Ingrediente *ingredientes, int *numIngredientes)
{
    if (*numIngredientes >= MAX_INGREDIENTES)
    {
        printf("Limite de ingredientes atingido.\n");

        system("PAUSE");
        system("CLS");

        return;
    }

    Ingrediente novoIngrediente;
    novoIngrediente.id = *numIngredientes + 1; // ID simples baseado na contagem

    printf("Digite o nome do ingrediente: ");
    scanf(" %[^\n]", novoIngrediente.nome);
    printf("Digite o preco do ingrediente: ");
    scanf("%f", &novoIngrediente.preco);

    ingredientes[*numIngredientes] = novoIngrediente;
    (*numIngredientes)++;
    printf("Ingrediente adicionado com sucesso!\n");

    system("PAUSE");
    system("CLS");
}

// Funçao para visualizar ingredietes
void visualizarIngredientes(Ingrediente *ingredientes, int numIngredientes)
{
    if (numIngredientes == 0)
    {
        printf("Nenhum ingrediente cadastrado.\n");

        system("PAUSE");
        system("CLS");

        return;
    }

    printf("Ingredientes:\n");
    for (int i = 0; i < numIngredientes; i++)
    {
        printf("ID: %d, Nome: %s, Preco: %.2f\n", ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
    }
    printf("\n");

    system("PAUSE");
    system("CLS");
}

// Funcaoo para editar um ingrediente
void editarIngrediente(Ingrediente *ingredientes, int numIngredientes)
{
    int id;
    printf("Digite o ID do ingrediente que deseja editar: ");
    scanf("%d", &id);

    if (id < 1 || id > numIngredientes)
    {
        printf("ID invalido.\n");

        system("PAUSE");
        system("CLS");

        return;
    }

    Ingrediente *ingrediente = &ingredientes[id - 1];
    printf("Editar ingrediente (atual: %s, %.2f):\n", ingrediente->nome, ingrediente->preco);
    printf("Novo nome: ");
    scanf(" %[^\n]", ingrediente->nome);
    printf("Novo preco: ");
    scanf("%f", &ingrediente->preco);
    printf("Ingrediente editado com sucesso!\n");
}

// Função para remover um ingrediente
void removerIngrediente(Ingrediente *ingredientes, int *numIngredientes)
{
    int id;
    printf("Digite o ID do ingrediente que deseja remover: ");
    scanf("%d", &id);

    if (id < 1 || id > *numIngredientes)
    {
        printf("ID invalido.\n");
        return;
    }

    for (int i = id - 1; i < *numIngredientes - 1; i++)
    {
        ingredientes[i] = ingredientes[i + 1];
    }
    (*numIngredientes)--;
    printf("Ingrediente removido com sucesso!\n");

    system("PAUSE");
    system("CLS");
}

// Função para exportar ingredientes pro arquivo
void exportarIngredientes(Ingrediente *ingredientes, int numIngredientes, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");

        system("PAUSE");
        system("CLS");

        return;
    }

    for (int i = 0; i < numIngredientes; i++)
    {
        fprintf(file, "%d;%s;%.2f\n", ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
    }

    fclose(file);
    printf("Ingredientes exportados com sucesso para %s!\n", filename);
}

// Função para importar ingredientes do arquivo
void importarIngredientes(Ingrediente *ingredientes, int *numIngredientes, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (*numIngredientes < MAX_INGREDIENTES && !feof(file))
    {
        Ingrediente novoIngrediente;
        char linha[256];

        if (fgets(linha, sizeof(linha), file))
        {
            sscanf(linha, "%d;%99[^;];%f", &novoIngrediente.id, novoIngrediente.nome, &novoIngrediente.preco);
            ingredientes[*numIngredientes] = novoIngrediente;
            (*numIngredientes)++;
        }
    }

    fclose(file);
    printf("Ingredientes importados com sucesso!\n\n");
}