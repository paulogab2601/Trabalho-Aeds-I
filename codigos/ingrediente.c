#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../headers/ingredientes.h"

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
    novoIngrediente.id = *numIngredientes + 1; // ID incremental
    printf("Nome do ingrediente: ");

    getchar();
    fgets(novoIngrediente.nome, 100, stdin);

    int tamanho = strlen(novoIngrediente.nome); // Só removendo o \n, mais pra formatação mesmo
    if (tamanho > 0 && novoIngrediente.nome[tamanho - 1] == '\n')
    {
        novoIngrediente.nome[tamanho - 1] = '\0';
    }

    printf("Preco: ");
    scanf("%f", &novoIngrediente.preco);
    ingredientes[*numIngredientes] = novoIngrediente;
    (*numIngredientes)++;
    printf("Ingrediente adicionado com sucesso!\n");

    system("PAUSE");
    system("CLS");
}

// Função para visualizar todos os ingredientes
void visualizarIngredientes(Ingrediente *ingredientes, int numIngredientes)
{
    if (numIngredientes == 0)
    {
        printf("Nenhum ingrediente cadastrado.\n");

        system("PAUSE");
        system("CLS");

        return;
    }
    for (int i = 0; i < numIngredientes; i++)
    {
        printf("ID: %d, Nome: %s, Preco: %.2f\n", ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
    }
}

// Função para editar um ingrediente
void editarIngrediente(Ingrediente *ingredientes, int numIngredientes)
{
    int id;
    printf("Digite o ID do ingrediente que deseja editar: ");
    scanf("%d", &id);

    if (id < 1 || id > numIngredientes)
    {
        printf("Ingrediente nao encontrado.\n");

        system("PAUSE");
        system("CLS");

        return;
    }

    Ingrediente *ingrediente = &ingredientes[id - 1]; // Acesso ao ingrediente
    printf("Novo nome do ingrediente (atual: %s): ", ingrediente->nome);

    getchar();
    fgets(ingrediente->nome, 100, stdin);

    int tamanho = strlen(ingrediente->nome); // Só removendo o \n, mais pra formatação mesmo
    if (tamanho > 0 && ingrediente->nome[tamanho - 1] == '\n')
    {
        ingrediente->nome[tamanho - 1] = '\0';
    }

    printf("Novo preco do ingrediente (atual: %.2f): ", ingrediente->preco);
    scanf("%f", &ingrediente->preco);
    printf("Ingrediente editado com sucesso!\n");

    system("PAUSE");
    system("CLS");
}

// Função para remover um ingrediente
void removerIngrediente(Ingrediente *ingredientes, int *numIngredientes)
{
    int id;
    printf("Digite o ID do ingrediente que deseja remover: ");
    scanf("%d", &id);

    if (id < 1 || id > *numIngredientes)
    {
        printf("Ingrediente nao encontrado.\n");
        return;
    }

    // Remover o ingrediente, deslocando os elementos
    for (int i = id - 1; i < *numIngredientes - 1; i++)
    {
        ingredientes[i] = ingredientes[i + 1];
    }
    (*numIngredientes)--; // Decrementa o número de ingredientes
    printf("Ingrediente removido com sucesso!\n");

    system("PAUSE");
    system("CLS");
}

// Função para exportar ingredientes para um arquivo
void exportarIngredientes(Ingrediente *ingredientes, int numIngredientes)
{
    FILE *file = fopen("ingredientes.txt", "w");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para exportacao.\n");
        return;
    }
    for (int i = 0; i < numIngredientes; i++)
    {
        fprintf(file, "%d %s %.2f\n", ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
    }
    fclose(file);
    printf("Ingredientes exportados com sucesso!\n");

    system("PAUSE");
    system("CLS");
}

// Função para importar ingredientes de um arquivo
void importarIngredientes(Ingrediente *ingredientes, int *numIngredientes)
{
    FILE *file = fopen("ingredientes.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para importacao.\n");
        return;
    }

    while (*numIngredientes < MAX_INGREDIENTES)
    {
        // Lê o ID e o preço do ingrediente
        if (fscanf(file, "%d %f", &ingredientes[*numIngredientes].id, &ingredientes[*numIngredientes].preco) != 2)
        {
            break; // Sai do loop se a leitura falhar
        }

        // Limpa o buffer e lê o nome do ingrediente
        fgetc(file); // Consome o '\n' que sobrou
        fgets(ingredientes[*numIngredientes].nome, 100, file);
        ingredientes[*numIngredientes].nome[strcspn(ingredientes[*numIngredientes].nome, "\n")] = '\0'; // Remove '\n'

        (*numIngredientes)++;
    }

    fclose(file);

    if (*numIngredientes == MAX_INGREDIENTES)
    {
        printf("Limite de ingredientes atingido.\n");
    }
    else
    {
        printf("Ingredientes importados com sucesso!\n");
    }

    system("PAUSE");
    system("CLS");
}
