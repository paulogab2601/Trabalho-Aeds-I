#ifndef PIZZA_H
#define PIZZA_H

#include "../head/ingredientes.h"
typedef struct pizza
{
    int id_pizza;
    char nome_pizza[101];
    char tamanho_pizza;
    float preco_pizza;

    ingrediente ingredientes_pizza[10]; // definido em ingredientes.h

} pizza;

// Prototipos das funções:

pizza newPizza(int *);

#endif // PIZZA_H
