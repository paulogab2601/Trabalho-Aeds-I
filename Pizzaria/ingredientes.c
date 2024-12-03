// Incluindo bibliotecas propias:
#include "../Headers/ingredientes.h"

ingrediente newIngrediente(int *posicao)
{
    ingrediente ingrediente_;

    printf("Digite o nome do ingrediente: ");
    fgets(ingrediente_.nome_ingrediente, 100, stdin);
    ingrediente_.nome_ingrediente[strcspn(ingrediente_.nome_ingrediente, "\n")] = '\0'; // Remove o '\n' gerado pelo fgets

    printf("Digite o valor do ingrediente: ");
    scanf("%f", &ingrediente_.preco_ingrediente);

    ingrediente_.id_ingrediente = 100 + *posicao; // Id vale a posicao do array do ingrediente + 100

    return ingrediente_;
}
