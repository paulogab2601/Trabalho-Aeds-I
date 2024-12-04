#include "header/ingredientes.h"


int main(){
    int op;


    while(1){ // Menu Principal
        clearScreen();

        puts("\t\t\t\e[1m| Seja Bem-Vindo a Freddy's Bear Pizzaria |\e[0m");

        puts("1) Visualizar Cardapio\n2) Gerenciar Pizzas\n3) Gerenciar Ingredientes\n4) Realizar Venda\n0) Encerrar Programa");
        scanf("%d", &op);

        getchar();

        switch(op){

        case 1:     //Visualizar Cardapio

            /*clearScreen();

            puts("\t\t\e[1m| Cardapio |\e[0m\n\n");
            puts("\t\t\t    |   Pequena    |    Media     |    Grande    |\n");

            for(int i=1; i<=max_ID; i++){       // Printa Pizzas
                printf("\n| %-25s |  R$  %-7.2f |  R$  %-7.2f |  R$  %-7.2f |\n", pizza[i].nome, pizza[i].preco, pizza[i].preco+15, pizza[i].preco+25);
                printf(" - ");

                for(int j=0; j<10; j++){    // Printa Ingredientes
                    if(strlen(pizza[i].ingredientes[j].nome) > 0)
                        printf("\e[38;5;245m%s, \e[0m", pizza[i].ingredientes[j].nome);
                }
            }

            getchar();
                
            break;

        case 2: // Menu Pizza
            while(op != 0){

                clearScreen();

                puts("1) Adicionar Pizza\n2) Visualizar Pizzas\n3) Editar Pizza\n4) Remover Pizza\n0) Voltar");
                scanf("%d", &op);

                switch(op){

                case 1:
                    //newPizza();
                    break;

                case 2:
                    //viewPizza();
                    break;

                case 3:
                    //editPizza();
                    break;

                case 4:
                    //delPizza();
                    break;

                case 0:
                    break;

                default:
                    puts("Opcao Invalida.");
                    break;
                }

            }


           /* while(1){

                printf("Adicionar Ingrediente %d/10: ", qtd_ingred+1);
                fgets(pizza[id].ingredientes[qtd_ingred].nome, 20, stdin);

                pizza[id].ingredientes[qtd_ingred].nome[strcspn(pizza[id].ingredientes[qtd_ingred].nome, "\n")] = '\0';     // Remove '\n'

                if(strcmp(pizza[id].ingredientes[qtd_ingred].nome, "x") == 0 || strcmp(pizza[id].ingredientes[qtd_ingred].nome, "X") == 0){
                    strcpy(pizza[id].ingredientes[qtd_ingred].nome, "");
                    break;
                }

                qtd_ingred++;

            }

            printf("\nPizza \"%s\" adicionada com sucesso!", pizza[id].nome);
            puts("\nPressione ENTER para continuar...");
            getchar();*/

            break;

        case 3:     //Menu Ingredientes

            while(op != 0){

                clearScreen();

                puts("1) Adicionar Ingrediente\n2) Visualizar Ingredientes\n3) Editar Ingrediente\n4) Remover Ingrediente\n0) Voltar");
                scanf("%d", &op);

                getchar();

                switch(op){

                case 1:
                    newIngrediente();

                    break;

                case 2:
                    viewIngrediente();

                    break;

                case 3:
                    editIngrediente();

                    break;

                case 4:
                    delIngrediente();

                    break;

                case 0:
                    break;

                default:
                    puts("Opcao Invalida.");
                    break;
                }

            }

            break;

        case 4:     //Realizar Venda

            break;

        case 0:     //Encerrar Programa
            clearScreen();

            puts("\nAte a proxima!");

            return 0;
            break;

        default:
            puts("Opcao Invalida.");
            break;
        }
    }
}
