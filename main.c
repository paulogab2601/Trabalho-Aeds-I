// Incluindo bibliotecas propias:
#include "head/ingredientes.h"
#include "head/pizza.h"
#include "head/menus.h"

int main()
{
    int select = 1; // Seletor do 1° menu

    int pos_Pizza = 0, pos_Ingrediente = 0; // Posição dos vetores

    printf("<------- Sistema Pizzaria Joao Fortao ------->");

    while (select != 0)
    {
        printf("Qual operacao deseja realizar?");
        printf("1- Editar Cardapio\n2- Editar Estoque\n3-Realizar venda\n0-Sair\n\n");
        scanf("%d", &select);

        switch (select)
        {
        case 1:
            EditorCardapio(&pos_Pizza);
            break;
        case 0:
            printf("Encerrando...");
            exit(0);
            break;

        default:
            printf("Selecione uma opcao valida!");
            select = 1;
            break;
        }
    }

    return 0;
}