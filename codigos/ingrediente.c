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

// Função para exportar ingredientes
void exportarIngredientes(Ingrediente *ingredientes, int numIngredientes)
{
    FILE *file = fopen("ingredientes.txt", "w");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo para exportação");
        return;
    }

    for (int i = 0; i < numIngredientes; i++)
    {
        // Escreve cada ingrediente em uma linha separada, com dados separados por ponto e vírgula
        fprintf(file, "%d;%s;%.2f\n",
                ingredientes[i].id,
                ingredientes[i].nome,
                ingredientes[i].preco);
    }

    fclose(file);
    printf("Ingredientes exportados com sucesso!\n");
}

// Função para importar ingredientes
void importarIngredientes(Ingrediente *ingredientes, int *numIngredientes)
{
    FILE *file = fopen("ingredientes.txt", "r");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo para importação");
        return;
    }

    char linha[256]; 
    while (fgets(linha, sizeof(linha), file) && *numIngredientes < MAX_INGREDIENTES)
    {
        // Divide a linha usando strtok para pegar os dados separados por ponto e vírgula
        char *token = strtok(linha, ";");

        // Lê o ID do ingrediente
        ingredientes[*numIngredientes].id = atoi(token);

        // Lê o nome do ingrediente
        token = strtok(NULL, ";");
        strcpy(ingredientes[*numIngredientes].nome, token);

        // Lê o preço do ingrediente
        token = strtok(NULL, ";");
        ingredientes[*numIngredientes].preco = atof(token);

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
}