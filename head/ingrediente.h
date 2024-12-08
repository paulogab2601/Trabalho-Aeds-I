#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#define MAX_INGREDIENTES 50
#define MAX_NOME 100

// Estrutura para ingredientes
typedef struct
{
    int id;
    char nome[MAX_NOME];
    float preco;
} Ingrediente;

// Funções CRUD para ingredientes
void adicionarIngrediente(Ingrediente *ingredientes, int *numIngredientes);
void visualizarIngredientes(Ingrediente *ingredientes, int numIngredientes);
void editarIngrediente(Ingrediente *ingredientes, int numIngredientes);
void removerIngrediente(Ingrediente *ingredientes, int *numIngredientes);
void exportarIngredientes(Ingrediente *ingredientes, int numIngredientes, const char *filename);
void importarIngredientes(Ingrediente *ingredientes, int *numIngredientes, const char *filename);

#endif // INGREDIENTE_H