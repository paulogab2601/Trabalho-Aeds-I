#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#define MAX_INGREDIENTES 50

typedef struct {
    int id;
    char nome[100];
    float preco;
} Ingrediente;

// Funções CRUD para ingredientes
void adicionarIngrediente(Ingrediente *ingredientes, int *numIngredientes);
void visualizarIngredientes(Ingrediente *ingredientes, int numIngredientes);
void editarIngrediente(Ingrediente *ingredientes, int numIngredientes);
void removerIngrediente(Ingrediente *ingredientes, int *numIngredientes);
void exportarIngredientes(Ingrediente *ingredientes, int numIngredientes);
void importarIngredientes(Ingrediente *ingredientes, int *numIngredientes);

#endif