#include "../head/menus.h"
#include "../head/pizza.h"
#include "../head/ingredientes.h"

void EditorCardapio(int *posicao_pizza)
{
    int select = 1;

    while (select != 0)
    {
        printf("1- Cadastrar novo sabor de pizza\n");
        printf("2- Editar pizza\n");
        printf("3- Excluir sabor de pizza\n");
        printf("0- Voltar\n\n");

        printf("Digite: ");
        scanf("%d", &select);

        switch (select)
        {
        case 1:
            newPizza(posicao_pizza);
            break;

        case 2:
            break;
        case 3:
            break;

        default:
            break;
        }
    }

    return;
}