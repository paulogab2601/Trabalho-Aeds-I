// Funcionalidades e definiçôes de Pizza
#include <stdlib.h>
#include <stdio.h>

struct pizza
{
    int pizza_id;
    char pizza_nome[100];
    char pizza_tam;
    float pizza_preco;
    // Incluir ingredientes
};

// Prototipos das funções:

pizza newPizza();
void removePizza(pizza* vet_pizza);
