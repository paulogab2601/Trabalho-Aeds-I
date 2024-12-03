#ifndef INGREDIENTES_H
#define INGREDIENTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ingredientes
{
    int id_ingrediente;
    char nome_ingrediente[101];
    float preco_ingrediente;
} ingrediente;

// Prototipos das funções:
ingrediente newIngrediente(int *);

#endif // INGREDIENTES_H
