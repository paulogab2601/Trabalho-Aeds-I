// Incluindo bibliotecas propias:
#include "head/ingredientes.h"
#include "head/pizza.h"

int main()
{
    int a = 0;
    ingrediente i1 = newIngrediente(&a);

    printf("%d", i1.id_ingrediente);

    return 0;
}