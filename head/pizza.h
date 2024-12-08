#ifndef PIZZA_H
#define PIZZA_H

#define MAX_INGREDIENTES_PIZZA 10
#define MAX_NOME 100

#include "../head/ingrediente.h"

// Struct para pizzas
typedef struct
{
    int id;
    char nome[MAX_NOME];
    char tamanho; // P, M, G
    float preco;
    Ingrediente ingredientes[MAX_INGREDIENTES_PIZZA];
} Pizza;

// Funções CRUD para pizzas
void adicionarPizza(Pizza *pizzas, int *numPizzas, Ingrediente *ingredientes, int *numIngredientes);
void visualizarPizzas(Pizza *pizzas, int numPizzas);
void editarPizza(Pizza *pizzas, int numPizzas, Ingrediente *ingredientes, int *numIngredientes);
void removerPizza(Pizza *pizzas, int *numPizzas);
void exportarPizzas(Pizza *pizzas, int numPizzas, const char *filename);
void importarPizzas(Pizza *pizzas, int *numPizzas, const char *filename);

#endif // PIZZA_H