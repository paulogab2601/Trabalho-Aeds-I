#include <stdio.h>
#include <string.h>
#include "../headers/ingredientes.h"

// Função para adicionar um ingrediente
void adicionarIngrediente(Ingrediente *ingredientes, int *numIngredientes) {
    if (*numIngredientes >= MAX_INGREDIENTES) {
        printf("Limite de ingredientes atingido.\n");
        return;
    }
    Ingrediente novoIngrediente;
    novoIngrediente.id = *numIngredientes + 1; // ID auto-incremental
    printf("Nome do ingrediente: ");
    scanf("%s", novoIngrediente.nome);
    printf("Preço: ");
    scanf("%f", &novoIngrediente.preco);
    ingredientes[*numIngredientes] = novoIngrediente;
    (*numIngredientes)++;
    printf("Ingrediente adicionado com sucesso!\n");
}

// Função para visualizar todos os ingredientes
void visualizarIngredientes(Ingrediente *ingredientes, int numIngredientes) {
    if (numIngredientes == 0) {
        printf("Nenhum ingrediente cadastrado.\n");
        return;
    }
    for (int i = 0; i < numIngredientes; i++) {
        printf("ID: %d, Nome: %s, Preço: %.2f\n", ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
    }
}

// Função para editar um ingrediente
void editarIngrediente(Ingrediente *ingredientes, int numIngredientes) {
    int id;
    printf("Digite o ID do ingrediente que deseja editar: ");
    scanf("%d", &id);
    
    if (id < 1 || id > numIngredientes) {
        printf("Ingrediente nao encontrado.\n");
        return;
    }

    Ingrediente *ingrediente = &ingredientes[id - 1]; // Acesso ao ingrediente
    printf("Novo nome do ingrediente (atual: %s): ", ingrediente->nome);
    scanf("%s", ingrediente->nome);
    printf("Novo preço do ingrediente (atual: %.2f): ", ingrediente->preco);
    scanf("%f", &ingrediente->preco);
    printf("Ingrediente editado com sucesso!\n");
}

// Função para remover um ingrediente
void removerIngrediente(Ingrediente *ingredientes, int *numIngredientes) {
    int id;
    printf("Digite o ID do ingrediente que deseja remover: ");
    scanf("%d", &id);
    
    if (id < 1 || id > *numIngredientes) {
        printf("Ingrediente nao encontrado.\n");
        return;
    }

    // Remover o ingrediente, deslocando os elementos
    for (int i = id - 1; i < *numIngredientes - 1; i++) {
        ingredientes[i] = ingredientes[i + 1];
    }
    (*numIngredientes)--; // Decrementa o número de ingredientes
    printf("Ingrediente removido com sucesso!\n");
}

// Função para exportar ingredientes para um arquivo
void exportarIngredientes(Ingrediente *ingredientes, int numIngredientes) {
    FILE *file = fopen("ingredientes.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para exportacao.\n");
        return;
    }
    for (int i = 0; i < numIngredientes; i++) {
        fprintf(file, "%d %s %.2f\n", ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
    }
    fclose(file);
    printf("Ingredientes exportados com sucesso!\n");
}

// Função para importar ingredientes de um arquivo
void importarIngredientes(Ingrediente *ingredientes, int *numIngredientes) {
    FILE *file = fopen("ingredientes.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para importacao.\n");
        return;
    }
    while (fscanf(file, "%d %s %f", &ingredientes[*numIngredientes].id, ingredientes[*numIngredientes].nome, &ingredientes[*numIngredientes].preco) != EOF) {
        (*numIngredientes)++;
        if (*numIngredientes >= MAX_INGREDIENTES) {
            printf("Limite de ingredientes atingido durante a importacao.\n");
            break;
        }
    }
    fclose(file);
    printf("Ingredientes importados com sucesso!\n");
}