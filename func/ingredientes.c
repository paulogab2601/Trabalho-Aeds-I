#include "header/ingredientes.h"


//Declaração das Variáveis Globais
int max_ID=0;

Ingrediente ingredientes[50];


//Funções

void clearScreen() {   //Funcao para limpar terminal
    system(Clear);
}

void newIngrediente(){      //Adiciona Ingrediente

    clearScreen();

    max_ID++;

    ingredientes[max_ID].id = max_ID;

    puts("\nDigite o nome do novo ingrediente: ");
    fgets(ingredientes[max_ID].nome, 20, stdin);
    ingredientes[max_ID].nome[strcspn(ingredientes[max_ID].nome, "\n")] = '\0';

    puts("\nDigite o preco do novo ingrediente: ");
    scanf("%f", &ingredientes[max_ID].preco);

    puts("\nIngrediente cadastrado com sucesso!\n");

    system("pause");
}


void viewIngrediente(){     //Visualiza Ingredientes Cadastrados
    
    clearScreen();

    printf("\t\t| Ingredientes Cadastrados |\n\n");

    for(int i=1; i<=max_ID; i++){
        if(ingredientes[i].id != 0)
            printf("[%d] %s - R$ %.2f\n", i, ingredientes[i].nome, ingredientes[i].preco);
    }

    puts("\n");
    system("pause");
}


void editIngrediente(){     //Edita Ingredientes

    erro1:
        clearScreen();

        int aux1, aux2;

        printf("\t\t| Editar Ingredientes |\n\n");

        for (int i = 1; i <= max_ID; i++){
            if (ingredientes[i].id != 0)
                printf("[%d] %s - R$ %.2f\n", i, ingredientes[i].nome, ingredientes[i].preco);
        }

        puts("\nDigite o ID do ingrediente que deseja editar: ");
        scanf("%d", &aux1);

        if(aux1 < 1 || aux1 > max_ID){
            puts("\nID inexistente.");
            Sleep(1500);
            goto erro1;
        }

    erro2:
        clearScreen();
        puts("\n1) Alterar nome\n\n2) Alterar preco\n");
        scanf("%d", &aux2);

        getchar();

        if(aux2 == 1){
            clearScreen();

            puts("\nDigite o novo nome do ingrediente: ");
            fgets(ingredientes[aux1].nome, 20, stdin);

            ingredientes[aux1].nome[strcspn(ingredientes[aux1].nome, "\n")] = '\0';

            puts("\nNome alterado com sucesso!\n");
        }
        else if(aux2 == 2){
            clearScreen();

            puts("Digite o novo preco do ingrediente: \n");
            scanf("%f", &ingredientes[aux1].preco);

            puts("\nPreco alterado com sucesso!\n");
        }
        else{
            puts("\nOpcao invalida");
            Sleep(1500);
            goto erro2;
        }

        system("pause");
}


void delIngrediente(){      //Deleta Ingredientes
    
    erro:
        clearScreen();

        int aux;

        printf("\t\t| Remover Ingredientes |\n\n");

        for(int i=1; i<=max_ID; i++){
            if(ingredientes[i].id != 0)
                printf("[%d] %s - R$ %.2f\n", i, ingredientes[i].nome, ingredientes[i].preco);
        }

        puts("\nDigite o ID do ingrediente que deseja remover: ");
        scanf("%d", &aux);

        if(aux < 1 || aux > max_ID){
            puts("\nID inexistente.");
            Sleep(1500);
            goto erro;
        }

        ingredientes[aux].id = 0;
        ingredientes[aux].nome[0] = '\0';
        ingredientes[aux].preco = 0;

        puts("\nIngrediente removido com sucesso.");
        Sleep(1500);

}

/* Incluindo bibliotecas propias:
#include "../head/ingredientes.h"

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
*/