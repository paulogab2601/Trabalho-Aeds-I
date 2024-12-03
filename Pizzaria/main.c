// Incluindo bibliotecas propias:
#include "Headers/ingredientes.h"
#include "Headers/pizza.h"

int main()
{
    int a = 0;
    ingrediente i1 = newIngrediente(&a);

    printf("%d", i1.id_ingrediente);

    return 0;
}
