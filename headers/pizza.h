#ifndef PIZZA_H
#define PIZZA_H

#include "../headers/ingredientes.h"
#define MAX_INGREDIENTES_PIZZA 10
#define MAX_PIZZAS 50

typedef struct {
    int id;
    char nome[50];
    char tamanho; // P, M, G
    float preco;
    Ingrediente ingredientes[MAX_INGREDIENTES_PIZZA];
    int num_ingredientes;
} Pizza;

// Funções CRUD para pizzas
void adicionarPizza(Pizza *pizzas, int *numPizzas);
void visualizarPizzas(Pizza *pizzas, int numPizzas);
void editarPizza(Pizza *pizzas, int numPizzas);
void removerPizza(Pizza *pizzas, int *numPizzas);
void exportarPizzas(Pizza *pizzas, int numPizzas);
void importarPizzas(Pizza *pizzas, int *numPizzas);

#endif